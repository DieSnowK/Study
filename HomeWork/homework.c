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
////С��������
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	int arr[10][2] = { 0 };
//
//	scanf("%d", &n);
//	
//	//��ȡ����
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//Ѱ�Ҽ�ֵ
//	int max_x = arr[0][0];
//	int max_y = arr[0][1];
//	int min_x = arr[0][1];
//	int min_y = arr[0][0];
//
//	for (i = 0; i < n; i++)
//	{
//		
//		if (max_x < arr[i][0])
//		{
//			max_x = arr[i][0];
//		}
//
//		if (max_y < arr[i][1])
//		{
//			max_y = arr[i][1];
//		}
//
//		if (min_x > arr[i][0])
//		{
//			min_x = arr[i][0];
//		}
//
//		if (min_y > arr[i][1])
//		{
//			min_y = arr[i][1];
//		}
//	}
//
//	int x = max_x - min_x;
//	int y = max_y - min_y;
//	int s = x > y ? x : y;
//
//	printf("%d", s * s);
//
//	return 0;
//}

//
///*�ַ�����֮�󵥴ʸ���
//
//���嵥��Ϊһ����������ĸ.�����ڲ�������ĸ�ַ�.
//����һ���ַ���,�ں��������е��ʵĸ���
//
//�������������
//hello world
//total word= 2
//
//�������Ҫ����Ѿ������������
//	**********  Begin  **********
//
//	**********   End  ***********
//  ע�Ͷ�֮��Ŀ����������Ĵ��룬�κ��޸ĸ�����ע�ͣ��Լ��޸�ע��������������ʧ��
//*/
//
//#include <math.h>
//#include <stdio.h>
//#include <ctype.h>
//#define N 256
//#define BUFSZ N
//int fun(char* p)
//{
//	/**********  Begin  **********/
	//int count = 0;
	//for (; *p != '\0'; p++)
	//{
	//	if (!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')))
	//	{
	//		count++;
	//		while (!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')))
	//		{
	//			p++;
	//		}
	//		p--;
	//	}
	//}
	//return ++count;
///**********   End  ***********/
//
//}
//void f()
//{
//	char s[256];
//	gets(s);
//	printf("total word= %d\n", fun(s));
//}
//int main()
//{
//	f();
//	return 0;
//}

//ɾ��һ�������ұߵķ���ĸ�ַ�
//#include <string.h>
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	char* p = &arr[strlen(arr) - 1];
//
//	for (; ; p--)
//	{
//		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
//		{
//			*(p + 1) = '\0';
//			break;
//		}
//	}
//
//	printf("[%s]", arr);
//	return 0;
//}

//����һ���ַ�����ɾ���ô�����ߵĿո����
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	char* p = arr;
//
//	for (; ; p++)
//	{
//		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
//		{
//			break;
//		}
//	}
//
//	printf("%s", p);
//	return 0;
//}

/*ָ��Ӧ��֮��ά����ת��

���뷽��Ľ�n(n<40),��������n�׷���,����÷����ת��.

�������������
�����뷽��Ľ�n(n<40):3
1 2 3
4 5 66
7 8 9
ת�ý��Ϊ:
  1   4   7
  2   5   8
  3  66   9
Press any key to continue

�������е����ľ�Ϊ�������ʾ�û�������.
���һ�е�Press any key to continue�Ǽ������������ʱ�����.

�������Ҫ����Ѿ������������

    **********  Begin  **********

    **********   End  ***********
  ע�Ͷ�֮��Ŀ����������Ĵ��룬�κ��޸ĸ�����ע�ͣ��Լ��޸�ע��������������ʧ��
*/

//#include <stdio.h>
//#define N 40
//void f(int* p, int n)
//{
//    /**********  Begin  **********/
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//
//            }
//        }
//    }
//
//
///**********   End  ***********/
//
//}
//int main()
//{
//    int a[N][N], n, i, j;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//        for (j = 0; j < n; j++)
//            scanf("%d", &a[i][j]);
//    f(&a[0][0], n);
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//            printf("%d ", a[i][j]);
//        printf("\n");
//    }
//    return 0;
//}