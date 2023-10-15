#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	// 先试试库函数fopen
	// FILE* fp = fopen("log.txt", "w+");
	// const char *s = "hello fputs\n";
	// const char *s1 = "hello fprintf\n";
	// const char *s2 = "hello fwrite\n";
	// fputs(s, fp);
	// fprintf(fp, "%s", s1);
	// fwrite(s2, strlen(s2), 1, fp); // 不要+1,\0结尾是C语言的规定，文件不需要遵守  
	// 							   // -->  文件保存的是有效数据
	// fclose(fp);

	// fopen("log.txt", "r");
	// char buffer[1024];
	// while(fgets(buffer, sizeof buffer, fp) != NULL)
	// {
	// 	printf("%s", buffer);
	// }
	// fclose(fp);

	// 再试试系统调用open
	// int fd = open("log.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
	// if(fd < 0)
	// {
	// 	perror("open");
	// 	return 1;
	// }
	
	// const char *s = "hello write\n";
	// write(fd, s, strlen(s));
	// printf("%d\n", fd);
	// close(fd);

	// fd = open("log.txt", O_RDONLY);
	// char buffer[1024] = {0};
	// read(fd, buffer, sizeof buffer);
	// printf("%s", buffer);
	
	// 试试重定向
	// close(1);
	// int fd = open("log.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
	// if(fd < 0)
	// {
	// 	perror("open");
	// 	return 1;
	// }

	// printf("hello close(!)\n");

	// 试试dup2()重定向
	// oldfd(fd) --> newfd(stdout?) |
	// 这里实验输出重定向
	// int fd = open("log.txt", O_WRONLY|O_TRUNC|O_CREAT, 0666);
	// dup2(fd, 1);

	// const char *s = "who are you?\n stdout or log.txt?\n";
	// fprintf(stdout, "%s", s);
	// close(fd);
	
	// 这里实验追加重定向
	// int fd = open("log.txt", O_WRONLY|O_APPEND|O_CREAT, 0666);
	// dup2(fd,1);

	// const char *s = "who are you?\n stdout or log.txt?\n";
	// fprintf(stdout, "%s", s);
	// close(fd);

	// 思考一下问题，为什么fork之后，库函数内容会被打印两次？
	printf("hello printf\n");
	fprintf(stdout, "hello fprintf\n");
	const char *s = "hello fputs\n";
	fputs(s, stdout);

	const char *s1 = "hello write\n";
	write(1, s1, strlen(s1));

	fork();

	return 0;
}
