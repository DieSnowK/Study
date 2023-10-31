#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>

using namespace std;

#define TNUM 3
typedef void (*func_t)(const string &name, pthread_mutex_t *pmtx, pthread_cond_t *pcond);
bool quit = false;

class ThreadData
{
public:
    ThreadData(const string &name, func_t func, pthread_mutex_t *pmtx, pthread_cond_t *pcond)
        : _name(name), _func(func), _pmtx(pmtx), _pcond(pcond)
    {}

public:
    string _name;
    func_t _func;
    pthread_mutex_t *_pmtx;
    pthread_cond_t *_pcond;
};

void func1(const string &name, pthread_mutex_t *pmtx, pthread_cond_t *pcond)
{
    while(!quit)
    {
        pthread_mutex_lock(pmtx);
        pthread_cond_wait(pcond, pmtx); // 默认该线程在执行的时候，wait代码被执行，当前线程会被立即阻塞
        cout << name << " running" << endl;
        pthread_mutex_unlock(pmtx);
    }
}

void func2(const string &name, pthread_mutex_t *pmtx, pthread_cond_t *pcond)
{
    while (!quit)
    {
        pthread_mutex_lock(pmtx);
        pthread_cond_wait(pcond, pmtx); // 默认该线程在执行的时候，wait代码被执行，当前线程会被立即阻塞
        cout << name << " running" << endl;
        pthread_mutex_unlock(pmtx);
    }
}

void func3(const string &name, pthread_mutex_t *pmtx, pthread_cond_t *pcond)
{
    while (!quit)
    {
        pthread_mutex_lock(pmtx);
        pthread_cond_wait(pcond, pmtx); // 默认该线程在执行的时候，wait代码被执行，当前线程会被立即阻塞
        cout << name << " running" << endl;
        pthread_mutex_unlock(pmtx);
    }
}

void *Entry(void *args)
{
    ThreadData *td = (ThreadData *)args;
    td->_func(td->_name, td->_pmtx, td->_pcond); // 此函数调用完后会返回
    delete td;
    return nullptr;
}

int main()
{
    pthread_mutex_t mtx;
    pthread_cond_t cond;
    pthread_mutex_init(&mtx, nullptr);
    pthread_cond_init(&cond, nullptr);

    pthread_t tids[TNUM];
    func_t funcs[TNUM] = {func1, func2, func3};
    for (int i = 0; i < TNUM; i++)
    {
        string name = "Thread";
        name += to_string(i + 1);
        ThreadData *td = new ThreadData(name, funcs[i], &mtx, &cond);
        pthread_create(tids + i, nullptr, Entry, (void *)td);
    }

    // ctrl new thread
    int cnt = 10;
    while (cnt)
    {
        cout << "resume thread... " << cnt-- << endl;
        pthread_cond_signal(&cond);
        sleep(1);
    }

    cout << "ctrl done" << endl;
    quit = true;
    pthread_cond_broadcast(&cond);

    for (int i = 0; i < TNUM; i++)
    {
        pthread_join(tids[i], nullptr);
    }

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cond);

    return 0;
}