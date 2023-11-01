#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>
#include "LockGuard.hpp"
using namespace std;

const int gDefaultCap = 5;

template<class T>
class BlockQueue
{
public:
    BlockQueue(int capacity = gDefaultCap)
    : _capacity(capacity)
    {
        pthread_mutex_init(&_mtx, nullptr);
        pthread_cond_init(&_empty, nullptr);
        pthread_cond_init(&_full, nullptr);
    }

    ~BlockQueue()
    {
        pthread_mutex_destroy(&_mtx);
        pthread_cond_destroy(&_empty);
        pthread_cond_destroy(&_full);
    }

    void push(const T &in) // 生产者
    {
        LockGuard lockguard(&_mtx);
        
        while (isFull())
        {
            pthread_cond_wait(&_full, &_mtx);
        }

        _bq.push(in);

        pthread_cond_signal(&_empty);
    }

    void pop(T *out) // 消费者
    {
        LockGuard lockguard(&_mtx);

        while(isEmpty())
        {
            pthread_cond_wait(&_empty, &_mtx);
        }

        *out = _bq.front();
        _bq.pop();

        pthread_cond_signal(&_full);
    }

private:
    bool isEmpty()
    {
        return _bq.size() == 0;
    }

    bool isFull()
    {
        return _bq.size() == _capacity;
    }

private:
    queue<T> _bq;          // 阻塞队列
    int _capacity;         // 容量上限
    pthread_mutex_t _mtx;  // 通过互斥锁保证队列安全
    pthread_cond_t _empty; // 用来表示bq是否为空的条件
    pthread_cond_t _full;  // 用来表示bq是否为满的条件
};