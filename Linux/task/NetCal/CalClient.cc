#include <iostream>
#include <unistd.h>
#include "Sock.hpp"
#include "Protocol.hpp"

void Usage(const std::string &process)
{
    std::cout << "\nUsage: " << process << " port\n"
              << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }

    std::string server_ip = argv[1];
    uint16_t server_port = atoi(argv[2]);

    Sock sock;
    int sockfd = sock.Socket();
    if(!sock.Connect(sockfd, server_ip, server_port))
    {
        std::cerr << "Connect error" << std::endl;
        exit(2);
    }

    bool quit = false;
    std::string buffer;
    while(!quit)
    {
        // 1.获取需求
        Request req;
        std::cout << "Please Enter # ";
        std::cin >> req._x >> req._op >> req._y;

        // 2.序列化
        std::string str = req.Serialize();

        // 3.添加长度报头
        str = Encode(str);

        // 4.发送给服务端
        Send(sockfd, str);

        // 5.正常读取
        while(true)
        {
            bool ret = Recv(sockfd, &buffer);
            if (!ret)
            {
                quit = true;
                break;
            }

            std::string package = Decode(buffer);
            if (package.empty())
            {
                continue;
            }

            Response resp;
            resp.DeSerialize(package);

            std::string err;
            switch (resp._code)
            {
            case 1:
                err = "除0错误";
                break;
            case 2:
                err = "模0错误";
                break;
            case 3:
                err = "非法操作";
                break;
            default:
                std::cout << "ret = " << resp._ret << std::endl;
                break;
            }

            if(!err.empty())
            {
                std::cout << err << std::endl;
            }

            break; // 到这里即认为一次完整的CS交互圆满结束
        } // end of while(true)
    } // end of while(!quie)

    close(sockfd);
    return 0;
}