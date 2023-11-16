#pragma once

#include "Log.hpp"
#include <iostream>
#include <string>
#include <functional>

// typedef std::function<void(int, const std::string &, const uint16_t, const std::string &)> func_t;

// 此用法和以上用法作用相同，只是为了多见见，无它
using func_t = std::function<void(int, const std::string &, const uint16_t, const std::string &)>;

class Task
{
public:
    Task() 
    {}

    Task(int sock, const std::string &ip, uint16_t port, func_t func) 
    : _sock(sock), _ip(ip), _port(port), _func(func)
    {}

    void operator()(const std::string &name)
    {
        _func(_sock, _ip, _port, name);
    }

public:
    int _sock;
    uint16_t _port;
    std::string _ip;
    func_t _func;
};