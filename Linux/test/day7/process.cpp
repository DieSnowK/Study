#include <iostream>
#include <unistd.h>

int main()
{

	std::cout << "I am parent process! -- PID:" << getpid() << std::endl;
	fork();
	// 变成两个进程，一个是父进程，一个是子进程
	//while(1)
	//{
		std::cout << "Hello SnowK" << std::endl;
		std::cout << "PID:" << getpid() << " PPID:" << getppid() << std::endl << std::endl;
		sleep(1);
		
	//}
	return 0;
}

