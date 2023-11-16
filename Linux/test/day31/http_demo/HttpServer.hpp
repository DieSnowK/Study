#pragma once

#include "Sock.hpp"
#include <functional>
#include <signal.h>

using func_t = std::function<void(int)>;

class HttpServer
{
public:
    HttpServer(uint16_t port, func_t func)
    : _port(port), _func(func)
    {
        _listensock = _sock.Socket();
        _sock.Bind(_listensock, _port);
        _sock.Listen(_listensock);
    }

    ~HttpServer()
    {
        if(_listensock > 0)
        {
            close(_listensock);
        }
    }

    void Start()
    {
        signal(SIGCHLD, SIG_IGN);
        while(true)
        {
            std::string cli_ip;
            uint16_t cli_port;
            int sockfd = _sock.Accept(_listensock, &cli_ip, &cli_port);
            if(sockfd < 0)
            {
                continue;
            }

            if(fork() == 0)
            {
                close(_listensock);
                _func(sockfd);
                close(sockfd);
                exit(0);
            }
            close(sockfd);
        }
    }

private:
    Sock _sock;
    int _listensock;
    uint16_t _port;
    func_t _func;
};