#include "Log.hpp"
#include "Epoll.hpp"
#include "Sock.hpp"
#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <functional>
#include <unistd.h>


class EpollServer
{
private:
    using func_t = std::function<void(std::string)>;
    const static int default_port = 8080;
    const static int g_num = 100;
public:
    EpollServer(func_t HandlerRequest, const uint16_t &port = default_port, const int num = g_num)
    : _port(port)
    , _revs_num(num)
    , _HandlerRequest(HandlerRequest)
    {
        // 1.创建_listensock
        _listensock = Sock::Socket();
        Sock::Bind(_listensock, _port);
        Sock::Listen(_listensock);

        // 2.申请对应空间
        _revs = new struct epoll_event[_revs_num];

        // 3.创建epoll模型
        _epfd = Epoll::CreateEpoll();
        LogMessage(NORMAL, "Init success, _listensock: %d, _epfd: %d", _listensock, _epfd);

        // 4.将_listensock先添加到epoll中，让epoll托管此fd
        if(!Epoll::CtlEpoll(_epfd, EPOLL_CTL_ADD, _listensock, EPOLLIN))
        {
            exit(6);
        }
        LogMessage(NORMAL, "add _listensock to epoll success");
    }

    ~EpollServer()
    {
        if(_listensock >= 0)
        {
            close(_listensock);
        }

        if(_epfd)
        {
            close(_epfd);
        }

        if(_revs)
        {
            delete[] _revs;
        }
    }

    void Start()
    {
        int timeout = -1;
        while (true)
        {
            LoopOnce(timeout);
        }
    }

private:
    void LoopOnce(int timeout)
    {
        int n = Epoll::WaitEpoll(_epfd, _revs, _revs_num, timeout);
        switch(n)
        {
        case 0:
            LogMessage(NORMAL, "time out...");
            break;
        case -1:
            LogMessage(WARNING, "epoll wait error: %s", strerror(errno));
            break;
        default:
            HandlerEvents(n);
            break;
        }
    }

    void HandlerEvents(int n)
    {
        for (int i = 0; i < n; i++)
        {
            uint32_t revents = _revs[i].events;
            int sock = _revs[i].data.fd;

            if(revents & EPOLLIN)
            {
                if(sock == _listensock)
                {
                    Accepter();
                }
                else
                {
                    Recver(sock);
                }
            }

            if(revents & EPOLLOUT)
            {
                // TODO
            }
        }
    } // end of HandlerEvent

    void Accepter()
    {
        std::string clientip;
        uint16_t clientport;
        int sock = Sock::Accept(_listensock, &clientip, &clientport);
        if(sock < 0)
        {
            LogMessage(WARNING, "accept error");
            return;
        }

        if(!Epoll::CtlEpoll(_epfd, EPOLL_CTL_ADD, sock, EPOLLIN))
        {
            LogMessage(WARNING, "add sock to epoll error");
            return;
        }
        LogMessage(NORMAL, "add new sock: %d to epoll success", sock);
    }

    void Recver(int sock)
    {
        char buffer[1024];
        ssize_t n = recv(sock, buffer, sizeof(buffer) - 1, 0); // 1.读取数据
        if(n > 0)
        {
            // 假设这里读到了一个完整报文，实际要定制协议保证
            buffer[n - 1] = 0;
            _HandlerRequest(buffer); // 2.处理数据
        }
        else if(n == 0)
        {
            // 1.先在epoll中去掉对sock的关心
            bool res = Epoll::CtlEpoll(_epfd, EPOLL_CTL_DEL, sock, 0);
            assert(res);
            (void)res;

            // 2.再close fd
            close(sock);
            LogMessage(NORMAL, "client %d quit, follow it :P");

            // 为什么要先在epoll中去掉sock再关闭？
            // 要保证epoll中的fd都是合法的，若先close fd，则epoll中的fd不合法，有不可预测的问题
        }
        else
        {
            // 1.先在epoll中去掉对sock的关心
            bool res = Epoll::CtlEpoll(_epfd, EPOLL_CTL_DEL, sock, 0);
            assert(res);
            (void)res;

            // 2.再close fd
            close(sock);
            LogMessage(WARNING, "client recv %d error, close error sock", sock);
        }
    }

private:
    int _listensock;
    int _epfd;
    uint16_t _port;
    struct epoll_event *_revs;
    int _revs_num;
    func_t _HandlerRequest; // 实际数据处理方法交由上层客户
};