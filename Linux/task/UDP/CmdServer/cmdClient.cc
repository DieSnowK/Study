#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

void Usage(std::string proc)
{
    std::cout << "\nUsage：" << proc << " ip port" << std::endl;
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

    // client要不要bind？-- 要，但是一般client不会显式bind，程序员不会自己bind
    // client是一个客户端 --> 普通人下载安装启动使用的 --> 如果程序员自己bind了
    // --> client一旦bind了一个固定的ip和port，万一其他的客户端提前占用了这个port该怎么办？
    // client一般不需要显式bind指定port，而是让OS自动随机选择
    std::string msg;
    struct sockaddr_in server;
    memset(&server, 0, sizeof server);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    char buffer[SIZE];
    while (true)
    {
        std::cout << "Enter your msg# ";
        std::getline(std::cin, msg);

        // 当client首次发送消息给server的时候，OS会自动给client bind它的IP和PORT
        sendto(sock, msg.c_str(), msg.size(), 0, (struct sockaddr *)&server, sizeof server);

        struct sockaddr_in tmp;
        memset(&tmp, 0, sizeof tmp);
        socklen_t len = sizeof tmp;

        ssize_t s = recvfrom(sock, buffer, sizeof buffer, 0, (struct sockaddr *)&tmp, &len);
        if(s > 0)
        {
            buffer[s] = 0;
            std::cout << "Server echo# " << buffer << std::endl;
        }
    }

    return 0;
}