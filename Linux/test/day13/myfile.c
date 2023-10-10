#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("can not execute!\n");
		exit(1);
	}

	printf("get PATH：SnowK:%s\n", getenv("SnowK"));

	if(strcmp(argv[1], "-a") == 0)
	{
		printf("hello -a\n");
	}
	else
	{
		printf("default\n");
	}

	return 0;
}
