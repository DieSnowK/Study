#include <stdio.h>

int AddTime(int time)
{
	int ret = 0;

	for(int i = 0; i <= time; i++)
	{
		ret +=i;
	}

	return ret;
}

int main()
{

	int time = 100;
	int result = AddTime(time);

	printf("%d\n", result);

	return 0;
}
