#include <stdio.h>
#include <unistd.h>

int g_val = 100;

int main()
{
	pid_t id = fork();
	if(id == 0)
	{
		g_val = 200;
		printf("I am child,PID:%d,PPID:%d,g_val = %d, %p\n", getpid(), getppid(), g_val, &g_val);
	}
	else
	{

		printf("I am parent,PID:%d,PPID:%d,g_val = %d, %p\n", getpid(), getppid(), g_val, &g_val);
	}

	return 0;
}
