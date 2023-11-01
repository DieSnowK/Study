#include "BlockQueue.hpp"
#include "Task.hpp"
#include <ctime>
#include <unistd.h>

int Add(int x, int y)
{
    return x + y;
}

void *consumer(void *args)
{
    BlockQueue<Task> *bqueue = (BlockQueue<Task> *)args;
    while (true)
    {
        // 获取任务
        Task t;
        bqueue->pop(&t);

        // 完成任务
        cout << "consumer：" << t._x << "+" << t._y << "=" << t() << endl;
    }

    return nullptr;
}

void *productor(void *args)
{
    BlockQueue<Task> *bqueue = (BlockQueue<Task> *)args;
    while (true)
    {
        // 类制作任务
        int x = rand() % 10 + 1;
        int y = rand() % 5 + 1;
        Task t(x, y, Add);

        // 生产任务
        bqueue->push(t);

        cout << "productor：" << t._x << "+" << t._y << "=?" << endl;
        sleep(1);
    }

    return nullptr;
}

int main()
{
    srand(time(nullptr) ^ getpid());
    BlockQueue<int> *bqueue = new BlockQueue<int>();

    pthread_t c[2], p[2];
    for (int i = 0; i < 2; i++)
    {
        pthread_create(c + i, nullptr, consumer, (void *)bqueue);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_create(c + i, nullptr, productor, (void *)bqueue);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(c[i], nullptr);
        pthread_join(p[i], nullptr);
    }

    return 0;
}