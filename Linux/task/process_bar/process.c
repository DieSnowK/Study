#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUM 102

int main()
{
	char bar[NUM] = {0};
	const char *lable = "|/-\\";
	int time = 0;
	
	while(time <= 100)
	{
		printf("[%-100s][%d%%] %c\r", bar, time, lable[time%4] );
		bar[time++] = '=';
		fflush(stdout);
		usleep(50000);
	}
	printf("\n");
	
	return 0;
}
