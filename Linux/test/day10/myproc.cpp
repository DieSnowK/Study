#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>

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
		// parent process
		printf("I am parent, PID:%d, PPID:%d\n", getpid(), getppid());

		int status = 0;
		//pid_t ret = wait(NULL); // 参数NULL表示父进程以阻塞式等待
		pid_t ret = waitpid(id, &status, 0); // 阻塞式等待
		if(ret > 0)
		{

			//printf("wait child success!"); 
			printf("wait child success! ret:%d, SIGNAL:%d, EXIT:%d\n", ret,
				   status & 0x7F, (status >> 8) & 0xFF);
		}
	}

	return 0;
}
