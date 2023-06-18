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

	//��������ռ䣬��������
	if (ps->size == ps->capacity)
	{
		ps->capacity = ps->capacity == 0 ? 4 : ps->capacity * 2; //�����������
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

	//SLInsert(ps, ps->size, x); //���ϴ�������������װ�滻��
}

void SLPopBack(SL* ps)
{
	assert(ps);
	//������� - �����ڵ��Խ׶�
	assert(ps->size > 0);

	//������ - �����ں��û�����ʹ��
	//if (0 == ps->size)
	//{
	//	printf("SeqList is empty\n");
	//	return;
	//}
	
	ps->size--;

	SLErase(ps, ps->size - 1); //���ϴ�������������װ�滻��
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	//Ų������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->arr[end + 1] = ps->arr[end];
		end--;
	}

	ps->arr[0] = x;
	ps->size++;

	//SLInsert(ps, 0, x); //���ϴ�������������װ�滻��
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

	//SLErase(ps, 0); //���ϴ�������������װ�滻��
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size); //����λ�úϷ���

	SLCheckCapacity(ps);

	//Ų������
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

	//Ų������
	int begin = pos;
	while (begin < ps->size - 1)
	{
		//�����������ǰ��
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