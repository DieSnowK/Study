#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct MyFile
{
	int fd;
	char buffer[1024];
	int end; // 当前缓冲区的结尾
} MyFile;

MyFile* fopen_(const char* pathname, const char* mode)
{
	assert(pathname);
	assert(mode);

	MyFile *fp = NULL; // 初始先置空
	
	if(strcmp(mode, "r") == 0)
	{

	}
	else if(strcmp(mode, "r+") == 0)
	{

	}
	else if(strcmp(mode, "w") == 0)
	{
		int fd = open(pathname, O_WRONLY|O_CREAT|O_TRUNC, 0666);
		if(fd >= 0)
		{
			fp = (MyFile*)malloc(sizeof(MyFile));
			memset(fp, 0, sizeof(MyFile)); // 将MyFile空间全部置0
			fp->fd = fd;
		}
	}
	else if(strcmp(mode, "w+") == 0)
	{

	}
	else if(strcmp(mode, "a") == 0)
	{

	}
	else if(strcmp(mode, "a+") == 0)
	{

	}
	else
	{
		// do nothing
	}

	return fp;
}

void fputs_(const char *msg, MyFile *fp)
{
	assert(msg);
	assert(fp);

	strcpy(fp->buffer + fp->end, msg); // 若第一次buffer里存了abcde\0
									   // 第二次要把\0覆盖掉，紧接着往后面存
	fp->end += strlen(msg);
	
	// 暂时还没有刷新，刷新策略 -->  通过执行C标准库中的代码逻辑，来完成刷新动作
	if(fp->fd == 0)
	{
		// 标准输入
	}
	else if(fp->fd == 1)
	{
		// 标准输出 - 行刷新
		if(fp->buffer[fp->end-1] == '\n')
		{
			write(fp->fd, fp->buffer, fp->end);
			fp->end = 0;
		}
	}
	else if(fp->fd == 2)
	{
		// 标准错误
	}
	else
	{
		// 其他，不做刷新策略
	}

}

void fflush_(MyFile *fp)
{
	assert(fp);

	if(fp->end != 0)
	{
		write(fp->fd, fp->buffer, fp->end); // 暂且认为是刷新了，其实是把数据刷新到了内核
		syncfs(fp->fd); // 将数据写入到磁盘
		fp->end = 0;
	}
}

void fclose_(MyFile *fp)
{
	assert(fp);
	fflush_(fp);
	close(fp->fd);
	free(fp);
}


int main()
{
	MyFile *fp = fopen_("log.txt", "w");
	if(fp == NULL)
	{
		printf("open file error");
		return 1;
	}
	
	fputs_("hello world\n", fp);
	
	// fork();

	fclose_(fp);
	return 0;
}
