#pragma once

#include "Log.hpp"
#include <iostream>
#include <string>
#include <functional>
using namespace std;

typedef function<int(int, int)> func_t;

class Task
{
public:
    Task() 
    {}

    Task(int x, int y, func_t func) 
    : _x(x)
    , _y(y)
    , _func(func)
    {}

    void operator()(const string &name)
    {
        LogMessage(NORMAL, "%s 处理完成：%d + %d = %d | %s | %d",
                   name.c_str(), _x, _y, _func(_x, _y), __FILE__, __LINE__);
    }

public:
    int _x;
    int _y;
    func_t _func;
};