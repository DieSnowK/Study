#include "TcpServer.hpp"
#include <memory>

int main()
{
    std::unique_ptr<TcpServer> svr(new TcpServer());
    svr->Dispatcher();
    return 0;
}