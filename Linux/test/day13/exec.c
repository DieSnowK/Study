#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM 16

int main()
{
	char const *_env[NUM] = 
	{
		"SnowK=666",
		NULL
	};

	pid_t id = fork();
	if (id == 0)
	{
		// child
		printf("child start,PID:%d\n", getpid());
		
		char const *_argv[NUM] = 
		{
			"ls",
			"-l",
			"-a",
			"--color=auto",
			NULL
		};
		
		//execl("/usr/bin/ls", "ls", "-l", "-a", NULL);
		// execv("/usr/bin/ls", _argv);
		// execlp("ls", "ls", "-al", "--color=auto", NULL);
		// execvp("ls", _argv);
		execle("./myfile", "myfile", "-a", NULL,  _env);
		exit(6);
	}
	else
	{
		// parent
		printf("parent,PID:%d\n", getpid());

		int status = 0;
		pid_t ret = waitpid(-1, &status, 0); // 阻塞等待，一定是子进程运行完毕，父进程获取之后才推出
		
		if(id > 0)
		{
			printf("wait success, exit code:%d\n", WEXITSTATUS(status));
		}
	}
	return 0;
}

