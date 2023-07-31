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

//平均:O(N^1.3)
//void ShellSort(int* a, int n)
//{
//	//gap > 1 --> 预排序
//	//gap = 1 --> 直接插入排序
//	int gap = n;
//
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;  //+1是为了保证最后gap可以取到1
//
//		for (int j = 0; j < gap; j++)  //j控制起点
//		{
//			//一组预排序
//			for (int i = j; i < n - gap; i += gap)
//			{
//				//一组预排序中的一次插入排序
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

//平均:O(N^1.3)
void ShellSort(int* a, int n)
{
	//gap > 1 --> 预排序
	//gap = 1 --> 直接插入排序
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;  //+1是为了保证最后gap可以取到1

		//gap组数据交替插入排序
		for (int i = 0; i < n - gap; i++)
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

//时间复杂度：O(N^2)  最好的情况：O(N^2)
//对比 插入排序，谁更好？  --  插入
void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			//找最大值/最小值
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

		//如果begin和maxi重叠，那么要修正一下maxi的位置
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

//时间复杂度：O(N^2)  最好的情况：O(N)
//对比 插入排序，谁更好？  --  插入
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
		// 右边先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// 左边再走，找大
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

// 挖坑法
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin;
	while (begin < end)
	{
		// 右边找小，填到左边的坑里面去。这个位置形成新的坑
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[piti] = a[end];
		piti = end;

		// 左边找大，填到右边的坑里面去。这个位置形成新的坑
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

// 前后指针法
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	// 加入三数取中的优化
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[keyi], &a[midi]);

	while (cur <= end)
	{
		// cur位置的之小于keyi位置值
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
	//结束条件  --  只有一个数 --> begin == end || 区间不存在 --> begin > end
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 30)
	{
		//hoare版本
		int left = begin, right = end;
		int keyi = left;

		while (left < right)
		{
			//右边先走，找小
			while (left < right && a[right] >= a[keyi])  //left < right是为了防止越界
			{
				right--;
			}

			//左边再走，找大
			while (left < right && a[left] <= a[keyi])
			{
				left++;
			}

			//交换
			Swap(&a[left], &a[right]);
		}

		Swap(&a[keyi], &a[left]);
		keyi = left;

		//key已经正确的位置上，左边都比key小，右边都比key大
		//递归，分治 --  [begin,keyi - 1]  keyi  [keyi + 1,end]
		QuickSort1(a, begin, keyi - 1);
		QuickSort1(a, keyi + 1, end);
	}
	else
	{
		//直接插入排序
		InsertSort(a + begin, end - begin + 1);
	}
}

void QuickSort2(int* a, int begin, int end)
{
	//结束条件  --  只有一个数 --> begin == end || 区间不存在 --> begin > end
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 30)
	{
		//挖坑法
		int key = a[begin];
		int piti = begin;
		int left = begin, right = end;

		while (begin < end)
		{
			//右边找小，填到左边的坑里去，这个位置形成新的坑
			while (begin < end && a[right] >= key)
			{
				right--;
			}

			a[piti] = a[right];
			piti = right;

			//左边找大，填到右边的坑里去，这个位置形成新的坑
			while (begin < end && a[left] <= key)
			{
				left++;
			}

			a[piti] = a[left];
			piti = left;
		}

		a[piti] = key;

		//key已经正确的位置上，左边都比key小，右边都比key大
		//递归，分治 --  [begin,keyi - 1]  keyi  [keyi + 1,end]
		QuickSort2(a, begin, piti - 1);
		QuickSort2(a, piti + 1, end);
	}
	else
	{
		//直接插入排序
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
	//结束条件  --  只有一个数 --> begin == end || 区间不存在 --> begin > end
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 30)
	{
		//前后指针版本
		int prev = begin;
		int cur = begin + 1;
		int keyi = begin;

		//加入三数取中的优化
		int midi = GetMidIndex(a, begin, end);
		Swap(&a[keyi], &a[midi]);

		while (cur <= end)  //一直往后走，遇到小则停下来处理
		{
			//cur找小
			if (a[cur] < a[keyi] && ++prev != cur)  //防止prev和cur重合时，重复交换
			{
				Swap(&a[prev], &a[cur]);
			}

			cur++;
		}

		Swap(&a[keyi], &a[prev]);
		keyi = prev;

		//key已经正确的位置上，左边都比key小，右边都比key大
		//递归，分治 --  [begin,keyi - 1]  keyi  [keyi + 1,end]
		QuickSort3(a, begin, keyi - 1);
		QuickSort3(a, keyi + 1, end);
	}
	else
	{
		//直接插入排序
		InsertSort(a + begin, end - begin + 1);
	}
}

//用栈模拟递归 -- 先进后出
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	
	StackPush(&st, end);
	StackPush(&st, begin);

	while (!isStackEmpty(&st))
	{
		//从栈中取出两个数，作为区间
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		//排序，取keyi
		int keyi = PartSort3(a, left, right);

		//此时分成了两个区间 [left, keyi-1] keyi [keyi+1, right]
		//继续压栈
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

//函数名前加_表示这个函数是内部函数，不对外提供接口 - 子函数
//后序思想
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;

	//[begin, mid] [mid+1, end] 分治递归，让子区间有序
	_MergeSort(a,begin,mid,tmp);
	_MergeSort(a,mid+1,end,tmp);

	//归并 [begin, mid] [mid+1, end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)  //有一组结束则结束
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

	//已经有一组结束了，拷贝另一组剩余的
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//把归并数据拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//时间复杂度:O(N*logN)
//空间复杂度:O(N)
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
//	//手动归并
//	int gap = 1;  //每次归并的元素个数
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//[i, i+gap-1] [i+gap,i+2*gap-1]
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//
//			//越界处理 - 修正边界
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//				//[begin2, end2]修正为不存在区间
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (begin2 >= n)
//			{
//				// [begin2, end2]修正为不存在区间
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//
//			//归并
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
//		//全部归并完后，拷贝回原数组
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

	//手动归并
	int gap = 1;  //每次归并的元素个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i, i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//越界处理
			//end1越界或者begin2越界，则可以不归并了
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			//归并
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