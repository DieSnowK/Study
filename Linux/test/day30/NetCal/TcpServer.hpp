#include "Sock.hpp"
#include <iostream>
#include <functional>
#include <vector>

using func_t = std::function<void(int)>;

class TcpServer; // 声明TcpServer，以便ThreadData可以识别
class ThreadData
{
public:
    ThreadData(int sock, TcpServer *svr)
        : _sock(sock), _svr(svr)
    {}

    ~ThreadData()
    {}

public:
    int _sock;
    TcpServer *_svr;
};

class TcpServer
{
public:
    TcpServer(const uint16_t &port, const std::string &ip = "")
    {
        _listensock = _sock.Socket();
        _sock.Bind(_listensock, port, ip);
        _sock.Listen(_listensock);
    }

    ~TcpServer()
    {
        if(_listensock > 0)
        {
            close(_listensock);
        }
    }

    void Start()
    {
       while(true)
       {
           std::string cli_ip;
           uint16_t cli_port;
           int sock = _sock.Accept(_listensock, &cli_ip, &cli_port);
           if(sock < 0)
           {
               continue;
           }
           LogMessage(NORMAL, "create new link success, sock：%d", sock);

           pthread_t tid;
           ThreadData *td = new ThreadData(sock, this);
           pthread_create(&tid, nullptr, ThreadRoutine, (void *)td);
       }
    }

    void BindService(func_t func) // 注册方法
    {
        _func.push_back(func);
    }

    void Execute(int sock)
    {
        for(auto &f : _func)
        {
            f(sock);
        }
    }

private:
    static void *ThreadRoutine(void *args)
    {
        pthread_detach(pthread_self());
        ThreadData *td = static_cast<ThreadData *>(args);
        td->_svr->Execute(td->_sock);

        delete td;
        close(td->_sock);
        return nullptr;
    }

private:
    int _listensock;
    Sock _sock;
    std::vector<func_t> _func;
};