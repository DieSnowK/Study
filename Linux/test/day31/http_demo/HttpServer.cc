#include "HttpServer.hpp"
#include "Util.hpp"
#include <fstream>
#include <memory>
#include <vector>

// 一般http都要有自己的web根目录
#define ROOT "./wwwroot"
// 若客户端只请求了/，则返回首页
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
        std::cout << buffer << std::endl;
    }

    // 2.截取每一行
    std::vector<std::string> vLine;
    Util::CutString(buffer, "\r\n", &vLine);

    // 3.截取出请求行每一个字段
    std::vector<std::string> vBlock;
    Util::CutString(vLine[0], " ", &vBlock);

    // 4.想要访问的目标文件
    std::string file = vBlock[1];
    std::string target = ROOT;

    if(file == "/") // string重载了operator==
    {
        file = "/index.html";
    }
    target += file;

    // 5.处理分析
    std::string content;
    std::ifstream in(target);
    if(in.is_open())
    {
        // 读取文件流里的内容
        std::string line;
        while(std::getline(in, line))
        {
            content += line;
        }
        in.close();
    }

    // 6.构建http响应
    std::string HttpResponse;
    if(content.empty())
    {
        HttpResponse = "HTTP/1.1 302 NotFound\r\n";
        HttpResponse += "Location: https://www.bilibili.com/\r\n";
    }
    else
    {
        HttpResponse = "HTTP/1.1 200 OK\r\n";
        // TODO
        HttpResponse += ("Content-Type: text/html\r\n");
        HttpResponse += ("Content-Length: " + std::to_string(content.size()) + "\r\n");
        HttpResponse += "Set-Cookie: 这是一个cookie\r\n";
    }
    HttpResponse += "\r\n";
    HttpResponse += content;

    send(sock, HttpResponse.c_str(), HttpResponse.size(), 0);
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