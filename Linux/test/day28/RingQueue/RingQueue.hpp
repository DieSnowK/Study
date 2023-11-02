#include <iostream>
#include <vector>
#include <pthread.h>
#include "sem.hpp"
using namespace std;

const int g_default_num = 5;

template <class T>
class RingQueue
{
public:
    RingQueue(int default_num = g_default_num)
    : _num(default_num)
    , _rq(default_num)
    , _c_step(0)
    , _p_step(0)
    , _space_sem(default_num)
    , _data_sem(0)
    {
        pthread_mutex_init(&_cmtx, nullptr);
        pthread_mutex_init(&_pmtx, nullptr);
    }

    ~RingQueue()
    {
        pthread_mutex_destroy(&_cmtx);
        pthread_mutex_destroy(&_pmtx);
    }

    // 生产者：空间资源，生产者的临界资源是什么？下标
    void push(const T &in)
    {
        _space_sem.p();
        pthread_mutex_lock(&_pmtx);

        _rq[_p_step++] = in;
        _p_step %= _num;

        pthread_mutex_unlock(&_pmtx);
        _data_sem.v();
    }

    // 消费者：数据资源，消费者的临界资源是什么？下标
    void pop(T &out)
    {
        _data_sem.p();
        pthread_mutex_lock(&_cmtx);

        out = _rq[_c_step++];
        _c_step %= _num;

        pthread_mutex_unlock(&_cmtx);
        _space_sem.v();
    }

private:
    vector<T> _rq;
    int _num;             // 环形队列被划分的个数
    int _c_step;          // 消费下标
    int _p_step;          // 生产下标
    Sem _space_sem;
    Sem _data_sem;
    pthread_mutex_t _cmtx; // 服务于多生产者多消费者
    pthread_mutex_t _pmtx;
};