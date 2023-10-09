#include <iostream>
#include <unistd.h>

int main()
{
	pid_t ret = fork();
	if(ret < 0)
	{
		perror("fork failed");
		return 1;
	}
	else if(ret == 0)
	{
		// child process
		std::cout << "I am child, PID:" << getpid() << std::endl;
		sleep(30);
	}
	else
	{
		// parent process
		std::cout << "I am parent, PID:" << getpid() << std::endl;
		sleep(10);
		exit(0);
	}
	return 0;
}

