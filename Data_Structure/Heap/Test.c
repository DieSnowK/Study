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
//从这里接着想
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

void TestHeapSort()  //堆排序
{
	Heap hp;
	HeapInit(&hp);

	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };



	HeapPrint(&hp);

	HeapDestroy(&hp);
}

int main()
{
	//Test();
	TestHeapSort();

	return 0;
}