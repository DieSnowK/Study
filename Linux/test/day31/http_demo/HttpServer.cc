#include "HttpServer.hpp"
#include "Util.hpp"
#include <memory>
#include <vector>

#define ROOT "./webroot"
#define HOMEPAGE "index.html"

void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " port\n"
              << std::endl;
}

void HandlerHttpRequest(int sock)
{
    // 1.读取请求
    char buffer[10240];
    ssize_t s = recv(sock, buffer, sizeof buffer - 1, 0);
    if(s > 0)
    {
        buffer[s] = 0;
    }

    std::vector<std::string> vLine;
    Util::CutString(buffer, "\n", &vLine);

    std::vector<std::string> vBlock;
    Util::CutString(vLine[0], " ", &vBlock);

    std::string file = vBlock[1];
    std::string target = ROOT;

    if(file == "/") // TODO 
    {
        
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[1]);
    }

    std::unique_ptr<HttpServer> svr(new HttpServer(atoi(argv[1]), HandlerHttpRequest));
    svr->Start();

    return 0;
}