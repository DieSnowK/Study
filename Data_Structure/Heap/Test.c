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

void TestHeapSort()  //������
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