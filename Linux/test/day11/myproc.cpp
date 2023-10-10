#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>

typedef void (*func)(); // 函数指针类型
std::vector<func> funcs; // 函数指针数组

void fun1()
{
	std::cout << "This is func1" << std::endl;
}

void fun2()
{

	std::cout << "This is func2" << std::endl;
}

// 设置对应的方法回调
// 以后想让父进程闲了执行任何方法的时候，只需要向Load里注册，就可以让父进程执行对应的方法
void Load()
{
	funcs.push_back(fun1);
	funcs.push_back(fun2);
}

int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		exit(1); // 标识进程运行完毕，结果不正确
	}
	else if(id == 0)
	{
		// child process
		int cnt = 5;
		while(cnt)
		{
			printf("I am child, cnt:%d, PID:%d, PPID:%d\n", cnt, getpid(), getppid());
			sleep(1);
			cnt--;
		}

		exit(66);
	}
	else
	{
		int quit = 0;
		while(!quit)
		{
			// 轮询检测方案
			int status = 0;
			pid_t ret = waitpid(-1, &status, WNOHANG); // 非阻塞等待，父进程可做其他任务
			if(ret > 0)
			{
				// 等待成功&&子进程退出
				printf("等待子进程退出成功，退出码:%d\n", WEXITSTATUS(status));
				quit = 1;
			}
			else if(ret == 0)
			{
				// 等待成功&&子进程未推出
				printf("子进程尚未退出，可进行其他操作\n");
				if(funcs.empty())
				{
					Load();
				}

				for(auto fun : funcs)
				{
					// 执行这里的其他操作
					fun();
				}
				
			}
			else
			{
				// 等待失败
				printf("wait failed\n");
				quit = 1;
			}

			sleep(1);
		}
	}

	return 0;
}
