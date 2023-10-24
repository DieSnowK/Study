#include <iostream>
#include <cassert>
#include <signal.h>

using namespace std;

static void catchSig(int sig)
{
    cout << "捕获到一个信号: " << sig << endl;
    int count = 20;
    while(count--)
    {
        sleep(1);
    }
}

static void showPending(sigset_t &set)
{
    for (int sig = 1; sig <= 31; sig++)
    {
        if(sigismember(&set, sig))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << endl;
}

static void blockSig(int sig)
{
    sigset_t bset;
    sigemptyset(&bset);
    sigaddset(&bset, sig);
    int n = sigprocmask(SIG_BLOCK, &bset, nullptr);
    assert(n == 0);
    (void)n;
}

// 6.如果不想等待子进程，并且还想让子进程退出之后，自动释放僵尸子进程
// int main()
// {
//     // OS默认对SIGCHLD是忽略的
//     signal(SIGCHLD, SIG_IGN); // 手动设置对子进程进行忽略，其效果和OS默认忽略是有区别的，算是一个特例

//     if(fork() == 0)
//     {
//         cout << "child: " << getpid() << endl;
//         sleep(5);
//         exit(0);
//     }

//     while(true)
//     {
//         cout << "parent: " << getpid() << "执行自己的任务" << endl;
//         sleep(1);
//     }
//     return 0;
// }

// 5.证明子进程退出，会向父进程发送信号
// int main()
// {
//     signal(SIGCHLD, catchSig);
//     if(fork() == 0)
//     {
//         cout << "child pid: " << getpid() << endl;
//         sleep(100);
//         exit(0);
//     }

//     while(true)
//     {
//         sleep(1);
//     }

//     return 0;
// }

// 4.sigaction使用
// int main()
// {
//     // 内核数据类型
//     struct sigaction act, oact;
//     act.sa_flags = 0;
//     sigemptyset(&act.sa_mask);
//     act.sa_handler = catchSig;

//     sigaddset(&act.sa_mask, 3);
//     sigaddset(&act.sa_mask, 4);
//     sigaddset(&act.sa_mask, 5);

//     // 设置进当前调用进程的PCB中
//     sigaction(2, &act, &oact);
    
//     return 0;
// }

// 3.
// int main()
// {
//     for (int sig = 1; sig <= 31; sig++)
//     {
//         blockSig(sig);
//     }

//     sigset_t pending;
//     while(true)
//     {
//         sigpending(&pending);
//         showPending(pending);
//         sleep(1);
//     }

//     return 0;
// }

// 2. sigset_t相关使用
// int main()
// {
//     // 0.方便测试，捕捉2号信号，不要退出
//     signal(2, catchSig);

//     // 1.定义信号集对象
//     sigset_t bset, obset;
//     sigset_t pending;

//     // 2.初始化
//     sigemptyset(&bset);
//     sigemptyset(&obset);
//     sigemptyset(&pending);

//     // 3.添加要进行屏蔽的信号
//     sigaddset(&bset, 2);

//     // 4.设置set到内核中对应的进程内部
//     int n = sigprocmask(SIG_BLOCK, &bset, &obset);
//     assert(n == 0);
//     (void)n; // release下，assert失效，为了方式未使用变量警告，作此处理

//     cout << "block 2号信号成功... PID: " << getpid() << endl;

//     // 5.重复打印当前进程的pending信号集
//     int count = 0;
//     while(true)
//     {
//         // 5.1获取当前进程的pending信号集
//         sigpending(&pending);

//         // 5.2显示pending信号集中没有被递达的信号
//         showPending(pending);
//         sleep(1);

//         count++;
//         if (count == 10)
//         {
//             // 默认情况下，恢复对于2号信号的block的时候，确实会进行递达
//             // 但是2号信号的默认处理动作是终止进程
//             // 对2号进程进行捕捉，好观察现象
//             cout << "解除对2号信号的block" << endl;
//             int n = sigprocmask(SIG_UNBLOCK, &bset, nullptr);
//             assert(n == 0);
//             (void)n;
//         }
//     }

//     return 0;
// }

// 1.
// int main()
// {
//     for (int sig = 1; sig <= 31; sig++)
//     {
//         signal(sig, catchSig);
//     }

//     while(true)
//     {
//         sleep(1);
//     }
//     return 0;
// }