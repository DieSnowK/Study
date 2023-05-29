#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////冒泡排序
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
//	for (i = 0; i < n - 1; i++) //几趟
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			//一趟冒泡排序的过程
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
////小孩看星星
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	int arr[10][2] = { 0 };
//
//	scanf("%d", &n);
//	
//	//获取坐标
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//寻找极值
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
///*字符函数之求单词个数
//
//定义单词为一串连续的字母.单词内不含非字母字符.
//输入一个字符串,在函数内求串中单词的个数
//
//输入输出样例：
//hello world
//total word= 2
//
//程序的主要框架已经给出，请仅在
//	**********  Begin  **********
//
//	**********   End  ***********
//  注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
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

//删除一个串最右边的非字母字符
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

//输入一个字符串，删除该串最左边的空格并输出
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

/*指针应用之二维数组转置

输入方阵的阶n(n<40),并输入这n阶方阵,输出该方阵的转置.

输入输出样例：
请输入方阵的阶n(n<40):3
1 2 3
4 5 66
7 8 9
转置结果为:
  1   4   7
  2   5   8
  3  66   9
Press any key to continue

其中所有的中文均为计算机提示用户的输入.
最后一行的Press any key to continue是计算机结束程序时的输出.

程序的主要框架已经给出，请仅在

    **********  Begin  **********

    **********   End  ***********
  注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
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

//函数fun的功能是：找出形参s所指字符串中出现频率最高的字母(不区分大小写)，并统计出其出现的次数。
#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>
void fun(char* s)
{
	//用哈希表
	int  k[26] = { 0 };
	int n = 0;
	int max = 0;
	int i = 0;
	char  ch;
	while (*s)
	{
		if (isalpha(*s)) 
		{
			ch = tolower(*s);
			n = ch - 'a';//获取字母在数组k中的下标
			k[n] += 1;//字母所对应的值加1
		}

		s++;

		if (max < k[n])  //max用于存放最大次数
		{
			max = k[n];
		}
	}
	//寻找最大的次数是哪一个
	for (i = 0; i < 26; i++)
	{
		if (k[i] == max)
		{
			printf("%c %d\n", i + 'a', k[i]);
		}
	}
}
void main()
{
	char  s[81];
	gets(s);
	fun(s);
}
