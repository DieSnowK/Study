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

//ƽ��:O(N^1.3)
//void ShellSort(int* a, int n)
//{
//	//gap > 1 --> Ԥ����
//	//gap = 1 --> ֱ�Ӳ�������
//	int gap = n;
//
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;  //+1��Ϊ�˱�֤���gap����ȡ��1
//
//		for (int j = 0; j < gap; j++)  //j�������
//		{
//			//һ��Ԥ����
//			for (int i = j; i < n - gap; i += gap)
//			{
//				//һ��Ԥ�����е�һ�β�������
//				int end = i;
//				int tmp = a[end + gap];
//				while (end >= 0)
//				{
//					if (tmp < a[end])
//					{
//						a[end + gap] = a[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}

void ShellSort(int* a, int n)
{
	//gap > 1 --> Ԥ����
	//gap = 1 --> ֱ�Ӳ�������
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;  //+1��Ϊ�˱�֤���gap����ȡ��1

		//gap�����ݽ����������
		for (int i = 0; i < n - gap; i++)
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

//ʱ�临�Ӷȣ�O(N^2)  ��õ������O(N^2)
//�Ա� ��������˭���ã�  --  ����
void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			//�����ֵ/��Сֵ
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);

		//���begin��maxi�ص�����ôҪ����һ��maxi��λ��
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
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

//ʱ�临�Ӷȣ�O(N^2)  ��õ������O(N)
//�Ա� ��������˭���ã�  --  ����
void BubbleSort(int* a, int n)
{
	assert(a);
	int exchange = 0;
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = j; i < n - j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}
}

//hoare�汾
int PastSort1(int* a, int begin, int end)
{
	int left = begin, right = end;
	int keyi = left;

	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])  //left < right��Ϊ�˷�ֹԽ��
		{
			right--;
		}

		//������ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		//����
		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	return keyi;
}

//�ڿӷ�
int PastSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin;
	int left = begin, right = end;

	while (begin < end)
	{
		//�ұ���С�����ߵĿ���ȥ�����λ���γ��µĿ�
		while (begin < end && a[right] >= key)
		{
			right--;
		}

		a[piti] = a[right];
		piti = right;

		//����Ҵ���ұߵĿ���ȥ�����λ���γ��µĿ�
		while (begin < end && a[left] <= key)
		{
			left++;
		}

		a[piti] = a[left];
		piti = left;
	}

	a[piti] = key;

	return piti;
}


void QuickSort(int* a, int begin, int end)
{
	//��������  --  ֻ��һ���� --> begin == end || ���䲻���� --> begin > end
	if (begin >= end)
	{
		return;
	}

	int left = begin, right = end;
	int keyi = left;

	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])  //left < right��Ϊ�˷�ֹԽ��
		{
			right--;
		}

		//������ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		//����
		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	//key�Ѿ���ȷ��λ���ϣ���߶���keyС���ұ߶���key��
	//�ݹ飬���� --  [begin,keyi - 1]  keyi  [keyi + 1,end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void MergeSort(int* a, int n)
{

}