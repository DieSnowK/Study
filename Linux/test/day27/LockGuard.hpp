#pragma once

#include <iostream>
#include <pthread.h>
using namespace std;

// RAII风格的加锁方式
class LockGuard
{
public:
    LockGuard(pthread_mutex_t *mtx)
    : _pmtx(mtx)
    {
        cout << "加锁" << endl;
        pthread_mutex_lock(_pmtx);
    }

    ~LockGuard()
    {
        cout << "解锁" << endl;
        pthread_mutex_unlock(_pmtx);
    }
private:
    pthread_mutex_t *_pmtx;
};