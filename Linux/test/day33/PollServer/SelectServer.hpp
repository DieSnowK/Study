#pragma once

#include "Log.hpp"
#include "Sock.hpp"
#include <iostream>
#include <poll.h>
#include <sys/time.h>

#define FD_NONE -1

struct pollfd io_233;

class PollServer
{
public:
    PollServer(const uint16_t &port = 8080, const int nfds = 100)
        : _port(port)
        , _nfds(nfds)
    {
        _listensock = Sock::Socket();
        Sock::Bind(_listensock, _port);
        Sock::Listen(_listensock);
        LogMessage(NORMAL, "create base socket success");

        _fds = new struct pollfd[_nfds]; // 第三方数组大小用户可自定义

        for (int i = 0; i < _nfds; i++)
        {
            _fds[i].fd = FD_NONE;
            _fds[i].events = _fds[i].revents = 0;
        }

        _fds[0].fd = _listensock; // 约定
        _fds[0].events = POLLIN;

        _timeout = 1000;
    }

    ~PollServer()
    {
        if (_listensock >= 0)
        {
            close(_listensock);
        }

        if(_fds)
        {
            delete[] _fds;
        }
    }

    void Start()
    {
        while(true)
        {
            DebugPrint();

            int n = poll(_fds, _nfds, _timeout);
            switch (n)
            {
            case 0:
                LogMessage(NORMAL, "time out...");
                break;
            case -1:
                LogMessage(WARNING, "poll error, %s", strerror(errno));
                break;
            default:
                LogMessage(NORMAL, "get a new link event...");
                HandlerEvent();
                break;
            }
        }
    }// end of Start

private:
    void DebugPrint()
    {
        std::cout << "_fd_Array[]: ";
        for (int i = 0; i < _nfds; i++)
        {
            if(_fds[i].fd == FD_NONE)
            {
                continue;
            }
            std::cout << _fds[i].fd << " ";
        }
        std::cout << std::endl;
    }

    void HandlerEvent()
    {
        for (int i = 0; i < _nfds; i++)
        {
            if (_fds[i].fd == FD_NONE)
            {
                continue;
            }

            if(_fds[i].revents & POLLIN) // 用标志位来区分状态
            {
                if (_fds[i].fd == _listensock)
                {
                    Accepter();
                }
                else
                {
                    Recver(i);
                }
            }
        } // end of for()
    } // end of HandlerEvent

    void Accepter()
    {
        std::string clientip;
        uint16_t clientport = 0;
        int sock = Sock::Accept(_listensock, &clientip, &clientport);
        if(sock < 0)
        {
            LogMessage(WARNING, "accept error");
            return;
        }
        LogMessage(NORMAL, "get a new link success: [%s:%d]: %d", clientip.c_str(), clientport, sock);

        int pos = 1;
        for (; pos < _nfds; pos++)
        {
            if (_fds[pos].fd == FD_NONE)
            {
                break;
            }
        }

        if (pos == _nfds)
        {
            // 这里可以考虑对_fds进行自动扩容
            LogMessage(WARNING, "select server already full, close: %d", sock);
            close(sock);
        }
        else
        {
            _fds[pos].fd = sock;
            _fds[pos].events = POLLIN;
        }
    } // end of Accepter

    void Recver(int pos)
    {
        LogMessage(NORMAL, "get IO event, message in: %d", _fds[pos].fd);

        char buffer[1024];
        int n = recv(_fds[pos].fd, buffer, sizeof(buffer) - 1, 0);
        if(n > 0)
        {
            buffer[n - 1] = 0;
            LogMessage(NORMAL, "client[%d]# %s", _fds[pos].fd, buffer);
        }
        else if(n == 0)
        {
            LogMessage(NORMAL, "client[%d] quit, follow it :P", _fds[pos].fd);
            // 1.关闭不需要的fd
            close(_fds[pos].fd);
            // 2.不要让select关心此fd了
            _fds[pos].fd = FD_NONE;
            _fds->events = _fds->revents = 0;
        }
        else
        {
            LogMessage(WARNING, "%d sock recv error: %s", _fds[pos].fd, strerror(errno));
            // 1.关闭不需要的fd
            close(_fds[pos].fd);
            // 2.不要让select关心此fd了
            _fds[pos].fd = FD_NONE;
            _fds->events = _fds->revents = 0;
        }
    } // end of Recver

private:
    int _listensock;
    uint16_t _port;
    struct pollfd *_fds;
    int _nfds;
    int _timeout;
};