#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////ð������
//int main()
//{
//	int arr[10] = { 0 };
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < n - 1; i++) //����
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			//һ��ð������Ĺ���
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//
//		for (k = 0; k < n; k++)
//		{
//			printf("%d", arr[k]);
//			if (k != (n - 1))
//			{
//				printf(",");
//			}
//		}
//		printf("\n");
//
//	}
//
//	return 0;
//}
//
// //С��������
// int main()
// {
// 	int n = 0;
// 	int i = 0;
// 	int j = 0;
// 	int arr[10][2] = { 0 };

// 	scanf("%d", &n);
	
// 	//��ȡ����
// 	for (i = 0; i < n; i++)
// 	{
// 		for (j = 0; j < 2; j++)
// 		{
// 			scanf("%d", &arr[i][j]);
// 		}
// 	}

// 	//Ѱ�Ҽ�ֵ
// 	int max_x = arr[0][0];
// 	int max_y = arr[0][1];
// 	int min_x = arr[0][1];
// 	int min_y = arr[0][0];

// 	for (i = 0; i < n; i++)
// 	{
		
// 		if (max_x < arr[i][0])
// 		{
// 			max_x = arr[i][0];
// 		}

// 		if (max_y < arr[i][1])
// 		{
// 			max_y = arr[i][1];
// 		}

// 		if (min_x > arr[i][0])
// 		{
// 			min_x = arr[i][0];
// 		}

// 		if (min_y > arr[i][1])
// 		{
// 			min_y = arr[i][1];
// 		}
// 	}

// 	int x = max_x - min_x;
// 	int y = max_y - min_y;
// 	int s = x > y ? x : y;

// 	printf("%d", s * s);

// 	return 0;
// }

int main()
{
    printf("Hello World");
	int i = 0;
	for(i=0;i<20;i++)
	{
		printf("%d����\n", i);
		i = 1;
	}
	if(i==1)
	{
		printf("Over");
	}
	return 0;
}