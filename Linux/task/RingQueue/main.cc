#include <ctime>
#include <unistd.h>
#include "RingQueue.hpp"

void *consumer(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);
    while(true)
    {
        sleep(1);
        int x;

        // 1.从环形队列中获取任务或者数据
        rq->pop(x);

        // 2.进行一定处理
        cout << "consumer：" << x << " [" << pthread_self() << "]" << endl;
    }
    
    return nullptr;
}

void *productor(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);
    while(true)
    {
        // 1.构建数据或者任务对象
        int x = rand() % 100 + 1;
        cout << "productor：" << x << " [" << pthread_self() << "]" << endl;

        // 2.推送到环形队列中
        rq->push(x); // 完成生产的过程
    }

    return nullptr;
}

int main()
{
    srand(time(nullptr));
    RingQueue<int> *rq = new RingQueue<int>();

    pthread_t c[3], p[2];
    for (int i = 0; i < 3; i++)
    {
        pthread_create(c + i, nullptr, consumer, (void *)rq);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_create(p + i, nullptr, productor, (void *)rq);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(c[i], nullptr);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(p[i], nullptr);
    }

    return 0;
}