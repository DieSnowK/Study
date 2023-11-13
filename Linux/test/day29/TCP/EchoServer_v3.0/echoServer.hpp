#include "Log.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

static void Service(int sock, const std::string &clientip, const uint16_t clientport)
{
    // echo server
    char buffer[SIZE];
    while(true)
    {
        // read && write 可以使用
        ssize_t s = read(sock, buffer, sizeof(buffer) - 1);
        if(s > 0)
        {
            buffer[s] = 0;
            std::cout << clientip << ":" << clientport << "# " << buffer << std::endl;
        }
        else if(s == 0) // 对端关闭连接
        {
            LogMessage(NORMAL, "%s:%d shutdown, follow it~", clientip.c_str(), clientport);
            break;
        }
        else
        {
            LogMessage(NORMAL, "read socket error, %d:%s", errno, strerror(errno));
            break;
        }

        write(sock, buffer, strlen(buffer));
    }

    close(sock);
}

class ThreadData
{
public:
    ThreadData(int sock, std::string &ip, uint16_t port)
    : _sock(sock), _ip(ip), _port(port)
    {}

    int _sock;
    std::string _ip;
    uint16_t _port;
};

class TcpServer
{
private:
    const static int gbacklog = 20;

    static void*ThreadRoutine(void *args)
    {
        pthread_detach(pthread_self()); // 线程分离，不用join回收
        ThreadData *td = (ThreadData *)args;
        Service(td->_sock, td->_ip, td->_port);
        delete td;
        
        return nullptr;
    }

public:
    TcpServer(uint16_t port, std::string ip = "")
    : _port(port), _ip(ip)
    {}

    ~TcpServer()
    {}

    void InitServer()
    {
        // 1.创建socket
        if ((_listensock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            LogMessage(FATAL, "create socket error, %d:%s", errno, strerror(errno));
            exit(2);
        }

        // 2.bind
        struct sockaddr_in local;
        memset(&local, 0, sizeof local);
        local.sin_family = AF_INET;
        local.sin_port = htons(_port);
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str());

        if(bind(_listensock, (struct sockaddr*)&local, sizeof local) < 0)
        {
            LogMessage(FATAL, "bind error, %d-%s", errno, strerror(errno));
            exit(3);
        }

        // 3.TCP是面向连接的 --> 正式通信的时候，需要先建立连接
        if(listen(_listensock, gbacklog) < 0)
        {
            LogMessage(FATAL, "listen error, %d:%s", errno, strerror(errno));
            exit(4);
        }

        LogMessage(NORMAL, "Init Server success");
    }

    void Start()
    {
        while(true)
        {
            // 4.获取连接
            struct sockaddr_in src;
            socklen_t len = sizeof src;
            int servicesock = accept(_listensock, (struct sockaddr *)&src, &len);
            if(servicesock < 0)
            {
                LogMessage(ERROR, "accept error, %d:%s", errno, strerror(errno));
                continue;
            }

            // 获取连接成功
            uint16_t cli_port = ntohs(src.sin_port);
            std::string cli_ip = inet_ntoa(src.sin_addr);
            LogMessage(NORMAL, "link success, servicesock：%d | %s:%d |",
                       servicesock, cli_ip.c_str(), cli_port);

            // 进行通信服务
            // version 3.0 -- 多线程版
            ThreadData *td = new ThreadData(servicesock, cli_ip, cli_port);
            pthread_t tid;
            pthread_create(&tid, nullptr, ThreadRoutine, (void *)td);

            // pthread_join() // 不需要设置join，会阻塞等待
        }
    }

private:
    uint16_t _port;
    std::string _ip;
    int _listensock;
};