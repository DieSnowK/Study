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
//void HeapSort(HPDataType* a, int size)
//{
//	Heap hp;
//	HeapInit(&hp);
//
//	for (int i = 0; i < size; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	int i = 0;
//	while (!isHeapEmpty(&hp))
//	{
//		a[i++] = HeapTop(&hp);
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}

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

//void TestHeapSort()  //堆排序
//{
//	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	Heapsort(arr, sizeof(arr) / sizeof(arr[0]));
//
//	for(int i = 0;i<sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}


void PrintTopK(int* a, int n, int k)
{
	//1.建堆 -- 用a中前k个元素建堆
	int* kMinHeap = (int*)malloc(sizeof(int) * k);
	assert(kMinHeap);

	//将a中前k个元素拷贝到kMinHeap中
	for (int i = 0; i < k; i++)
	{
		kMinHeap[i] = a[i];
	}

	//建堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kMinHeap, k, i);
	}

	//2.将剩余n-k个元素依次和堆顶元素做比较,不满规则则替换
	for (int i = k; i < n; i++)
	{
		//比较&替换
		if (a[i] > kMinHeap[0])
		{
			kMinHeap[0] = a[i];

			//堆，所以调整
			AdjustDown(kMinHeap, k, 0);
		}
	}

	//倘若需要降/升序，直接调用堆排序即可
	//......

	//替换完成，打印
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kMinHeap[i]);
	}
	printf("\n");
}

//此处测试最大问题
void TestTopK()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[120] = 1000000 + 5;
	a[99] = 1000000 + 6;
	a[0] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

int main()
{
	//Test();
	//TestHeapSort();
	TestTopK();

	return 0;
}