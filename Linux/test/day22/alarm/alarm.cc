#include <iostream>
#include <vector>
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

typedef function<void()> func;
vector<func> callbacks;
uint64_t count = 0;

void catchsig(int sig)
{
    for(const auto &f : callbacks)
    {
        f();
    }
    cout << endl;

    alarm(1); // 执行特性方法后，重新设定闹钟
}

//////////////////////////////////////////////////////////////////////////////////////
// 信号异常后的执行方法
void showCount()
{
    cout << "final count : " << count << endl;
}

void showLog()
{
    cout << "这个是日志功能" << endl;
}

void logUser()
{
    if(fork() == 0)
    {
        execl("/usr/bin/who", "who", nullptr);
        exit(1);
    }
    wait(nullptr);
}
//////////////////////////////////////////////////////////////////////////////////////

int main()
{
    signal(SIGALRM, catchsig); // 捕获特定的信号，执行自定的方法
    alarm(1);

    callbacks.push_back(showCount);
    callbacks.push_back(showLog);
    callbacks.push_back(logUser);

    while(true)
    {
        count++;
    }

    return 0;
}