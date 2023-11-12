#include "echoServer.hpp"
#include <memory>

void Usage(const std::string proc)
{
    std::cout << "\nUsage：" << proc << " port" << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    uint16_t port = atoi(argv[1]);
    std::unique_ptr<TcpServer> svr(new TcpServer(port));

    svr->InitServer();
    svr->Start();

    return 0;
}