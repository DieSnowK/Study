#include "Sort.h"
#include "Stack.h"

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

//ƽ��:O(N^1.3)
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

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

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

// Hoare
int PartSort1(int* a, int begin, int end)
{
	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		// �ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// ������ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	return keyi;
}

// �ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin;
	while (begin < end)
	{
		// �ұ���С�����ߵĿ�����ȥ�����λ���γ��µĿ�
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[piti] = a[end];
		piti = end;

		// ����Ҵ���ұߵĿ�����ȥ�����λ���γ��µĿ�
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[piti] = a[begin];
		piti = begin;
	}

	a[piti] = key;
	return piti;
}

// ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	// ��������ȡ�е��Ż�
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[keyi], &a[midi]);

	while (cur <= end)
	{
		// curλ�õ�֮С��keyiλ��ֵ
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}

	Swap(&a[prev], &a[keyi]);
	keyi = prev;

	return keyi;
}

void QuickSort1(int* a, int begin, int end)
{
	//��������  --  ֻ��һ���� --> begin == end || ���䲻���� --> begin > end
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 0)
	{
		//hoare�汾
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
		QuickSort1(a, begin, keyi - 1);
		QuickSort1(a, keyi + 1, end);
	}
	else
	{
		//ֱ�Ӳ�������
		InsertSort(a + begin, end - begin + 1);
	}
}

void QuickSort2(int* a, int begin, int end)
{
	//��������  --  ֻ��һ���� --> begin == end || ���䲻���� --> begin > end
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 0)
	{
		//�ڿӷ�
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

		//key�Ѿ���ȷ��λ���ϣ���߶���keyС���ұ߶���key��
		//�ݹ飬���� --  [begin,keyi - 1]  keyi  [keyi + 1,end]
		QuickSort2(a, begin, piti - 1);
		QuickSort2(a, piti + 1, end);
	}
	else
	{
		//ֱ�Ӳ�������
		InsertSort(a + begin, end - begin + 1);
	}
}

int GetMidIndex(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	if (a[begin] > a[end])
	{
		if (a[midi] > a[begin])
		{
			return begin;
		}
		else if (a[end] > a[midi])
		{
			return end;
		}
		else
		{
			return midi;
		}
	}
	else
	{
		//a[begin] < a[end]
		if (a[midi] > a[end])
		{
			return end;
		}
		else if (a[begin] > a[midi])
		{
			return begin;
		}
		else
		{
			return midi;
		}
	}
}

void QuickSort3(int* a, int begin, int end)
{
	//��������  --  ֻ��һ���� --> begin == end || ���䲻���� --> begin > end
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 0)
	{
		//ǰ��ָ��汾
		int prev = begin;
		int cur = begin + 1;
		int keyi = begin;

		//��������ȡ�е��Ż�
		int midi = GetMidIndex(a, begin, end);
		Swap(&a[keyi], &a[midi]);

		while (cur <= end)  //һֱ�����ߣ�����С��ͣ��������
		{
			//cur��С
			if (a[cur] < a[keyi] && ++prev != cur)  //��ֹprev��cur�غ�ʱ���ظ�����
			{
				Swap(&a[prev], &a[cur]);
			}

			cur++;
		}

		Swap(&a[keyi], &a[prev]);
		keyi = prev;

		//key�Ѿ���ȷ��λ���ϣ���߶���keyС���ұ߶���key��
		//�ݹ飬���� --  [begin,keyi - 1]  keyi  [keyi + 1,end]
		QuickSort3(a, begin, keyi - 1);
		QuickSort3(a, keyi + 1, end);
	}
	else
	{
		//ֱ�Ӳ�������
		InsertSort(a + begin, end - begin + 1);
	}
}

//��ջģ��ݹ� -- �Ƚ����
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	
	StackPush(&st, end);
	StackPush(&st, begin);

	while (!isStackEmpty(&st))
	{
		//��ջ��ȡ������������Ϊ����
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		//����ȡkeyi
		int keyi = PartSort3(a, left, right);

		//��ʱ�ֳ����������� [left, keyi-1] keyi [keyi+1, right]
		//����ѹջ
		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
	}

	StackDestroy(&st);
}

//������ǰ��_��ʾ����������ڲ��������������ṩ�ӿ� - �Ӻ���
//����˼��
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;

	//[begin, mid] [mid+1, end] ���εݹ飬������������
	_MergeSort(a,begin,mid,tmp);
	_MergeSort(a,mid+1,end,tmp);

	//�鲢 [begin, mid] [mid+1, end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)  //��һ����������
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//�Ѿ���һ������ˣ�������һ��ʣ���
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//�ѹ鲢���ݿ�����ԭ����
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//ʱ�临�Ӷ�:O(N*logN)
//�ռ临�Ӷ�:O(N)
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("MergeSort");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc:");
//		exit(-1);
//	}
//
//	//�ֶ��鲢
//	int gap = 1;  //ÿ�ι鲢��Ԫ�ظ���
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//[i, i+gap-1] [i+gap,i+2*gap-1]
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//
//			//Խ�紦�� - �����߽�
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//				//[begin2, end2]����Ϊ����������
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (begin2 >= n)
//			{
//				// [begin2, end2]����Ϊ����������
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//
//			//�鲢
//			int j = begin1;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[j++] = a[begin1++];
//				}
//				else
//				{
//					tmp[j++] = a[begin2++];
//				}
//			}
//
//			while (begin1 <= end1)
//			{
//				tmp[j++] = a[begin1++];
//			}
//
//			while (begin2 <= end2)
//			{
//				tmp[j++] = a[begin2++];
//			}
//
//		}
//
//		//ȫ���鲢��󣬿�����ԭ����
//		memcpy(a, tmp, sizeof(int) * n);
//
//		gap *= 2;
//	}
//
//	free(tmp);
//}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc:");
		exit(-1);
	}

	//�ֶ��鲢
	int gap = 1;  //ÿ�ι鲢��Ԫ�ظ���
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i, i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//Խ�紦��
			//end1Խ�����begin2Խ�磬����Բ��鲢��
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			//�鲢
			int m = end2 - begin1 + 1;
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * m);
		}

		gap *= 2;
	}

	free(tmp);
}