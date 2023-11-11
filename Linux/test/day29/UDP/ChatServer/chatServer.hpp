// cmdServer：Client给服务器发指令，服务器给响应
#pragma once

#include "Log.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

class UdpServer
{
public:
    UdpServer(uint16_t port, std::string ip = "")
    : _port(port), _ip(ip), _sock(-1)
    {}

    ~UdpServer()
    {
        if(_sock >= 0)
        {
            close(_sock);
        }
    }

    void InitServer()
    {
        _sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(_sock < 0)
        {
            LogMessage(FATAL, "%d:%s", errno, strerror(errno));
            exit(2);
        }

        struct sockaddr_in local;
        memset(&local, 0, sizeof local);
        local.sin_family = AF_INET;
        local.sin_port = htons(_port);
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str());

        if(bind(_sock, (struct sockaddr*)&local, sizeof local) < 0)
        {
            LogMessage(FATAL, "%d:%s", errno, strerror(errno));
            exit(3);
        }

        LogMessage(NORMAL, "Init UDP server done... %s", strerror(errno));
    }

    void Start()
    {
        char buffer[SIZE];
        while (true)
        {
            char usr[64];

            struct sockaddr_in peer;
            bzero(&peer, sizeof peer);
            socklen_t len = sizeof peer;
            ssize_t s = recvfrom(_sock, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len);
            if (s > 0)
            {
                buffer[s] = 0;

                uint16_t cli_port = ntohs(peer.sin_port);
                std::string cli_ip = inet_ntoa(peer.sin_addr);

                snprintf(usr, sizeof usr, "%s:%d", cli_ip.c_str(), cli_port);
                LogMessage(NORMAL, "usr：%s", usr);

                auto it = _users.find(usr);
                if(it == _users.end())
                {
                    // 查无此usr
                    LogMessage(NORMAL, "Add new usr：%s", usr);
                    _users.insert({usr, peer}); // C++11的列表初始化:)
                }
            }

            // 将本次收到的消息广播给所有参与聊天的用户
            std::string msg = usr;
            msg += "# ";
            msg += buffer;

            for(auto &iter : _users)
            {
                LogMessage(NORMAL, "Push msg to %s", iter.first.c_str());
                sendto(_sock, msg.c_str(), msg.size(), 0, (struct sockaddr *)&(iter.second), sizeof iter.second);
            }
        }
    }

private:
    uint16_t _port;
    std::string _ip;
    int _sock;
    std::unordered_map<std::string, struct sockaddr_in> _users;
};