#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->top = ps->capacity = 0;
}

void StackPush(Stack* ps ,STDataType x)
{
	assert(ps);

	//检测扩容
	if (ps->top == ps->capacity)
	{
		ps->capacity = 0 ? 4: ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		ps->a = tmp;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!isStackEmpty(ps));

	ps->top--;  //访问不到这个数据即可视为删除
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!isStackEmpty(ps));

	return ps->a[ps->top - 1];
}

bool isStackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}