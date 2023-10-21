#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include "Log.hpp"

using namespace std;

#define PATH_NAME "/home/snowk"
#define PROJ_ID 0x233
#define SHM_SIZE 4096 // 共享内存大小，最好是页(PAGE:4096)整数倍
#define FIFO_NAME "./fifo"
#define READ O_RDONLY
#define WRITE O_WRONLY

class Init
{
public:
    Init()
    {
        umask(0);
        int n = mkfifo(FIFO_NAME, 0666);
        assert(n == 0);
        (void)n;
        Log("create fifo success", NOTICE) << endl;
    }

    ~Init()
    {
        unlink(FIFO_NAME);
        Log("remove fifo success", NOTICE) << endl;
    }
};

int OpenFifo(string pathname, int flags)
{
    int fd = open(pathname.c_str(), flags);
    assert(fd >= 0);
    return fd;
}

void CloseFifo(int fd)
{
    close(fd);
}

void Wait(int fd)
{
    Log("等待中...", NOTICE) << endl;
    uint32_t tmp = 0;
    ssize_t s = read(fd, &tmp, sizeof(uint32_t));
    assert(s == sizeof(uint32_t));
    (void)s;
}

void Signal(int fd)
{
    uint32_t tmp = 1;
    ssize_t s = write(fd, &tmp, sizeof(uint32_t)); // 写什么不重要，主要是通过管道来进行访问控制
    assert(s == sizeof(uint32_t));
    (void)s;
    Log("唤醒中", NOTICE) << endl;
}