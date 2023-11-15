#include "TcpServer.hpp"
#include "Protocol.hpp"
#include "Daemon.hpp"
#include <cstdlib>
#include <memory>

void Usage(const std::string &process)
{
    std::cout << "\nUsage: " << process << " port\n"
              << std::endl;
}

// 一般服务器都是要忽略SIGPIPE信号的，防止在运行中出现非法写入的问题
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    // Daemon();

    std::unique_ptr<TcpServer> svr(new TcpServer(atoi(argv[1])));
    svr->Start();
    
    return 0;
}