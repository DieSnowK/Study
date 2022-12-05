#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//求两个输入变量最大值问题
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

//通过控制printf函数来打印图案
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

//判断一个整数能否被5整除问题
//int main()
//{
//	//输入值
//	int M;
//	scanf("%d", &M);
//	//判断
//	if (M % 5 == 0)
//		printf("YES");
//	else
//		printf("NO");
//
//	return 0;
//}

//判断一个数是否为奇数
//int main()
//{
//	int num = 19;
//	if (num % 2 == 1)
//		printf("奇数");
//	else
//		printf("偶数");	
//
//
//	return 0;
//}

//输出1-100之间的奇数
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

//输出1-10数
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

//计算n的介乘
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
//	printf("%d的介乘为%d:", n, tep);
//	return 0;
//}

//计算1！+2！+3！……+n!

//int main()
//{
//
//	int i = 0;
//	int n = 0;
//	int m = 0;
//	int tep = 1;
//	int sum = 0;
//	//m为求多少的介乘的具体数
//	scanf("%d", &m);
//
//	for (n = 1; n <= m; n++)
//	{
//		//由i变量来求出每个数的介乘 
//		for (i = 1; i <= n; i++)
//		{
//			tep *= i;
//		}
//
//		sum += tep;
//		//对临时值tep重新赋初值，使得下次计算i介乘时起点为1
//		tep = 1;
//	}
//	
//	printf("%d", sum);
//
//	return 0;
//}

//计算1！+2！+3！……+n!
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

//在一个有序数组中查找具体的某个数字n的下标
//采用折半查找法
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//left right mid 均为下标
//	int left = 0;
//	int right = (sizeof(arr)/sizeof(arr[0])) - 1;
//
//	//定义一个需要查找的数
//	int k = 0;
//	printf("请输入1-10中需要查找的数\n");
//	scanf("%d" , &k);
//
//	
//
//	//查找
//	//arr[]去访问数组中的数，用下标来访问数
//
//
//	while (left<=right)
//	{
//		//定义中间折半数值下标
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
//			printf("%d的下标是%d", k, mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到了/(ㄒoㄒ)/~~\n");
//	}
//
//	return 0;
//}

//查找一个有序数组中某个数的下标（笨办法）（效率低下）

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//left right mid 均为下标
//	int i = 1;
//	int nm = (sizeof(arr)/sizeof(arr[0])) - 1;
//
//	//定义一个需要查找的数
//	int k = 0;
//	printf("请输入1-10中需要查找的数\n");
//	scanf("%d" , &k);
//
//	//查找
//	//arr[]去访问数组中的数，用下标来访问数
//
//	/*for (i = 1; i < k; i++)
//	{
//
//	}*/
//
//	if (k > 10)
//	{
//		printf("%d不在该数组中，找不到啦~/(ㄒoㄒ)/~~\n", k);
//	}
//	else
//	{
//		while (i <= k)
//		{
//			if (i = k)
//			{
//				i -= 1;
//				printf("%d的下标为%d", k, i);
//				break;
//			}
//			i++;
//		}
//	}
//	return 0;
//}

////演示多个字符从两端移动，向中间汇聚
//#include <string.h>
//#include <windows.h>
//int main()
//{
//	char text[] = "Welcome to dick big!!!";
//	char exam[] = "                      ";
//	int left = 0;
//	int right = strlen(exam) - 1;
//
//	while (left <= right)
//	{
//		exam[left] = text[left];
//		exam[right] = text[right];
//		printf("%s\n", exam);
//		Sleep(200);//睡眠1s，即让程序1s后继续
//		system("cls");//清空屏幕
//		left++;
//		right--;
//	}
//	printf("%s\n", exam);
//
//	return 0;
//}

//编写代码实现，模拟用户登陆情景，并且只能登录三次
//#include <string.h>
//int main()
//{
//	//假定密码为123456
//
//	int i = 0;//登录次数 用于限制次数
//	char password[20] = { 0 };//限制密码长度最大为20
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入登录密码:>");
//		scanf("%s", password);
//		//if(password == "123456") --err 两个字符串比较，不能用==，应该使用strcap（string compare）
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("密码正确，登入成功");
//			break;
//		}
//		else
//		{
//			printf("密码错误，请重试");
//		}
//	}
//
//	return 0;
//}

//写一个猜数游戏
/*思路：1.自动生成1-100之间的随机数
		2.猜数字
			(1)猜对了，恭喜你，游戏结束
			(2)猜错了，会告诉大了还是小了，继续猜
		3.游戏一直进行，除非退出游戏*/

int main()
{
	
	return 0;
}
