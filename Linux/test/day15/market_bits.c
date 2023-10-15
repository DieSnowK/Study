#include <stdio.h>

#define ONE 0x1 // 0000 0001
#define TWO 0x2 // 0000 0010
#define THREE 0x4 // 0000 0100

void show(int flags)
{
	if(flags & ONE)
	{
		printf("one\n");
	}
	if(flags & TWO)
	{
		printf("two\n");
	}
	if(flags & THREE)
	{
		printf("three\n");
	}
}

int main()
{
	show(ONE);
	show(TWO);
	show(ONE|TWO); // 0000 0001|0000 0010 = 0000 0011
	show(ONE|TWO|THREE);
	show(ONE|THREE);

	return 0;
}
