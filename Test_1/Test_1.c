#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����������������ֵ����
/*
int Max(int x, int y)
{
	if (x > y)
		return x;
	else
	return y;
}


int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int m = Max(a, b);
	printf("%d", m);

	return 0;
}
*/

//ͨ������printf��������ӡͼ��
/*
int main()
{
	printf("     **\n");
	printf("     **\n");
	printf("************\n");
	printf("************\n");
	printf("    *  *\n");
	printf("    *  *\n");
	return 0;
}
*/

//�ж�һ�������ܷ�5��������
//int main()
//{
//	//����ֵ
//	int M;
//	scanf("%d", &M);
//	//�ж�
//	if (M % 5 == 0)
//		printf("YES");
//	else
//		printf("NO");
//
//	return 0;
//}

//�ж�һ�����Ƿ�Ϊ����
//int main()
//{
//	int num = 19;
//	if (num % 2 == 1)
//		printf("����");
//	else
//		printf("ż��");	
//
//
//	return 0;
//}

//���1-100֮�������
//int main()
//{
//	int i = 1;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d\n", i);
//		}
//
//	}
//
//	return 0;
//}

//���1-10��
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d ", i);
//		i++;
//	}
//
//	return 0;
//}

//����n�Ľ��
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int tep = 1;
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++)
//	{
//		tep *= i;
//
//	}
//
//	printf("%d�Ľ��Ϊ%d:", n, tep);
//	return 0;
//}

//����1��+2��+3������+n!

//int main()
//{
//
//	int i = 0;
//	int n = 0;
//	int m = 0;
//	int tep = 1;
//	int sum = 0;
//	//mΪ����ٵĽ�˵ľ�����
//	scanf("%d", &m);
//
//	for (n = 1; n <= m; n++)
//	{
//		//��i���������ÿ�����Ľ�� 
//		for (i = 1; i <= n; i++)
//		{
//			tep *= i;
//		}
//
//		sum += tep;
//		//����ʱֵtep���¸���ֵ��ʹ���´μ���i���ʱ���Ϊ1
//		tep = 1;
//	}
//	
//	printf("%d", sum);
//
//	return 0;
//}

//����1��+2��+3������+n!
//int main()
//{
//	int sum = 0;
//	int n = 0;
//	int i = 0;
//	int tep = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		tep *= i;
//		sum += tep;
//
//	}
//	printf("%d", sum);
//	return 0;
//}

//��һ�����������в��Ҿ����ĳ������n���±�
//�����۰���ҷ�
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//left right mid ��Ϊ�±�
//	int left = 0;
//	int right = (sizeof(arr)/sizeof(arr[0])) - 1;
//
//	//����һ����Ҫ���ҵ���
//	int k = 0;
//	printf("������1-10����Ҫ���ҵ���\n");
//	scanf("%d" , &k);
//
//	
//
//	//����
//	//arr[]ȥ���������е��������±���������
//
//
//	while (left<=right)
//	{
//		//�����м��۰���ֵ�±�
//		int mid = (left + right) / 2;
//
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("%d���±���%d", k, mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ�����/(��o��)/~~\n");
//	}
//
//	return 0;
//}

//����һ������������ĳ�������±꣨���취����Ч�ʵ��£�

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//left right mid ��Ϊ�±�
//	int i = 1;
//	int nm = (sizeof(arr)/sizeof(arr[0])) - 1;
//
//	//����һ����Ҫ���ҵ���
//	int k = 0;
//	printf("������1-10����Ҫ���ҵ���\n");
//	scanf("%d" , &k);
//
//	//����
//	//arr[]ȥ���������е��������±���������
//
//	/*for (i = 1; i < k; i++)
//	{
//
//	}*/
//
//	if (k > 10)
//	{
//		printf("%d���ڸ������У��Ҳ�����~/(��o��)/~~\n", k);
//	}
//	else
//	{
//		while (i <= k)
//		{
//			if (i = k)
//			{
//				i -= 1;
//				printf("%d���±�Ϊ%d", k, i);
//				break;
//			}
//			i++;
//		}
//	}
//	return 0;
//}