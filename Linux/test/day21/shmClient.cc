#include "comm.hpp"

int main()
{
    // 1.创建公共的key值
    key_t k = ftok(PATH_NAME, PROJ_ID);
    if(k < 0)
    {
        Log("create key failed", ERROR) << " client key : " << k << endl;
        exit(1);
    }
    Log("create key done", DEBUG) << " client key : " << k << endl;

    // 2.获取共享内存
    int shmid = shmget(k, SHM_SIZE, 0);
    if(shmid < 0)
    {
        Log("create shm failed", ERROR) << " client key : " << k << endl;
        exit(2);
    }
    Log("create shm success", ERROR) << " client key : " << k << endl;

#ifdef DEBUGV
    sleep(10);
#endif

    // 3.将指定的共享内存，挂接到自己的地址空间
    char *shmaddr = (char *)shmat(shmid, nullptr, 0);
    if (shmaddr == nullptr)
    {
        Log("attach shm failed", ERROR) << " client key : " << k << endl;
        exit(3);
    }
    Log("attach shm success", DEBUG) << " client key : " << k << endl;

#ifdef DEBUGV
    sleep(10);
#endif

    // 通信逻辑
    int fd = OpenFifo(FIFO_NAME, WRITE);
    while(true)
    {
        ssize_t s = read(0, shmaddr, SHM_SIZE - 1); // 从键盘读数据，存入shm
        if (s > 0)
        {
            shmaddr[s - 1] = 0; // 最后会键入\n，把\n替换成\0
            Signal(fd); // 已经获取到数据，唤醒服务端
            if(strcmp(shmaddr, "quit") == 0)
            {
                break;
            }
        }
    }
    CloseFifo(fd);

    // 4.将指定的共享内存，从自己的地址空间中去关联
    int n = shmdt(shmaddr);
    assert(n != -1);
    Log("detach shm success", DEBUG) << " client key : " << k << endl;

#ifdef DEBUGV
    sleep(10);
#endif

    // client不需要shmctl删除
    return 0;
}