#include "Sort.h"

PrintArray(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������Ϊ��

void InsertSort(int* a, int n)
{
	assert(a);

	//��[0,end]���򣬽�end+1λ�õ�ֵ���룬��������
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (tmp < a[end])
			{
				//Ų������
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				//�ҵ�tmp > a[end] ��λ��
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	//gap > 1 --> Ԥ����
	//gap = 1 --> ֱ�Ӳ�������
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;  //+1��Ϊ�˱�֤���gap����ȡ��1

		for (int j = 0; j < gap; j++)  //j�������
		{
			//һ��Ԥ����
			for (int i = j; i < n - gap; i += gap)
			{
				//һ��Ԥ�����е�һ�β�������
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}

void SelectSort(int* a, int n)
{

}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDwon(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		// ѡ�����Һ�����С/����Ǹ�
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		// ���Ӹ����ױȽ�
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// ���� -- ��С��
void HeapSort(int* a, int n)
{
	// ���ѷ�ʽ2��O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

void BubbleSort(int* a, int n)
{

}

void QuickSort(int* a, int n)
{

}

void MergeSort(int* a, int n)
{

}