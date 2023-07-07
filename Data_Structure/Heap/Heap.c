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
	while (child > 0)  //child == 0时,已经是根节点
	{				  //不能是parent >= 0,因为parent必然大于等于0
		if (a[child] < a[parent])
		{
			//交换父子值
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;  //满足小/大堆,不需要调整
		}
	}
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//选出左右孩子中较小/大的
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child += 1;
		}

		//孩子跟父亲比较
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;  //满足小/大堆,不需要调整
		}
	}
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//检测扩容
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

	//向上调整
	AdjustUp(php->a, php->size - 1);
}

void HeapPop(Heap* php)  //该接口删除堆顶元素,不能破坏原本堆的结构
{
	assert(php);
	assert(php->size > 0);

	//交换堆顶元素和最后一个元素
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//向下调整
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