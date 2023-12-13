#include "EpollServer.hpp"
#include <memory>

int main()
{
    std::unique_ptr<EpollServer> svr(new EpollServer());
    svr->Start();

    return 0;
}