// echoServer：Client给服务器发送消息，原封不动返回
#pragma once

#include "Log.hpp"
#include <iostream>
#include <string>
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
        // 1.创建套接字
        _sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(_sock < 0)
        {
            LogMessage(FATAL, "%d:%s", errno, strerror(errno));
            exit(2);
        }
        
        // 2.bind：将用户设置的ip和port在内核中和当前的进程强关联
        struct sockaddr_in local;
        memset(&local, 0, sizeof local);
        local.sin_family = AF_INET;

        // 服务器的IP和端口未来也是要发给对方主机的 -->  先要将数据发送到网络
        local.sin_port = htons(_port);

        // 1. 将点分十进制IP转换为4字节
        // 2. 4字节主机序列 --> 网络序列
        // 有一套接口，可以一次性做完这两件事情
        // INADDR_ANY：让服务器在工作过程中，可以从任意IP中获取数据
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
        // 作为一款服务器，永远不推出
        // 服务器启动 --> 进程 --> 常驻进程 --> 永远在内存中存在，除非挂了
        char buffer[SIZE];
        while (true)
        {
            // peer：纯输出型参数
            struct sockaddr_in peer;
            bzero(&peer, sizeof peer); // 将前n个bit位置零，这里功能类似memset，单纯用用，无他

            // start.读取数据
            // len：输入输出型参数
            // 输入：peer缓冲区大小
            // 输出：实际读到的peer
            socklen_t len = sizeof peer; // 不可设为0，原因如上
            ssize_t s = recvfrom(_sock, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len); // UDP协议下，接收消息接口
            if (s > 0)
            {
                buffer[s] = 0;
                // 这里暂定执行以下任务
                // 1.输出发送的数据信息
                // 2.是谁发送的？
                uint16_t cli_port = ntohs(peer.sin_port); // 数据从网络中来，所以要转
                std::string cli_ip = inet_ntoa(peer.sin_addr); // 4字节的网络序列IP --> 本主机的字符串风格的IP
                printf("[%s:%d]# %s\n", cli_ip.c_str(), cli_port, buffer);
            }

            // 分析和处理数据，TODO
            // end.写回数据
            sendto(_sock, buffer, strlen(buffer), 0, (struct sockaddr *)&peer, len);
        }
    }

private:
    // 一个服务器，一般必须需要ip地址和port(16位整数)
    uint16_t _port;
    std::string _ip;
    int _sock;
};