#include "ThreadPool.hpp"
#include "Task.hpp"
#include <unistd.h>

int main()
{
    srand(time(nullptr) ^ getpid());
    ThreadPool<Task>::GetThreadPool(5)->Run();

    while(true)
    {
        // 模拟生产
        int x = rand() % 100 + 1;
        usleep(6688);
        int y = rand() % 50 + 1;
        Task t(x, y, [](int x, int y)
               { return x + y; });

        // 将任务推送到线程池中
        ThreadPool<Task>::GetThreadPool(5)->PushTask(t);

        LogMessage(NORMAL, "制作任务完成：%d + %d =?", x, y);
        sleep(1);
    }

    return 0;
}