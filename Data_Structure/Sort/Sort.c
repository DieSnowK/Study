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

//均以升序为例

void InsertSort(int* a, int n)
{
	assert(a);

	//视[0,end]有序，将end+1位置的值插入，保持有序
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (tmp < a[end])
			{
				//挪动数据
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				//找到tmp > a[end] 的位置
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	//gap > 1 --> 预排序
	//gap = 1 --> 直接插入排序
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;  //+1是为了保证最后gap可以取到1

		for (int j = 0; j < gap; j++)  //j控制起点
		{
			//一组预排序
			for (int i = j; i < n - gap; i += gap)
			{
				//一组预排序中的一次插入排序
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
		// 选出左右孩子中小/大的那个
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		// 孩子跟父亲比较
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

// 降序 -- 建小堆
void HeapSort(int* a, int n)
{
	// 建堆方式2：O(N)
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