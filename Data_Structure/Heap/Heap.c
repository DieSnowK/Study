#include "Heap.h"

void HeapPrint(Heap* php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ",php->a[i]);
	}
	printf("\n");
}

void HeapInit(Heap* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)  //child == 0ʱ,�Ѿ��Ǹ��ڵ�
	{				  //������parent >= 0,��Ϊparent��Ȼ���ڵ���0
		if (a[child] < a[parent])
		{
			//��������ֵ
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;  //����С/���,����Ҫ����
		}
	}
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//ѡ�����Һ����н�С/���
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child += 1;
		}

		//���Ӹ����ױȽ�
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;  //����С/���,����Ҫ����
		}
	}
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//�������
	if (php->size == php->capacity)
	{
		php->capacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * php->capacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		php->a = tmp;
	}

	php->a[php->size] = x;
	php->size++;

	//���ϵ���
	AdjustUp(php->a, php->size - 1);
}

void HeapPop(Heap* php)  //�ýӿ�ɾ���Ѷ�Ԫ��,�����ƻ�ԭ���ѵĽṹ
{
	assert(php);
	assert(php->size > 0);

	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//���µ���
	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

bool isHeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}

int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}