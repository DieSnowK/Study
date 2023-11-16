#pragma once

#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 自己实现一个daemon()，让进程变为守护进程
void Daemon()
{
    // 1.忽略信号，SIGPIPE，SIGCHLD
    signal(SIGCHLD, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);

    // 2.不要让自己成为进程组组长
    if(fork() > 0)
    {
        exit(0);
    }

    // 3.调用setsid
    setsid();

    // 4.重定向标准输入、标准输出、标准输出
    // 守护进程不能直接向显示器打印消息
    int devnull = open("/dev/null", O_RDONLY | O_WRONLY);
    if(devnull > 0)
    {
        dup2(0, devnull);
        dup2(1, devnull);
        dup2(2, devnull);
        close(devnull);
    }
}