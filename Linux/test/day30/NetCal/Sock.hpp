#pragma once

#include "Log.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

class Sock
{
private:
    const static int gbacklog = 20;
public:
    Sock()
    {}

    ~Sock()
    {}

    int Socket()
    {
        int listensock = socket(AF_INET, SOCK_STREAM, 0);
        if (listensock < 0)
        {
            LogMessage(FATAL, "create socket error, %d:%s", errno, strerror(errno));
            exit(2);
        }

        return listensock;
    }

    void Bind(int sock, uint16_t port, std::string ip = "")
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

    int Listen(int sock)
    {
        if (listen(sock, gbacklog) < 0)
        {
            LogMessage(FATAL, "listen error, %d:%s", errno, strerror(errno));
            exit(4);
        }
        LogMessage(NORMAL, "Init Server success");
    }

    // TODO 一般经验，歇会考虑用不用
    // const std::string &：输入型参数
    // std::string *：输出型参数
    // std::string &：输入输出型参数
    int Accept(int listensock, std::string *ip, uint16_t *port)
    {
        struct sockaddr_in src;
        socklen_t len = sizeof src;
        int servicesock = accept(listensock, (struct sockaddr *)&src, &len);
        if (servicesock < 0)
        {
            LogMessage(ERROR, "accept error, %d:%s", errno, strerror(errno));
            exit(5);
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
};