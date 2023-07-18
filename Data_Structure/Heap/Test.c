#include "Heap.h"

void Test()
{
	Heap hp;
	HeapInit(&hp);
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		HeapPush(&hp, arr[i]);
	}

	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

//1.你得先写一个Heap的数据结构，反而复杂
//2.有O(N)的空间复杂度
//所以不太好
void HeapSort(HPDataType* a, int size)
{
	Heap hp;
	HeapInit(&hp);

	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, a[i]);
	}

	int i = 0;
	while (!isHeapEmpty(&hp))
	{
		a[i++] = HeapTop(&hp);
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

//升序 -- 建大堆
//降序 -- 建小堆
void Heapsort(HPDataType* a, int size)
{
	//建堆方式1:O(N*logN)
	//for (int i = 1; i < size; i++)
	//{
	//	//每一次向上调整可以看成是一次插入的过程
	//	AdjustUp(a, i);
	//}

	//建堆方式2:O(N)
	//从最后一个非叶子节点开始,向下调整
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}

	//排序 O(N*logN)
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void TestHeapSort()  //堆排序
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	Heapsort(arr, sizeof(arr) / sizeof(arr[0]));

	for(int i = 0;i<sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	//Test();
	TestHeapSort();

	return 0;
}