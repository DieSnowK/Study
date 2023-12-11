#pragma once

#include "Log.hpp"
#include "Sock.hpp"
#include <iostream>
#include <sys/select.h>
#include <sys/time.h>

#define BITS 8
#define NUM (sizeof(fd_set)*BITS)
#define FD_NONE -1

class SelectServer
{
public:
    SelectServer(const uint16_t &port = 8080)
    : _port(port)
    {
        _listensock = Sock::Socket();
        Sock::Bind(_listensock, _port);
        Sock::Listen(_listensock);
        LogMessage(NORMAL, "create base socket success");

        for (int i = 0; i < NUM;i++)
        {
            _fd_Array[i] = FD_NONE; // 初始化_fd_Array
        }

        _fd_Array[0] = _listensock; // 约定
    }

    ~SelectServer()
    {
        if (_listensock >= 0)
        {
            close(_listensock);
        }
    }

    void Start()
    {
        while(true)
        {
            // 如何看待_listensock?
            // 获取新连接，依旧把它看成IO，如果没有连接到来，就阻塞
            // 1.nfds：随着获取的sock越来越多，添加到select的sock越来越多，注定了nfds每一次都可能要变化，需要对它动态计算
            // 2.rfds/writefds/exceptfds：都是输入输出型参数，输入输出不一定是一样的，所以注定每次都要对其进行重新添加
            // 3.timeout：输入输出型参数，每一次都要进行重置，前提是需要的话
            // 1,2 --> 注定必须自己将合法的fd单独全部保存起来，以支持：a.更新最大fd b.更新位图结构
            DebugPrint();

            fd_set rfds;
            FD_ZERO(&rfds);

            // 1.遍历数组，更新出maxfd
            // 2.遍历数组，添加所有需要关心的fd到fd_set位图中
            int maxfd = _listensock;
            for (int i = 0; i < NUM;i++)
            {
                if(_fd_Array[i] == FD_NONE)
                {
                    continue;
                }

                FD_SET(_fd_Array[i], &rfds);

                if(maxfd < _fd_Array[i])
                {
                    maxfd = _fd_Array[i];
                }
            }

            // rfds未来，一定会有两类sock，_listensock，普通sock
            struct timeval tv = {0, 0};
            int n = select(maxfd + 1, &rfds, nullptr, nullptr, &tv);
            // int n = select(maxfd, &rfds, nullptr, nullptr, nullptr);
            switch(n)
            {
            case 0:
                LogMessage(NORMAL, "time out...");
                break;
            case -1:
                LogMessage(WARNING, "select error, %s", strerror(errno));
                break;
            default:
                LogMessage(NORMAL, "get a new link event...");
                HandlerEvent(rfds);
                break;
            }
            
            sleep(1);
        }
    }

private:
    void DebugPrint()
    {
        std::cout << "_fd_Array[]: ";
        for (int i = 0; i < NUM; i++)
        {
            if(_fd_Array[i] == FD_NONE)
            {
                continue;
            }
            std::cout << _fd_Array[i] << " ";
        }
        std::cout << std::endl;
    }

    void HandlerEvent(const fd_set &rfds)
    {
        for (int i = 0; i < NUM; i++)
        {
            // 1.去掉不合法的fd
            if(_fd_Array[i] == FD_NONE)
            {
                continue;
            }

            // 2.合法的就一定就绪了？不一定
            if(FD_ISSET(_fd_Array[i], &rfds))
            {
                // 3.指定的fd，读事件就绪
                // a.连接事件到来，accept
                // b.读取数据
                if(_fd_Array[i] == _listensock)
                {
                    Accepter();
                }
                else
                {
                    Recver(i);
                }
            }
        } // end of for()
    }

    void Accepter()
    {
        // _listensock上面的读事件就绪了，表示可以读取了
        std::string clientip;
        uint16_t clientport = 0;
        int sock = Sock::Accept(_listensock, &clientip, &clientport);
        if(sock < 0)
        {
            LogMessage(WARNING, "accept error");
            return;
        }
        LogMessage(NORMAL, "get a new link success: [%s:%d]: %d", clientip.c_str(), clientport, sock);

        // 此时不能read/recv，因为不清楚此sock上的数据何时到来，read/recv时有可能直接被阻塞了
        // 得到新连接时，应考虑将accept到的sock依然托管给select监视
        // 要将sock添加给select，只要将此fd加入到_fd_Array[]即可
        int pos = 1;
        for (; pos < NUM; pos++)
        {
            if(_fd_Array[pos] == FD_NONE)
            {
                break;
            }
        }

        if (pos == NUM)
        {
            LogMessage(WARNING, "select server already full, close: %d", sock);
            close(sock);
        }
        else
        {
            _fd_Array[pos] = sock;
        }
    }

    void Recver(int pos)
    {

    }

private:
    int _listensock;
    uint16_t _port;
    int _fd_Array[NUM];
    // 此处可以用vector，会更加方便
    // 但为了后续说明select问题，故用原生数组
};