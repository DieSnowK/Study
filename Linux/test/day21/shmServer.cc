#include "comm.hpp"

// 程序加载的时候，自动构建全局变量，调用该类的构造函数 --> 创建管道文件
// 程序退出的时候，全局变量析构，自动删除管道文件
Init init;

string TransToHex(key_t k)
{
    char buffer[32];
    snprintf(buffer, sizeof buffer, "0x%x", k);
    return buffer;
}

int main()
{
    // 1.创建公共的key值
    key_t k = ftok(PATH_NAME, PROJ_ID);
    assert(k != -1);
    Log("create key done ", DEBUG) << "server key：" << TransToHex(k) << endl;

    // 2.创建共享内存 -- 建议创建一个全新的共享内存 -- 通信的发起者
    int shmid = shmget(k, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if(shmid == -1)
    {
        perror("shmget");
        exit(1);
    }
    Log("create shm done ", DEBUG) << "shmid：" << shmid << endl;

#ifdef DEBUGV
    sleep(10);
#endif

    // 3.将指定的共享内存，挂接到自己的地址空间
    char *shmaddr = (char*)shmat(shmid, nullptr, 0);
    Log("attach shm done ", DEBUG) << "shmid：" << shmid << endl;

#ifdef DEBUGV
    sleep(10);
#endif

    // 这里就是通信逻辑，将共享内存看作一个大数组 -> char buffer[SHM_SIZE]
    // 这里添加一定的访问控制(依赖管道)
    int fd = OpenFifo(FIFO_NAME, READ);
    while(true)
    {
        Wait(fd); // 写慢，读快，管道没有数据的时候，读必须等待

        cout << shmaddr << endl;
        if(strcmp(shmaddr, "quit") == 0)
        {
            break;
        }
    }

    // 4.将指定的共享内存，从自己的地址空间去关联
    int n = shmdt(shmaddr);
    assert(n != -1);
    (void)n;
    Log("detach shm done ", DEBUG) << "shmid：" << shmid << endl;

#ifdef DEBUGV
    sleep(10);
#endif

    // 5.删除共享内存，IPC_RMID即便是有进程和当下的shm挂接，依旧删除共享内存
    n = shmctl(shmid, IPC_RMID, nullptr);
    assert(n != -1);
    (void)n;
    Log("delete shm done ", DEBUG) << "shmid：" << shmid << endl;

    CloseFifo(fd);

    return 0;
}