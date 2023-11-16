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

static Response CalcuatorDealer(const Request &req)
{
    Response resp(0, 0);
    switch (req._op)
    {
    case '+':
        resp._ret = req._x + req._y;
        break;
    case '-':
        resp._ret = req._x - req._y;
        break;
    case '*':
        resp._ret = req._x * req._y;
        break;
    case '/':
        if (0 == req._y)
        {
            resp._code = 1;
        }
        else
        {
            resp._ret = req._x / req._y;
        }
        break;
    case '%':
        if (0 == req._y)
        {
            resp._code = 2;
        }
        else
        {
            resp._ret = req._x % req._y;
        }
        break;
    default:
        resp._code = 3;
        break;
    }
    
    return resp;
}

void Calculator(int sock)
{
    std::string inbuffer;
    while (true)
    {
        // 1.读取请求
        bool ret = Recv(sock, &inbuffer);
        if (!ret)
        {
            break;
        }

        // 2.解析协议，保证得到了一个完整的报文
        std::string package = Decode(inbuffer);
        if (package.empty())
        {
            continue;
        }
        LogMessage(NORMAL, "%s", package.c_str());

        // 3.反序列化：字节流 -> 结构化
        Request req;
        req.DeSerialize(package);

        // 4.业务逻辑
        Response resp;
        resp = CalcuatorDealer(req);

        // 5.序列化
        std::string respStr = resp.Serialize();

        // 6.添加长度信息，形成一个完整报文
        respStr = Encode(respStr);

        // 7.发送
        Send(sock, respStr);
    }
}

// 一般服务器都是要忽略SIGPIPE信号的，防止在运行中出现非法写入的问题
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    // Daemon();

    std::unique_ptr<TcpServer> svr(new TcpServer(atoi(argv[1])));
    svr->BindService(Calculator);
    svr->Start();

    return 0;
}