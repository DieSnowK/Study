#include "cmdServer.hpp"
#include <memory>

void Usage(std::string proc)
{
    std::cout << "\nUsage：" << proc << " port" << std::endl << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    // std::string ip = argv[1];
    uint16_t port = atoi(argv[1]);
    std::unique_ptr<UdpServer> svr(new UdpServer(port));

    svr->InitServer();
    svr->Start();

    return 0;
}