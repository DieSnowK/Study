#include "SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);

	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLDestroy(SL* ps)
{
	assert(ps);

	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}

void SLPrint(SL* ps)
{
	assert(ps);

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}

	printf("\n");
}

void SLCheckCapacity(SL* ps)
{
	assert(ps);

	//检查容量空间，满了扩容
	if (ps->size == ps->capacity)
	{
		ps->capacity = ps->capacity == 0 ? 4 : ps->capacity * 2; //最大容量扩容
		SLDataType* tmp = realloc(ps->arr, ps->capacity * sizeof(SLDataType));
		if (NULL == tmp)
		{
			perror("realloc:");
			exit(1);
		}
		ps->arr = tmp;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);

	ps->arr[ps->size] = x;
	ps->size++;

	//SLInsert(ps, ps->size, x); //以上代码可以用这个封装替换了
}

void SLPopBack(SL* ps)
{
	assert(ps);
	//暴力检查 - 适用于调试阶段
	assert(ps->size > 0);

	//温柔检查 - 适用于和用户交互使用
	//if (0 == ps->size)
	//{
	//	printf("SeqList is empty\n");
	//	return;
	//}
	
	ps->size--;

	SLErase(ps, ps->size - 1); //以上代码可以用这个封装替换了
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	//挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->arr[end + 1] = ps->arr[end];
		end--;
	}

	ps->arr[0] = x;
	ps->size++;

	//SLInsert(ps, 0, x); //以上代码可以用这个封装替换了
}

void SLPopFront(SL* ps)
{
	int begin = 1;
	while (begin < ps->size)
	{
		ps->arr[begin - 1] = ps->arr[begin];
		begin++;
	}

	ps->size--;

	//SLErase(ps, 0); //以上代码可以用这个封装替换了
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size); //检验位置合法性

	SLCheckCapacity(ps);

	//挪动数据
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->arr[end + 1] = ps->arr[end];
		end--;
	}

	ps->arr[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//挪动数据
	int begin = pos;
	while (begin < ps->size - 1)
	{
		//后面的数据往前搬
		ps->arr[begin] = ps->arr[begin + 1];
		begin++;
	}

	ps->size--;
}

int SLSearch(SL* ps, SLDataType x)
{
	assert(ps);
	
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->arr[pos] = x;
}