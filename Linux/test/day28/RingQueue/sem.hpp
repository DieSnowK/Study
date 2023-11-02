#pragma once

#include <semaphore.h>

// 将库中信号量封装
class Sem
{
public:
    Sem(int value)
    {
        sem_init(&_sem, 0, value);
    }

    ~Sem()
    {
        sem_destroy(&_sem);
    }

    void p()
    {
        sem_wait(&_sem);
    }

    void v()
    {
        sem_post(&_sem);
    }

private:
    sem_t _sem;
};