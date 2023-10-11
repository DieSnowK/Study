#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM 1024
#define SIZE 32
#define SEP " "

char cmd_line[NUM] = {0}; // 保存用户键入的命令行字符串
char *g_argv[SIZE] = {NULL}; // 保存解析之后的字符串
char g_valbf[NUM]; // buffer，用来存储环境变量

// shell运行原理 --> shell解析命令&&等待子进程，子进程执行命令
int main()
{
	// 命令行解释器，是一个常驻内存的进程，不退出
	while(1)
	{
		// 0.打印提示信息
		printf("[SnowK@localhost minishell]# ");
		fflush(stdout); // 手动刷新缓冲区

		// 1.读取命令
		if(fgets(cmd_line, sizeof cmd_line, stdin) == NULL)
		{
			// 读取失败，重新尝试读取
			continue;
		}
		cmd_line[strlen(cmd_line) - 1] = '\0'; // 键入类似"ls -l\n"，但是没有\0，所以手动置换
											   
		// 2.解析命令:"ls -l -a" --> "ls" "-l" "-a"
		int index = 1;
		g_argv[0] = strtok(cmd_line, SEP); // 第一次调用，要传入原始字符串	

		// 为实现方便，为ls添加颜色和类似ll的别名，就做特殊处理了
		// 有兴趣的小伙伴可以自己实现更智能的做法
		if(strcmp(g_argv[0], "ls") == 0)
		{
			g_argv[index++] = "--color=auto";
		}
		if(strcmp(g_argv[0], "ll") == 0)
		{
			g_argv[0] = "ls";
			g_argv[index++] = "-l";
			g_argv[index++] = "--color=auto";
		}
		// export MYVAL=SnowK
		if(strcmp(g_argv[0], "export") == 0 && g_argv[1] != NULL)
		{
			strcpy(g_valbf, g_argv[1]);
			putenv(g_valbf);
			continue;

			// 思考为什么不能用下面的代码？
			// putenv(g_argv[1]);
			// strtok裁剪出来的子字符串，是用一个指针指向子字符串的
			// 并不是单独拿出来的，每次一次循环，会覆盖原来的cmd_line
			// 则g_argv中的各个子字符串就指向了错误的字符串
			// 如:g_argv[1]存的地址，依然是cmd_line中的地址
		}
		while(g_argv[index++] = strtok(NULL, SEP)); // 第二次，如果还要继续解析原字符串，传NULL
		
		// 2.5 内置命令，即让父进程shell自己执行的命令
		// 内置命令本质就是shell里的一个函数调用
		if(strcmp(g_argv[0], "cd") == 0)
		{
			if(g_argv[1] != NULL)
			{
				chdir(g_argv[1]); // chdir 系统调用接口 --> cd path
				continue;
			}
		}

		// 3.fork()，派送子进程
		pid_t id = fork();
		if(id == 0)
		{
			// child
			printf("child start\n");
			printf("----------------------------\n");
			execvp(g_argv[0], g_argv);
			exit(1);
		}
		
		// parent
		int status = 0;
		int ret = waitpid(id, &status, 0);
		if(ret > 0)
		{
			printf("child success, exit code:%d\n", WEXITSTATUS(status));
			printf("----------------------------\n");
		}
	}

	return 0;
}
