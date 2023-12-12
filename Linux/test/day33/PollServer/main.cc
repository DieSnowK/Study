#include "SelectServer.hpp"
#include <memory>

int main()
{
    std::unique_ptr<PollServer> svr(new PollServer());
    svr->Start();

    return 0;
}