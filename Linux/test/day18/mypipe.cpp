#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

// 为什么不定义全局buffer来进行通信？ -->  因为有写时拷贝存在，无法更改通信

int main()
{
    // 1.创建管道
    int pipefd[2] = {0};
    int n = pipe(pipefd);
    assert(n == 0);
    (void)n; // 因为n不会用到，此举为了防止编译时编译器因从未使用该变量而大量警告

#ifdef DEBUG
    cout << "pipefd[0]:" << pipefd[0] << endl;
    cout << "pipefd[1]:" << pipefd[1] << endl;
#endif

    // 2.创建子进程
    pid_t id = fork();
    assert(id != -1);

    if (id == 0)
    {
        // child - read
        // 3.构建单向通信的信道
        // 3.1 关闭父进程不需要的fd
        close(pipefd[1]);
        char buffer[1024] = {0};

        while(true)
        {
            // 写入的一方fd没有关闭，如果有数据，就读，没有数据就等
            // 写入的一方fd关闭，读取的一方，read会返回0，表示读到了文件的结尾
            ssize_t s = read(pipefd[0], buffer, sizeof(buffer) - 1);
            if(s > 0)
            {
                // buffer[s] = 0; // 填充结尾\0，但初始化时都初始化了0，此步省略
                cout << "child get a message[" << getpid() << "] Parent# " << buffer << endl;
            }
            else if(s == 0)
            {
                cout << "writer quit, follow him :P" << endl;
                break;
            }
        }

        // close(pipefd[0]); // 这个位置可写可不写，反正下一步进程就退出
        exit(1);
    }

    // parent - write
    // 3.构建单向通信的信道
    // 3.1 关闭父进程不需要的fd
    close(pipefd[0]);

    string msg = "我是父进程，我正在发消息";
    int count = 0;
    char send_buffer[1024];

    while(true)
    {
        // 3.2 构建一个变化的字符串
        snprintf(send_buffer, sizeof(send_buffer), 
        "%s[%d]:%d", msg.c_str(), getpid(), count++); // \0会自动追加到写入的内容之后

        // 3.3 写入
        write(pipefd[1], send_buffer, strlen(send_buffer));

        // 3.4 故意sleep
        sleep(1);

        if(count == 5)
        {
            cout << "writer quie :P" << endl;
            break;
        }
    }

    close(pipefd[1]);
    pid_t ret = waitpid(id, nullptr, 0);
    assert(ret > 0);
    (void)ret;

    return 0;
}