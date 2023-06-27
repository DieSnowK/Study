#include "Stack.h"

int main()
{
	Stack ST;
	StackInit(&ST);
	StackPush(&ST, 1);
	StackPush(&ST, 2);
	StackPush(&ST, 3);
	StackPush(&ST, 4);
	StackPush(&ST, 5);
	StackPush(&ST, 6);

	while (!isStackEmpty(&ST))
	{
		printf("%d ", StackTop(&ST));
		StackPop(&ST);
	}
	printf("\n");

	StackDestroy(&ST);
	return 0;
}