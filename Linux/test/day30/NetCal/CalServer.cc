#include "CalServer.hpp"
#include "Protocol.hpp"
#include "Daemon.hpp"
#include <cstdlib>

void Usage(const std::string &process)
{
    std::cout << "\nUsage: " << process << " port\n"
              << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }
    return 0;
}