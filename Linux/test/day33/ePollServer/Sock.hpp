#pragma once

#include "Log.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

// 为了方便类外使用，故将部分方法设置为static
class Sock
{
private:
    // listen的第二个参数，意义：底层全连接队列的长度 = listen的第二个参数+1
    const static int gbacklog = 20;
public:
    Sock()
    {}

    ~Sock()
    {}

    static int Socket()
    {
        int listensock = socket(AF_INET, SOCK_STREAM, 0);
        if (listensock < 0)
        {
            LogMessage(FATAL, "create socket error, %d:%s", errno, strerror(errno));
            exit(2);
        }

        int opt = 1;
        setsockopt(listensock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof opt);

        return listensock;
    }

    static void Bind(int sock, uint16_t port, std::string ip = "")
    {
        struct sockaddr_in local;
        memset(&local, 0, sizeof local);
        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        local.sin_addr.s_addr = ip.empty() ? INADDR_ANY : inet_addr(ip.c_str());

        if (bind(sock, (struct sockaddr *)&local, sizeof local) < 0)
        {
            LogMessage(FATAL, "bind error, %d-%s", errno, strerror(errno));
            exit(3);
        }
    }

    static void Listen(int sock)
    {
        if (listen(sock, gbacklog) < 0)
        {
            LogMessage(FATAL, "listen error, %d:%s", errno, strerror(errno));
            exit(4);
        }
        LogMessage(NORMAL, "Init Server success");
    }

    static int Accept(int listensock, std::string *ip, uint16_t *port)
    {
        struct sockaddr_in src;
        socklen_t len = sizeof src;
        int servicesock = accept(listensock, (struct sockaddr *)&src, &len);
        if (servicesock < 0)
        {
            LogMessage(ERROR, "accept error, %d:%s", errno, strerror(errno));
            return -1;
        }

        if(port)
        {
            *port = ntohs(src.sin_port);
        }

        if(ip)
        {
            *ip = inet_ntoa(src.sin_addr);
        }

        return servicesock;
    }

    static bool Connect(int sock, std::string &serverip, const uint16_t serverport)
    {
        struct sockaddr_in server;
        memset(&server, 0, sizeof server);
        server.sin_family = AF_INET;
        server.sin_port = htons(serverport);
        server.sin_addr.s_addr = inet_addr(serverip.c_str());

        if (connect(sock, (struct sockaddr *)&server, sizeof server) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};