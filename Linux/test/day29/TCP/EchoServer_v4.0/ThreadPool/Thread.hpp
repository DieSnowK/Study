#pragma once

#include <iostream>
#include <string>
#include <pthread.h>
using namespace std;

typedef void *(*tfun_t)(void *);

struct ThreadData
{
    void *_args;
    string _name;
};

class Thread
{
public:
    Thread(int num, tfun_t callback, void *args)
    : _func(callback)
    {
        char nameBuffer[64];
        snprintf(nameBuffer, sizeof nameBuffer, "Thread-%d", num);

        _tData._name = nameBuffer;
        _tData._args = args;
    }

    ~Thread()
    {}

    void start()
    {
        pthread_create(&_tid, nullptr, _func, (void *)&_tData);
    }

    void join()
    {
        pthread_join(_tid, nullptr);
    }

    const string& name()
    {
        return _tData._name;
    }

private:
    tfun_t _func;
    ThreadData _tData;
    pthread_t _tid;
};