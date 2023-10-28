#include <iostream>
#include <string>
#include <cassert>
#include <unistd.h>
#include <pthread.h>

using namespace std;


#define THREAD_NUM 5

int tickets = 10000;

class ThreadData
{
public:
    ThreadData(const string &name, pthread_mutex_t *pm)
    : _name(name)
    , _pmtx(pm)
    {}
public:
    string _name;
    pthread_mutex_t *_pmtx;
};

void *GetTickets(void *args)
{
    ThreadData *td = (ThreadData *)args;
    while(true)
    {
        int n = pthread_mutex_lock(td->_pmtx);
        assert(n == 0);

        if(tickets > 0)
        {
            usleep(1000);
            printf("%s：%d\n", td->_name.c_str(), tickets);
            tickets--;
            n = pthread_mutex_unlock(td->_pmtx);
            assert(n == 0);
        }
        else
        {
            n = pthread_mutex_unlock(td->_pmtx);
            assert(n == 0);
            break;
        }
    }

    delete td;
    return nullptr;
}

int main()
{
    pthread_mutex_t mtx;
    pthread_mutex_init(&mtx, nullptr);

    // 多线程抢票逻辑
    pthread_t t[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++)
    {
        string name = "thread";
        name += to_string(i + 1);
        ThreadData *td = new ThreadData(name, &mtx);
        pthread_create(t + i, nullptr, GetTickets, (void *)td);
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(t[i], nullptr);
    }

    pthread_mutex_destroy(&mtx);
    return 0;
}

// int tickets = 10000;

// void *GetTickets(void *args)
// {
//     (void)args;
//     while (true)
//     {
//         if (tickets > 0)
//         {
//             usleep(1000);
//             printf("%p：%d\n", pthread_self(), tickets);
//             tickets--;
//         }
//         else
//         {
//             break;
//         }
//     }

//     return nullptr;
// }

// int main()
// {
//     // 多线程抢票逻辑
//     pthread_t t1, t2, t3;

//     pthread_create(&t1, nullptr, GetTickets, nullptr);
//     pthread_create(&t2, nullptr, GetTickets, nullptr);
//     pthread_create(&t3, nullptr, GetTickets, nullptr);

//     pthread_join(t1, nullptr);
//     pthread_join(t2, nullptr);
//     pthread_join(t3, nullptr);

//     return 0;
// }