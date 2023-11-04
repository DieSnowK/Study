#pragma once

#include <iostream>
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

    int operator()()
    {
        return _func(_x, _y);
    }

public:
    int _x;
    int _y;
    func_t _func;
};