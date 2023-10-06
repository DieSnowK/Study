#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	std::cout << "I am parent process! -- PID:" << getpid() << std::endl;
	pid_t ret = fork();
	// 变成两个进程，一个是父进程，一个是子进程
	if(ret < 0)
	{
		perror("fork failed");
		return 1;
	}
	else if (ret > 0)
	{
		// parent process
		std::cout << "parent:" << getpid() << ":is sleeping" << std::endl;
		sleep(30);
	}
	else
	{
		// child process
		std::cout << "child:" << getpid() << ":is sleeping" << std::endl;
		sleep(5);
		exit(0);
	}
	//while(1)
	//{
	//	std::cout << "Hello SnowK" << std::endl;
	//	std::cout << "PID:" << getpid() << " PPID:" << getppid() << std::endl << std::endl;
	//	sleep(1);
		
	//}
	return 0;
}

