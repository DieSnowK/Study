// 线程池本质是一个生产消费模型
// 此处模拟一个线程安全的单例线程池(基于懒汉模式) 

#pragma once

#include "Log.hpp"
#include "Thread.hpp"
#include "LockGuard.hpp"
#include <vector>
#include <queue>
using namespace std;

const int g_thread_num = 3;

template<class T>
class ThreadPool
{
public:
    // 以下函数为static Routine服务
    pthread_mutex_t *GetMutex()
    {
        return &_mtx;
    }

    bool IsEmpty()
    {
        return _task_queue.empty();
    }

    void WaitCond()
    {
        pthread_cond_wait(&_cond, &_mtx);
    }

    T GetTask()
    {
        T t = _task_queue.front();
        _task_queue.pop();
        return t;
    }

private:
    ThreadPool(int thread_num = g_thread_num)
    : _num(thread_num)
    {
        pthread_mutex_init(&_mtx, nullptr);
        pthread_cond_init(&_cond, nullptr);
        for (int i = 0; i < _num; i++)
        {
            _threads.push_back(new Thread(i + 1, Routine, this));
        }
    }

    ThreadPool(const ThreadPool<T> &other) = delete;
    const ThreadPool<T> &operator=(const ThreadPool<T> &other) = delete;

public:
    ~ThreadPool()
    {
        for (auto &iter : _threads)
        {
            iter->join();
            delete iter;
            iter = nullptr;
        }

        pthread_mutex_destroy(&_mtx);
        pthread_cond_destroy(&_cond);
    }

    // 如果单例本身也在被多线程申请使用呢？
    // 考虑多线程使用单例过程
    // 思考这里为什么加static？ -- 这个坑很有意思:P
    static ThreadPool<T> *GetThreadPool(int num = g_thread_num)
    {
        // 第一层if可以有效减少未来必定要进行加锁检测的问题
        // 拦截大量的在已经创建好单例的时候，剩余线程请求单例而直接访问锁的行为
        // 毕竟每次调用GetThreadPool都无意义的请求释放锁是浪费资源的
        if(_thread_ptr == nullptr)
        {
            // 此处加锁是为了防止多个执行流首次创建单例对象
            LockGuard lockguard(&_smtx);
            if (_thread_ptr == nullptr)
            {
                _thread_ptr = new ThreadPool<T>(num);
            }
        }

        return _thread_ptr;
    }

    // 运行各个线程
    void Run()
    {
        for(auto &iter : _threads)
        {
            iter->start();
            LogMessage(NORMAL, "%s %s", iter->name().c_str(), "启动~");
        }
    }

    // 这里为什么加锁? -- 访问临界资源
    void PushTask(const T &task)
    {
        LockGuard lockguard(&_mtx);
        _task_queue.push(task);
        pthread_cond_signal(&_cond);
    }

    // 成员函数默认带*this，不满足tfun_t要求
    // 故将routine设置成static，不带*this
    // 消费过程
    // static无法访问非静态成员
    // 所以构造函数处，将此ThreadPool当作args传给routine当args
    static void *Routine(void *args)
    {
        ThreadData *td = (ThreadData *)(args);
        ThreadPool<T> *tp = (ThreadPool<T> *)td->_args; // 获取ThreadPool实例化出的对象

        while(true)
        {
            T task;
            {
                LockGuard lockguard(tp->GetMutex());
                while (tp->IsEmpty())
                {
                    tp->WaitCond();
                }

                // 读取任务
                task = tp->GetTask(); // 任务队列是共享的 --> 将任务从共享拿到自己的私有空间
            }
            task(td->_name);
        }
    }

private:
    vector<Thread *> _threads;
    int _num;
    queue<T> _task_queue; // 临界资源

    pthread_mutex_t _mtx;
    pthread_cond_t _cond;

    static ThreadPool<T> *_thread_ptr; // 不能属于对象，只能属于类
    static pthread_mutex_t _smtx;
};

// static成员变量类外初始化
template <class T>
ThreadPool<T> *ThreadPool<T>::_thread_ptr = nullptr;

template <class T>
pthread_mutex_t ThreadPool<T>::_smtx = PTHREAD_MUTEX_INITIALIZER; // 初始化