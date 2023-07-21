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

//1.�����дһ��Heap�����ݽṹ����������
//2.��O(N)�Ŀռ临�Ӷ�
//���Բ�̫��
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

//���� -- �����
//���� -- ��С��
void Heapsort(HPDataType* a, int size)
{
	//���ѷ�ʽ1:O(N*logN)
	//for (int i = 1; i < size; i++)
	//{
	//	//ÿһ�����ϵ������Կ�����һ�β���Ĺ���
	//	AdjustUp(a, i);
	//}

	//���ѷ�ʽ2:O(N)
	//�����һ����Ҷ�ӽڵ㿪ʼ,���µ���
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}

	//���� O(N*logN)
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

//void TestHeapSort()  //������
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
	//1.���� -- ��a��ǰk��Ԫ�ؽ���
	int* kMinHeap = (int*)malloc(sizeof(int) * k);
	assert(kMinHeap);

	//��a��ǰk��Ԫ�ؿ�����kMinHeap��
	for (int i = 0; i < k; i++)
	{
		kMinHeap[i] = a[i];
	}

	//����
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kMinHeap, k, i);
	}

	//2.��ʣ��n-k��Ԫ�����κͶѶ�Ԫ�����Ƚ�,�����������滻
	for (int i = k; i < n; i++)
	{
		//�Ƚ�&�滻
		if (a[i] > kMinHeap[0])
		{
			kMinHeap[0] = a[i];

			//�ѣ����Ե���
			AdjustDown(kMinHeap, k, 0);
		}
	}

	//������Ҫ��/����ֱ�ӵ��ö����򼴿�
	//......

	//�滻��ɣ���ӡ
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kMinHeap[i]);
	}
	printf("\n");
}

//�˴������������
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