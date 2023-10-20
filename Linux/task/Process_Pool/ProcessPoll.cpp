#include <iostream>
#include <cassert>
#include <wait.h>
#include "Task.hpp"
using namespace std;

#define PROCESS_NUM 5

int waitCommand(int fd, bool &quit)
{
    uint32_t command = 0; // 规定接受4字节命令
    ssize_t s = read(fd, &command, sizeof(command));
    if (s == 0)
    {
        quit = true;
        return -1;
    }

    assert(s == sizeof(uint32_t)); // 规定接受4字节命令
    return command;
}

void sendAndWakeup(pid_t who, int fd, uint32_t command)
{
    write(fd, &command, sizeof(command));
    cout << "main process：call process " << who << " excute " << desc[command] << " through " << fd << endl;
}

int main()
{
    vector<pair<pid_t, int>> slots;
    load();

    // 先创建多个进程
    for (int i = 0; i < PROCESS_NUM; i++)
    {
        // 创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        assert(n == 0);
        (void)n;

        pid_t id = fork();
        assert(id != -1);

        if(id == 0)
        {
            // child - read
            close(pipefd[1]);

            while(true)
            {
                bool quit = false;
                int command = waitCommand(pipefd[0], quit); // 如果对方不发送，就阻塞等待
                if (quit)
                {
                    break;
                }

                // 执行对应命令
                if(command >= 0 && command < handlerSize())
                {
                    callbacks[command]();
                }
                else
                {
                    cout << "非法command：" << command << endl;
                }
            }

            exit(1);
        }

        // parent - write
        close(pipefd[0]);
        slots.push_back(make_pair(id, pipefd[1]));
    }

    // 父进程派发任务
    srand(time(nullptr) ^ getpid()); // 此举让数据源更随机

    while(true)
    {
        // 选择一个任务
        int command = rand() % handlerSize();

        // 选择一个进程，采用随机数的方式选择进程来完成任务，随机数方式的负载均衡
        int choice = rand() % slots.size();

        // 把任务派送给指定的进程
        sendAndWakeup(slots[choice].first, slots[choice].second, command);
        sleep(1);
    }

    // 关闭fd，所有的子进程都会退出
    for(const auto &slot : slots)
    {
        close(slot.second);
    }

    // 回收所有的子进程
    for(const auto &slot : slots)
    {
        waitpid(slot.first, nullptr, 0);
    }

    return 0;
}