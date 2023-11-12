#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define SIZE 1024

void Usage(std::string proc)
{
    std::cout << "\nUsage£º" << proc << " ip port" << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }

    std::string serverip = argv[1];
    uint16_t serverport = atoi(argv[2]);

    // 1.´´½¨socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        std::cerr << "socket error" << std::endl;
        exit(2);
    }

    // 2.connect
    struct sockaddr_in server;
    memset(&server, 0, sizeof server);
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    server.sin_addr.s_addr = inet_addr(serverip.c_str());

    if(connect(sock, (struct sockaddr*)&server, sizeof server) < 0)
    {
        std::cerr << "connect error" << std::endl;
        exit(3);
    }
    std::cout << "connect success" << std::endl;

    // 3.work
    char buffer[SIZE];
    while (true)
    {
        std::string line;
        std::cout << "Enter your msg# ";
        std::getline(std::cin, line);
        send(sock, line.c_str(), line.size(), 0);

        ssize_t s = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (s > 0)
        {
            buffer[s] = 0;
            std::cout << "server echo# " << buffer << std::endl;
        }
        else if(s == 0)
        {
            break;
        }
        else
        {
            break;
        }
    }

    close(sock);
    return 0;
}