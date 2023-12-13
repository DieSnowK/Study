#include "Log.hpp"
#include "Epoll.hpp"
#include "Sock.hpp"
#include <iostream>
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
    EpollServer(const uint16_t &port = default_port, const int num = g_num)
    : _port(port)
    , _revs_num(num)
    {
        // 1.����_listensock
        _listensock = Sock::Socket();
        Sock::Bind(_listensock, _port);
        Sock::Listen(_listensock);

        // 2.�����Ӧ�ռ�
        _revs = new struct epoll_event[_revs_num];

        // 3.����epollģ��
        _epfd = Epoll::CreateEpoll();
        LogMessage(NORMAL, "Init success, _listensock: %d, _epfd: %d", _listensock, _epfd);

        // 4.��_listensock����ӵ�epoll�У���epoll�йܴ�fd
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
        int n = Epoll::WaitEpoll()
    }

private:
    int _listensock;
    int _epfd;
    uint16_t _port;
    struct epoll_event *_revs;
    int _revs_num;
    func_t _HandlerRequest;
};