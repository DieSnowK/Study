#include "Thread.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

// 无论多线程读还是写，用的sock都是一个，sock代表就是文件
// UDP是全双工的 --> 可以同时进行收发而不受干扰

std::string serverip;
uint16_t serverport = 0;

void Usage(std::string proc)
{
    std::cout << "\nUsage：" << proc << " ip port" << std::endl;
}

void *UdpSend(void *args)
{
    int sock = *(int *)((ThreadData *)args)->_args;
    std::string name = ((ThreadData *)args)->_name;

    std::string msg;
    struct sockaddr_in server;
    memset(&server, 0, sizeof server);
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    server.sin_addr.s_addr = inet_addr(serverip.c_str());

    while(true)
    {
        std::cerr << "Enter your msg# "; // 这里使用cerr暂且是为了分开服务器返回的群聊消息和此条提示
        std::getline(std::cin, msg);
        sendto(sock, msg.c_str(), msg.size(), 0, (struct sockaddr *)&server, sizeof server);
    }

    return nullptr;
}

void *UdpRecv(void *args)
{
    int sock = *(int *)((ThreadData *)args)->_args;
    std::string name = ((ThreadData *)args)->_name;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    server.sin_addr.s_addr = inet_addr(serverip.c_str());

    char buffer[SIZE];
    while (true)
    {
        memset(buffer, 0, sizeof buffer);
        struct sockaddr_in tmp;
        socklen_t len = sizeof tmp;
        ssize_t s = recvfrom(sock, buffer, sizeof buffer - 1, 0, (struct sockaddr *)&server, &len);
        if(s > 0)
        {
            buffer[s] = 0;
            std::cout << buffer << std::endl;
        }
    }

    return nullptr;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        std::cerr << "socket error" << std::endl;
        exit(2);
    }

    serverip = argv[1];
    serverport = atoi(argv[2]);

    std::unique_ptr<Thread> sender(new Thread(1, UdpSend, (void *)&sock));
    std::unique_ptr<Thread> recver(new Thread(2, UdpRecv, (void *)&sock));

    sender->start();
    recver->start();

    sender->join();
    recver->join();

    close(sock);
    return 0;
}