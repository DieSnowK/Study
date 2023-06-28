#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

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

		//#include <stdlib.h>
		//#include <time.h>
		//
		//void menu()
		//{
		//
		//	printf("***********************************\n");
		//	printf("************  1.Play  *************\n");
		//	printf("************  0.exit  *************\n");
		//	printf("***********************************\n");
		//
		//}
		//
		//void game()
		//{
		//	//先生成随机数，以时间做种
		//	int num = rand() % 100 + 1;//%100的余数是0-99，然后+1即可达成范围为1-100
		//
		//	//先做框架
		//	int guess = 0;
		//	while (1)
		//	{
		//		printf("请猜数字:>");
		//		scanf("%d", &guess);
		//		if (guess > num)
		//		{
		//			printf("猜大啦\n");
		//		}
		//		else if (guess < num)
		//		{
		//			printf("猜小啦\n");
		//		}
		//		else
		//		{
		//			printf("恭喜你，猜对了，正确答案为%d\n", num);
		//			break;
		//		}
		//	}
		//
		//
		//}
		//
		//int main()
		//{
		//	int input = 0;
		//	//先调用srand() 掷出rand()所需要的随机数种子
		//	//该种子一个程序中，有一次生成即可
		//	//所以放在主函数开头中
		//	srand((unsigned int)time(NULL));
		//
		//	do 
		//	{
		//		//开始游戏先打印菜单
		//		menu();
		//		printf("请选择:>");
		//		//选择游戏模式
		//		scanf("%d", &input);
		//
		//		//判断游戏是否进行（即状态）
		//		//switch 决定游戏框架
		//		//game()决定游戏如何游玩
		//		switch (input)
		//		{
		//		case 1:
		//			game();
		//			break;
		//		case 0:
		//			printf("退出游戏\n");
		//			break;
		//		default:
		//			printf("选择错误，请重新选择\n");
		//			break;
		//		}
		//	} while (input);
		//	
		//	return 0;
		//}

		//将三个整数按从大到小输出
		//借此研究理解全局变量和局部变量

		//int main()
		//{
		//	int a = 0;
		//	int b = 0;
		//	int c = 0;
		//	printf("请输入要排序的三个数:>");
		//	//输入
		//	scanf("%d%d%d", &a, &b, &c);
		//	
		//	//调整顺序
		//	if (a < b)
		//	{
		//		int tep = a;//中间过度变量
		//		a = b;
		//		b = tep;
		//	}
		//	if (a < c)
		//	{
		//		int tmp = a;
		//		a = c;
		//		c = tmp;
		//	}
		//	if (b < c)
		//	{
		//		int tmp = b;
		//		b = c;
		//		c = tmp;
		//	}
		//
		//	//输出 - 从大到小
		//	printf("%d %d %d", a, b, c);
		//	return 0;
		//}

		//打印1-100之间3的倍数的数字

		//int main()
		//{
		//	int i = 0;
		//	//for (i = 1; i <= 100; i++)
		//	//{
		//	//	if (i % 3 == 0)
		//	//	{
		//	//		printf("%d ", i);
		//	//	}
		//	//}
		//
		//	for (i = 3; i <= 100; i += 3)
		//	{
		//		printf("%d ", i);
		//	}
		//
		//	return 0;
		//}

		//给定两个数，求这两个数的最大公约数

		//int main()
		//{
		//	int m = 0;
		//	int n = 0;
		//	int min = 0;
		//	scanf("%d%d", &m, &n);
		//
		//	//方法① if语句
		//	/*if (m > n)
		//	{
		//		min = n;
		//	}
		//	else
		//	{
		//		min = m;
		//	}*/
		//
		//	//方法② 用条件操作符 exp1 ? exp2 : exp3
		//	min = (m > n) ? n : m;//等价于上方的if语句
		//
		//	while (1)
		//	{
		//		if (m % min == 0 && n % min == 0)
		//		{
		//			printf("最大公约数为%d", min);
		//			break;
		//		}
		//		min--;
		//	}
		//
		//	return 0;
		//} 

		//上述问题用辗转相除法
		//
		//int main()
		//{
		//	int m = 0;
		//	int n = 0;
		//	int tep = 0;
		//	scanf("%d%d", &m, &n);
		//
		//	while (tep=m%n)
		//	{
		//		m = n;
		//		n = tep;
		//	}
		//	printf("最大公约数是%d", n);
		//	return 0;
		// //最小公倍数 = m*n/最大公因数 
		//}

		//打印1000-2000之间的闰年

		//int main()
		//{
		//	//能被4整除，不能被100整除的为闰年
		//	//能被400整除，为闰年
		//
		//	int year = 0;
		//	int count = 0;
		//	//for (year = 1000; year<= 2000; year++)
		//	//{
		//	//	if (year % 4 == 0)
		//	//	{
		//	//		if (year % 100 != 0)
		//	//		{
		//	//			printf("%d ", year);
		//	//			count++;
		//	//		}
		//	//		
		//	//	}
		//	//	if (year % 400 == 0)
		//	//	{
		//	//		printf("%d ", year);
		//	//		count++;
		//	//	}
		//	//}
		//
		//	//优化上述代码 用|| 逻辑或来合并两次if判断闰年的两种方法
		//	for (year = 1000; year <= 2000; year++)
		//	{
		//		if (((year % 4 == 0) && (year % 400 != 0)) || (year % 400 == 0))
		//		{
		//			printf("%d ", year);
		//			count++;
		//		}
		//	}
		//
		//	printf("\n\n闰年总数为%d\n", count);
		//	return 0;
		//}

		//打印100-200之间的素数
		//int main()
		//{
		//	//素数的判断
		//	//因数只有1和本身
		//	int i = 0;
		//	for (i = 100; i <= 200; i++) //这个for语句是为了生成100-200
		//	{
		//		//判断i是否为素数
		//		//方法：用2 -> i-1之间的数字去试除，看能不能整除
		//		//如果能，即不是素数
		//		int j = 0;
		//
		//		for (j = 2; j < i; j++) //这个for语句是判断是否为素数用的
		//		{
		//			if (i % j == 0)
		//			{
		//				break;
		//			}
		//		}
		//		//break跳出到此
		//		if (i == j)//因为两个路径都可以到达这个地方，所以用if语句判断来控制输出
		//		{
		//			printf("%d ", i);//打印素数
		//		}
		//	}
		//	return 0;
		//}

		//上述题目另一种判断思路

		//int main()
		//{
		//	//素数的判断
		//	//因数只有1和本身
		//	int i = 0;
		//	for (i = 100; i <= 200; i++) //这个for语句是为了生成100-200
		//	{
		//		//判断i是否为素数
		//		//方法：用2 -> i-1之间的数字去试除，看能不能整除
		//		//如果能，即不是素数
		//		int j = 0;
		//		int flag = 1;//假设i就是素数
		//		for (j = 2; j < i; j++) //这个for语句是判断是否为素数用的
		//		{
		//			if (i % j == 0)
		//			{
		//				flag = 0;//i不是素数
		//				break;
		//			}
		//		}
		//		//break跳出到此
		//		if (flag == 1)
		//		{
		//			printf("%d ", i);//打印素数
		//		}
		//	}
		//	return 0;
		//}

		//上述问题的另一种写法
		//#include <math.h>
		//
		//int main()
		//{
		//	//素数的判断
		//	//因数只有1和本身、
		//	//如果m=a*b
		//	//a和b中一定至少有一个数字是<=m开平方根
		//	//如16 = 2*8 = 4*4  sqrt(16)=4
		//	//所以试除 只需要除到 <=m开平方根即可，因为如果这个可以，那么后面也必然可以存在一个因数使得他可以除
		//	int i = 0;
		//	for (i = 101; i <= 200; i+=2) //这个for语句是为了生成100-200       从101开始，每次+=2，从源头上杜绝了判断偶数的可能  因为偶数有2为因数
		//	{
		//		//判断i是否为素数
		//		//方法：用2 -> sqrt(i)之间的数字去试除，看能不能整除
		//		//如果能，即不是素数
		//		int j = 0;
		//		int flag = 1;//假设i就是素数    此处flag为控制变量
		//		for (j = 2; j < sqrt(i); j++) //减少了循环次数，优化代码效率
		//		{
		//			if (i % j == 0)
		//			{
		//				flag = 0;//i不是素数
		//				break;
		//			}
		//		}
		//		//break跳出到此
		//		if (flag == 1)
		//		{
		//			printf("%d ", i);//打印素数
		//		}
		//	}
		//	return 0;
		//}

		//关机
		//#include <string.h>
		//
		//int main()
		//{
		//	char input[20] = { 0 };//存放输入信息
		//	system("shutdown -s -t 60"); //需引用 - stdlib.h
		//	
		//again:
		//
		//	printf("您的电脑将在60s后关机，如要取消，请输入:我是猪,\"即可取消关机\"\n");
		//	scanf("%s", input);
		//
		//	if (strcmp(input, "我是猪") == 0)
		//	{
		//		system("shutdown -a");
		//		printf("成功取消");
		//	}
		//	else 
		//	{
		//		goto again;   //可以用while循环代替goto 
		//	}
		//
		//	return 0;
		//}

		//写一个函数可以找出两个整数中的较大值

		//int get_max(int x,int y)
		//{
		//	int z = 0;
		//	z = (x > y) ? x : y;
		//	return z;//返回z-返回最大值
		//}
		//
		//int main()
		//{
		//	int a = 10;
		//	int b = 20;
		//	//函数的调用
		//	int max = get_max(a, b);
		//	printf("max = %d\n");
		//	return 0;
		//}

		//写一个函数 - 交换两个整型变量的值

		//void exchange_int(int* x, int* y)
		//{
		//	int z = 0;
		//	z = *x;
		//	*x = *y;
		//	*y = z;
		//}
		//
		//int main()
		//{
		//	int a = 10;
		//	int b = 20;
		//	printf("交换前的值为%d %d\n", a, b);
		//	//调用交换数值函数
		//	exchange_int(&a,&b);
		//	printf("交换后的值为%d %d\n", a, b);
		//
		//	return 0;
		//}

		//写一个函数可以判断一个数是不是素数
		//
		//#include <math.h>
		//
		//int judge_prime(int x)
		//{
		//	//怎么判断一个素数？
		//	//方法① 用要判断的数去除2 - （num-1），我都除了之后有余数，那他就是素数
		//	int z = 0;
		//	for (z = 2; z <= sqrt(x); z++)
		//	{
		//		if (x % z == 0)
		//		{
		//			return 0;
		//		}
		//
		//	}
		//	return 1;
		//}
		//
		//int main()
		//{
		//	//判断100-200中间的素数
		//	int num = 0;
		//	int count = 0;
		//	for (num = 100; num <= 200; num++)
		//	{
		//		if (judge_prime(num) == 1)
		//		{
		//			printf("%d ", num);
		//			count++;
		//		}
		//
		//	}
		//
		//	printf("\ncount = %d\n", count);
		//	return 0;
		//}

		//写一个函数判断一年是不是闰年
		//1000-2000年之间的闰年

		//定义函数
		//int judge_year(int x)
		//{
		//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
		//	{
		//		return 0;
		//	}
		//	return 1;
		//}
		//
		//int main()
		//{
		//	int y = 0;
		//	int count = 0;
		//	for (y = 1000; y <= 2000; y++)
		//	{
		//		if (judge_year(y) == 0)
		//		{
		//			printf("%d ", y);
		//			count++;
		//		}
		//	}
		//
		//	printf("\ncount = %d\n", count);
		//	return 0;
		//}

		//写一个函数，实现一个整型有序数组的二分查找

		//int get_num(int a[],int x,int y)
		//{
		//	int left = 0;
		//	int right = y - 1;
		//
		//	while (left <= right)
		//	{
		//		int mid = (left + right) / 2;
		//		if (a[mid] < x)
		//		{
		//			left += 1;
		//		}
		//		else if (a[mid] > x)
		//		{
		//			right -= 1;
		//		}
		//		else
		//		{
		//			return mid;
		//		}
		//	}
		//	return 0;
		//}
		//
		//int main()
		//{
		//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
		//	int k = 8;
		//	int sz = sizeof(arr) / sizeof(arr[0]);
		//
		//	if (get_num(arr, k, sz) == 0)
		//	{
		//		printf("找不到了/(ㄒoㄒ)/~~\n");
		//	}
		//	else
		//	{
		//		printf("%d的下标为：%d\n", k, get_num(arr, k, sz)); //链式访问
		//	}
		//	return 0;
		//}

		//写一个函数，每调用一次这个函数，将会将num的值增加1

		//add(int* p)
		//{
		//	(*p)++;
		//}
		//
		//int main()
		//{
		//	int num = 0;
		//	add(&num);
		//	printf("%d\n", num);//1
		//
		//	add(&num);
		//	printf("%d\n", num);//2
		//
		//	add(&num);
		//	printf("%d\n", num);//3
		//	return 0;
		//}

		//函数的嵌套调用
		//void test3()
		//{
		//	printf("呵呵\n");
		//}
		//
		//int test2()
		//	{
		//		test3();
		//		return 0;
		//	}
		//
		//int main()
		//{
		//	test2();
		//	return 0;
		//}

		//接受一个整型值（无符号），按顺序打印他的每一位  例如：1234，输出1 2 3 4
		//从项目为练习函数的递归（自己调用自己）
		//递归主要思考方式：把大事化小 

		//void print(int n)
		//{
		//	if (n > 9)   //需要存在限制条件，来组织函数一直递归    且每递归一次，越来越接近限制条件
		//	{
		//		print(n/10);
		//	}
		//	printf("%d ", n % 10);
		//}
		//
		//int main()
		//{
		//	int num = 0;
		//	scanf("%d", &num);
		//	print(num);
		//	return 0;
		//}

		//模拟实现一个strlen函数   测量字符串长度函数

		//int my_strlen(char* str)//str为一个字符型指针变量
		//{
		//	//创建临时变量的方法
		//	//int count = 0;
		//	//while (*str != 0) //指针存放数组时，存放的是第一个元素的地址，并非整个数组
		//	//{
		//	//	str++;
		//	//	count++;
		//	//}
		//	//return count;
		//
		//	//不允许创建临时变量法，用函数递归
		//	if (*str != '\0')
		//	{
		//		return 1 + my_strlen(str + 1);
		//	}
		//	else
		//	{
		//		return 0; 
		//	}
		//	
		//}
		//
		//int main()
		//{
		//	char arr[] = "SnowK";
		//	//[S][n][o][w][K][\0]   \0为字符串结束表示，不占据字符串长度和大小
		//
		//	printf("%d\n", my_strlen(arr));//函数的链式访问
		//	return 0;
		//}

		//求n的介乘
		//迭代的方式

		//int main()
		//{
		//	int n = 0;   //求n的介乘，可以用n来限制次数
		//	int i = 0;
		//	scanf("%d", &n);
		//	int ret = 1; //ret作为中转用的变量
		// 
		//  迭代
		//	for (i = 1; i <= n; i++)
		//	{
		//		ret = ret * i;
		//	}
		//	
		//	printf("%d", ret);
		//	return 0;
		//}

		////求n的介乘  用递归的方式
		//Fac(int n)
		//{
		//	if (n <= 1)
		//	{
		//		return 1;
		//	}
		//	else
		//	{
		//		return n * Fac(n - 1);
		//	}
		//}
		//
		//int main()
		//{
		//	int n = 0;
		//	scanf("%d", &n);
		//	//int ret = Fac(n);
		//	//
		//	//printf("%d", ret);
		//
		//	printf("%d", Fac(n));
		//
		//	return 0;
		//}

		//求斐波那契数列的第n个数
		//用迭代的方法去做

		//定义一个全局变量count  用来计数
		//int count = 0;
		//
		//int Fib(int n)
		//{
		//	if (n == 3)
		//	{
		//		count++; //用于计数，n=3被算了多少遍
		//	}
		//
		//	if (n <= 2)
		//	{
		//		return 1;
		//	}
		//	else
		//	{
		//		return Fib(n - 1) + Fib(n - 2);
		//	}
		//}
		//
		//int main()
		//{
		//	int n = 0;
		//	scanf("%d", &n);
		//
		//	printf("%d\n", Fib(n));
		//
		//	printf("%d\n", count);
		//
		//	return 0;
		//}

		//求n的斐波那契数
		//用迭代的方式去做

		//int Fib(int n)
		//{
		//	int a = 1;
		//	int b = 1;
		//	int c = 1;
		//
		//	while (n >= 3)
		//	{
		//		c = a + b;
		//		a = b;
		//		b = c;
		//		n--;
		//	}
		//	return c;
		//}
		//
		//int main()
		//{
		//	int n = 0;
		//	printf("要计算第几个斐波那契数:");
		//	scanf("%d", &n);
		//	int result = Fib(n);
		//	printf("%d", result);
		//
		//	return 0;
		//}


		//编写程序数一下1到100 的所有整数中出现多少个数字9
		//9 19 29 39 49 59 69 79 89 99

		//int main()
		//{	
		//	int count = 0;
		//	//先生成数字
		//	int i = 0;
		//	for (i = 1; i <= 100; i++)
		//	{
		//		//判断个位9
		//		if (i % 10 == 9)
		//		{
		//			count++;
		//		}
		//
		//		//判断十位10
		//		if (i / 10 == 9)
		//		{
		//			count++;
		//		}
		//	}
		//
		//	printf("总共有%d个9", count);
		//	return 0;
		//}


		//计算1/1-1/2+1/3-1/4+1/5 ......+ 1/99 - 1/100的值，打印出结果
		//int main()
		//{
		//	int i = 0;
		//	double sum = 0.0;
		//	int flag = 1;
		//	for (int i = 1; i <= 100; i++)
		//	{
		//		//此处模2是为了判断并且控制正负号
		//	/*	if (i % 2 == 0)
		//			sum -= 1.0 / i;
		//		else
		//			sum += 1.0 / i;*/
		//
		//		//另一种控制正负方法
		//		sum += 1.0 / i * flag;
		//		flag = -flag;  //控制正负号
		//
		//	}
		//	printf("%lf", sum);
		//	return 0;
		//}

		//求10个数中的最大值  随机 且不分正负

		//int main()
		//{
		//	int arr[7] = { 188,261,233,666,100,1835,1752 };
		//	int max = arr[0];  //假设起始max数为数组中的一个数  而不是0   因为如果为负数，则无法判断
		//	int i = 0;
		//
		//	for (i = 1; i <= 7; i++)
		//	{
		//		if (arr[i] > max)
		//		{
		//			max = arr[i];
		//		}
		//	}
		//
		//	printf("%d", max);
		//
		//	return 0;
		//}
		//
		//打印九九乘法表
			//1*1=1 
			//2*1=2 2*2=4
			//3*1=3 3*2=4

		//int main()
		//{
		//	int i = 0;
		//	for (i = 1; i <= 9; i++)//控制行数
		//	{
		//		int j = 0; //控制列数变量
		//
		//		for (j = 1; j <= 9; j++)
		//		{
		//			printf("%d*%d=%-2d ", i, j, i * j);//%-2d用了控制两位，且左对齐    %2d为右对齐
		//			                                  //使输出的int型的数值以2位的固定位宽输出。如果不足2位，则在前面补空格
		//		}
		//		printf("\n"); //调整排版，使每一行结尾换行
		//	}
		//	return 0;
		//}
		//

		//实现X*X乘法表
		//
		//void print_table(int n)
		//{
		//	int i = 0;
		//	for (i = 1; i <= n; i++)
		//	{
		//		//一行
		//		int w = 0;
		//		for (w = 1; w <= n; w++)
		//		{
		//			printf("%d*%d=%-4d", i, w, i * w);
		//		}
		//		printf("\n");
		//	}
		//}
		//
		//int main()
		//{
		//	int n = 0; //控制x*x
		//	printf("请输入需要X*X:");
		//	scanf("%d", &n);
		//
		//	print_table(n);
		//	return 0;
		//}

		//字符串逆序(递归实现)题目内容:
		//编写一个函数reverse_string(char * string)(递归实现)
		//实现:将参数字符串中的字符反向排列，不是逆序打印。要求:不能使用C函数库中的字符串操作函数

		//int my_strlen(char* arr)//写一个函数  模拟库函数strlen()的功能
		//{
		//	int count = 0;
		//	while (*arr != '\0')
		//	{
		//		arr++;
		//		count++;
		//	}
		//	return count;
		//
		//}

		//法①  不用递归实现  用迭代
		//void reverse_string(char* arr)//形参用指针
		//{
		//	int left = 0;
		//	int right = my_strlen(arr) - 1;
		//	while (left < right)
		//	{
		//		//第一种表述形式
		//		//char tmp = arr[left];
		//		//arr[left] = arr[right];
		//		//arr[right] = tmp;
		//		//left++;
		//		//right--;
		//
		//		//第二种表述形式   解引用
		// 		char tmp = *(arr + left);//等价于 arr[left];
		//		*(arr + left) = *(arr + right);
		//		*(arr + right) = tmp;
		//		left++;
		//		right--;
		//	}
		//}

		//法② 用递归实现
		//void reverse_string(char* arr)
		//{
		//	char tmp = *arr;
		//	int len = my_strlen(arr) - 1;
		//	*arr = *(arr + len);
		//	*(arr + len) = '\0'; //先不放最前面一个值到最后面  防止下次调用时 这两个换  就达不到目的
		//	//判断条件
		//	if (my_strlen(arr + 1) >= 2)
		//	{
		//		reverse_string(arr + 1);
		//	}
		//	*(arr + len) = tmp;//最后再把第一个值换到最后面
		//}
		//
		//int main()
		//{
		//	//生成一个字符串
		//	char arr[10] = "DiesnowK" ;
		//	reverse_string(arr);//传数组过去 传的是第一个字符的地址
		//	printf("%s", arr);
		//	return 0;
		//}

		//计算一个数的每位之和(非负数)  用递归实现

		//int digitsum(int n)
		//{
		//	if (n <= 9)
		//		return n;
		//	else
		//	{
		//		return n % 10 + digitsum(n / 10);
		//	}
		//}
		//
		//int main()
		//{
		//	int n = 0;
		//	scanf("%d", &n);
		//	int sum = digitsum(n);
		//	printf("%d", sum);
		//	
		//	return 0;
		//}

		//编写一个程序，实现n的k次方，用递归实现  包含正负数功能
		//若k次方为负的，则为小数，所以数据类型用double

		//double Pow(int n, int k)
		//{
		//	if (k == 0)
		//	{
		//		return 1.0;
		//	}
		//	else if (k > 0)
		//	{
		//		return n * Pow(n, k - 1);
		//	}
		//	else
		//	{
		//		return 1.0 / (Pow(n, -k));
		//	}
		//}
		//
		//int main()
		//{
		//	int n = 0;
		//	int k = 0;
		//	scanf("%d %d", &n, &k);
		//	double result = Pow(n, k);
		//	printf("%lf", result);
		//
		//	return 0;
		//}

		//冒泡排序

		//void bubble_sort(int* arr, int sz)
		//{
		//	//确定要换几趟
		//	int i = 0;
		//	int flag = 1;
		//	for (i = 0; i < sz - 1; i++)
		//	{
		//		//每一趟要换几次
		//		int j = 0;
		//		for (j = 0; j < sz - 1 - i; j++)
		//		{
		//			//一趟冒泡排序的过程
		//			if (arr[j] < arr[j + 1])
		//			{
		//				//交换
		//				int tmp = arr[j];
		//				arr[j] = arr[j + 1];
		//				arr[j + 1] = tmp;
		//				flag = 0;
		//			}
		//		}
		//		if (flag == 1)
		//		{
		//			break;
		//		}
		//	}
		//
		//}
		//
		//int main()
		//{
		//	//声明数组
		//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
		//	int sz = sizeof(arr) / sizeof(arr[0]);
		//	bubble_sort(arr, sz);
		//	int k = 0;
		//	for (k = 0; k <= sz - 1; k++)
		//	{
		//		printf("%d ", arr[k]);
		//	}
		//
		//	return 0;
		//}

		//完成数组的交换

		//int main()
		//{
		//	int arr1[] = { 1,3,5,7,9 };
		//	int arr2[] = { 2,4,6,8,10 };
		//	int i = 0;
		//	int sz = sizeof(arr1);
		//	for (i = 0; i < sz; i++)
		//	{
		//		int tmp = 0;
		//		tmp = arr1[i];
		//		arr1[i] = arr2[i];
		//		arr2[i] = tmp;
		//	}
		//	return 0;
		//}

		//较为规范模拟strcpy  -  my_strcpy

		//#include <assert.h>
		//
		//char* my_strcpy(char* destination, const char* source) //这里使用const防止source被修改
		//{
		//	char* tmp = destination;
		//
		//	assert(source != NULL); //断言，用来debug时查错用
		//
		//	while (*destination++ = *source++)
		//	{
		//		;
		//	}
		//	return tmp;  //返回目标空间的起始地址
		//}
		//
		//int main()
		//{
		//	char arr1[] = "SnowK";
		//	char arr2[] = "xxxxxxxxxxxxx";
		//
		//	printf("%s\n", my_strcpy(arr2, arr1));
		//
		//	return 0;
		//}

		//较为规范的模拟strlen  -  my_strlen

		//#include <assert.h>
		//
		//unsigned int my_strlen(const char* arr)  //为何是unsigned int?   --  因为长度不存在负数，以防任何其他意外
		//{
		//	assert(arr != NULL);
		//	//assert(arr); 等价于上述表达式
		//
		//	unsigned int count = 0;
		//	while (*arr++ != '\0')
		//	{
		//		count++;
		//	}
		//	return count;
		//}
		//
		//int main()
		//{
		//	char arr[] = "DieSnowK";
		//	printf("%d\n", my_strlen(arr));
		//	
		//	return 0;
		//}

		//写一个函数
		//要求：输入一个整数，输出该数32位二进制表示中1的个数，其中负数用补码表示

		//如何获取一个十进制数字的二进制形式？
		//以下为例子
		//15 - 00001111
		//15 % 2 = 1               //获得最右边一位是1/0
		//15 / 2 = 7 - 00000111    //除去一位
		//7 % 2 = 1
		//7 / 2 = 3 -- 00000011
		//3 % 2 = 1 -- 00000001
		//3 / 2 = 1 -- 00000001
		//1 % 2 = 1 -- 00000001

		//此函数算法是有问题的   正数可以正常处理   但是负数呢？
		//int NumberOf(int n)
		//{
		//	int count = 0;//计数器
		//	while (n)
		//	{
		//		if (n % 2 == 1)  //判断第一位是否是1
		//		{
		//			count++;
		//		}
		//
		//		n /= 2;  //获取下一位
		//	}
		//
		//	return count;
		//}

		//通过直接操作二进制位  可以避免上述问题
		//int NumberOf(int n)
		//{
		//	int count = 0;
		//	int i = 0;
		//	
		//	for (i = 0; i < 32; i++)
		//	{
		//		//用& 按位与   
		//		//与1   00000001    可判断最后一位情况
		//
		//		if ((n >> i) & 1 == 1)    //n右移位数用i控制  一步控制  不需要每次都右移一位
		//		{
		//			count++;
		//		}
		//	}
		//	
		//	return count;
		//}

		//以上函数算法可优化
		//n & (n - 1)  --  用来逐步减少二进制位中的1
		//以下位例子
		//n = n & (n - 1)
		//n = 15
		//1111 - n
		//1110 - n - 1
		//1110 - n
		//1101 - n - 1
		//1100 - n
		//1011 - n - 1
		//1000 - n
		//0111 - n - 1
		//0000 - n

		//以上思路还可以用来判断一个数字是不是2的n次方
		//2的n次方的数字，其中只有一个1
		// 00100000 - n
		// 00011111 - n - 1
		//k & (k - 1) == 0

		//int NumberOf(int n)
		//{
		//	int count = 0;
		//
		//	while (n)  //一直处理到 n == 0时，跳出循环
		//	{
		//		n = n & (n - 1); //只要能进来，就让他移位，减少二进制中的一个1
		//		count++;
		//	}
		//
		//	return count;
		//}

		//int main()
		//{
		//	int n = -1;  //00001100  -  12
		//
		//	printf("%d", NumberOf(n));
		//	return 0;
		//}

		//求两个数二进制中不同位的个数
		// 按位异或即可   ^   相同为0  相异为1
		// 统计异或后的结果中1的个数
		//例：1999  2299    输出 - 7

//int NumberOf(int n)
//{
//	int count = 0;
//
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//
//	return count;
//}

//int main()
//{
//
//	int m = 0;
//	int n = 0;
//	int ret = 0;
//
//	scanf("%d %d", &m, &n);
//
//	ret = m ^ n;    //相同为0  相异为1
//	printf("%d\n", NumberOf(ret));
//
//	return 0;
//}

//以上问题另一种处理方案
//int main()
//{
//	int m = 0;
//	int n = 0;
//
//	int count = 0;
//	int i = 0;
//	scanf("%d %d", &m, &n);
//
//	for (i = 0; i < 32; i++)
//	{
//		if (((m >> i) & 1) != ((n >> i) & 1))
//		{
//			count++;
//		}
//	}
//
//	printf("%d", count);
//
//	return 0;
//}

//打印整数二进制的奇数位和偶数位

//int main()
//{
//	int x = 15;
//	int i = 0;
//	//00000000000000000000000000001000
//	//打印偶数位
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (x >> i) & 1);
//	}
//	printf("\n");
//
//	//打印奇数位
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (x >> i) & 1);
//	}
//
//	return 0;
//}

//交换两个变量（不创建临时变量）

//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	a = a ^ b;
//	b = a ^ b; // a ^ b ^ b        b ^ b == 0     此时b == a
//
//	a = b ^ a; // a ^ a ^ b  同理
//
//	printf("a = %d  b = %d", a, b);
//
//	return 0;
//}

//求最小公倍数  设计算法

//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	scanf("%d %d", &a, &b);
//	int m = a > b ? a : b;
//
//	//while (1)
//	//{
//	//	if (m % a == 0 && m % b == 0)
//	//	{
//	//		printf("%d\n", m);
//	//		break;
//	//	}
//	//	m++;
//	//}
//
//	//以上代码可优化
//	int i = 1;
//	for (i = 1;; i++)
//	{
//		if (a * i % b == 0)
//		{
//			printf("%d\n", a * i);
//			break;
//		}
//	}
//
//	return 0;
//}

//将一句话的单词进行倒置，标点不倒置，比如 l like beijing.
//倒置后 beijing. like l
//#include <string.h>
//
//void reverse(char* left, char* right) //用来逆序数组内容
//{
//	while (left < right)
//	{
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[100];
//	gets(arr);
//	int len = strlen(arr);
//
//	//三步翻转法
//	//1.字符串整体翻转
//	reverse(arr, arr + len - 1);
//	//2.每个单词逆序
//	char* start = arr;
//	while (*start)
//	{
//		char* end = start;
//
//		//找到每一个单词停顿的位置
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		//逆序每一个单词
//		reverse(start, end - 1);
//
//		//往下找下一个单词
//		if (*end == ' ')
//		{
//			start = end + 1;
//		}
//		else
//		{
//			start = end;
//		}
//	}
//	
//
//	printf("%s", arr);
//	return 0;
//}

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字
//例如:2+22+222+2222 +22222

//int main()
//{
//	int a = 0;
//	int n = 0;
//
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int ret = 0; //一项
//	for (i = 0; i < n; i++)
//	{
//		//算出一项
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d", sum);
//
//	return 0;
//}

//写一个函数打印arr数组的内容，不使用数组下标，使用指针
//arr是一个整形一维数组

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	//①
//	int* pend = arr + sz - 1;
//	while (p <= pend)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//
//	////②
//	//int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(p + i));
//	//}
//	
//	return 0;
//}

//求出0～100000之间的所有“水仙花数”并输出
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，//如：153=1^3+5^3+3^3，则153是一个“水仙花数”

//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 10000; i++)
//	{
//		//判断一个数是不是自幂数
//		//1.计算n的位数 - n
//		int n = 1;
//		int tmp = i;
//		while (tmp / 10)
//		{
//			n++;
//			tmp /= 10;
//		}
//
//		//2.计算i的每一位的n次方之和
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//
//		//3.判断
//		if (sum == i)
//		{
//			printf("%d ", sum);
//		}
//	}
//	return 0;
//}

//写一个函数，可以逆序一个字符串的内容
//#include <string.h>
//#include <assert.h>
//void reverse(char* str)
//{
//	assert(str != NULL);
//	//可直接用assert(str);代替  若str为空指针，则默认为NULL
//
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef"; //fedcba
//	reverse(arr);
//	printf("%s", arr);
//
//	return 0;
//}

//绘制菱形
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	scanf("%d", &n);
//	int line = n / 2 + 1; //上半部分
//	//绘制上半部分
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//绘制下半部分
//	for (i = 0; i < line - 1; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//
//		for (j = 0; j < 2 * (line - i - 1) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）
//int main()
//{
//	int money = 0;
//	int total = money;
//	int empty = money;
//	scanf("%d", &money);
//	
//	//开始置换瓶子
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d", total);
//
//	return 0;
//}

//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		//从左往右找一个偶数
//		while (left < right && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//从右往左找一个奇数
//		while (left < right && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//}

//打印杨辉三角
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1

//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//
//			//开始计算部分
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//找凶手
//A说：不是我
//B说：是C
//C说：是D
//D说：C在胡说
//已知三个人说了真话，一个人说的是假话
//写一个程序来确定谁到底是凶手

//int main()
//{
//	char killer = 0;
//	//从每个人都是凶手的角度，去遍历一遍，挨个判断他们的话
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c", killer);
//		}
//	}
//	return 0;
//}

//五位运动员跳水比赛，有人让他们预测比赛结果
//A说：B第二，我第三；
//B说：我第二，E第四
//C说：我第一，D第二；
//D说：C最后，我第三
//E说：我第四，A第一
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次

//int main()
//{
//	//枚举出五个人  ——  五个循环套出五个人的名次
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if ((b == 2) + (a == 3) == 1      //每个人中半真半假  那么也就是判断值求和为1
//							&& (b == 2) + (e == 4) == 1
//							&& (c == 1) + (d == 2) == 1
//							&& (c == 5) + (d == 3) == 1
//							&& (e == 4) + (a == 1) == 1
//							)
//						{
//							if (a * b * c * d * e == 120)  //用于限定不重复的情况
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//模拟计算器calc  并且逐渐进行迭代 升级 优化  (能力范围内)
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void menu()
//{
//	printf("***************************\n");
//	printf("**** 1. add     2. sub ****\n");
//	printf("**** 3. mul     2. div ****\n");
//	printf("****      0.exit       ****\n");
//	printf("***************************\n");
//
//}

//版本①
//如果要计算a&b a|b a>>b a<<b a^b呢？
//int main()
//{
//	int input = 0;
//
//	do {
//		menu();
//
//		int x = 0;
//		int y = 0;
//		int ret = 0;
//
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 2:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 3:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 4:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 0:
//			printf("退出程序\n");
//			break;
//
//		default:
//			printf("输入错误，重新输入\n");
//			break;
//		}
//
//	} while (input);
//	return 0;
//}

////版本②  用函数指针数组来调用函数
////函数指针数组的用途：转移表
//int main()
//{
//	int input = 0;
//
//	do {
//		menu();
//		int(*pfarr[5])(int,int) = { NULL,Add,Sub,Mul,Div };  //函数指针数组
//		int x = 0;
//		int y = 0;
//		int ret = 0;
//
//		scanf("%d", &input);
//
//		if (input >= 1 && input <= 4)
//		{
//			//实际调用计算模块
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = pfarr[input](x, y);  //通过函数指针数组来调用函数
//			printf("ret = %d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出程序\n");
//			break;
//		}
//		else
//		{
//			printf("选择错误，重新选择\n");
//		}
//
//	} while (input);
//
//	return 0;
//}

////版本③  回调函数
//int Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d %d", &x, &y);
//	return pf(x, y);
//}
//int main()
//{
//	int input = 0;
//
//	do {
//		menu();
//
//		int ret = 0;
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("%d\n", Calc(Add));
//			break;
//		case 2:
//			printf("%d\n", Calc(Sub));
//			break;
//		case 3:
//			printf("%d\n", Calc(Mul));
//			break;
//		case 4:
//			printf("%d\n", Calc(Div));
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("输入错误，重新选择\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}

////研究库函数qsort();
////void qsort(
////	void* base,  //目标数组的开头
////	size_t num,	 //排序数据元素的个数
////	size_t width, //排序数据中一个元素的大小，单位是字节
////	int(__cdecl* compare)(const void*e1, const void*e2) //是用来比较待排序数据中的两个元素的函数，返回值是int类型 
////													//>0则e1>e2
////);
//
//#include <stdlib.h>
//#include <string.h>
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	//>0 则e1>e2  <0 则e1<e2  增序
//	return *(int*)e1 - *(int*)e2;
//	
//	//降序
//	//return *(int*)e2 - *(int*)e1;
//}
//
//void test1()
//{
//	//整形数据的排序
//	int  arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//排序
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	//打印
//	print_arr(arr, sz);
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
//
//	int sz = sizeof(s) / sizeof(s[0]);
//	//按照年龄来排序
//	//qsort(s, sz, sizeof(s[0]), sort_by_age);
//
//	//按照名字来排序
//	qsort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//void swap(char* buffer1, char* buffer2, int width)
//{
//	//buffer为缓冲区的意思,以后用buf缩写代替
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buffer1;
//		*buffer1 = *buffer2;
//		*buffer2 = tmp;
//		buffer1++;
//		buffer2++;
//	}
//}
//
////模仿qsort()自己写一个冒泡排序
//void bubble_sort(void* base, unsigned int sz, unsigned int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟的排序
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//两个元素的比较
//			//arr[j] > arr[j+1]
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//				//为何强制转化成char*呢？
//				//char* 步长最小，为一个字节，可以通过 (最小的跨度) * (width) 来控制到任意类型(int struct short等等)
//			{
//				//交换
//				//可是不知道具体的类型,该如何交换呢？
//				//可以一个字节一个字节的交换 直到完成一个类型的大小 - 交换两个元素对应位置的字节
//				//比如int类型，交换4次对应的字节，则交换完成两个元素
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void test3()
//{
//	//整形数据的排序
//	int  arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//排序
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	//打印
//	print_arr(arr, sz);
//}
//
//void test4()
//{
//	//使用qsort函数排序结构体数据
//	struct Stu s[3] = { {"zhangsan", 30},{"lisi", 34},{"wangwu", 20} };
//
//	int sz = sizeof(s) / sizeof(s[0]);
//	//按照年龄来排序
//	bubble_sort(s, sz, sizeof(s[0]), sort_by_age);
//	//按照名字来排序
//	//bubble_sort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//
//int main()
//{
//	//test1();//排序整形测试
//	//test2();//排序结构体测试
//	//test3();
//	test4();
//	return 0;
//}

//杨氏矩阵
//题目内容：
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
// 那就不能遍历，不然时间复杂度不符合要求
//如
//1 2 3 
//4 5 6
//7 8 9

//int find_num(int arr[3][3], int* px, int* py, int k)
//{
//	//从右上角开始找  去杂
//	int x = 0;
//	int y = *py - 1;
//	while (x < *px && y >= 0) //防止越界
//	{
//		if (arr[x][y] < k)
//		{
//			x++;//去掉一行
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;//去掉一列
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1; //找到了
//		}
//	}
//	return 0; //找不到
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	//如果找到返回1，找不到返回0
//	int x = 3;
//	int y = 3;
//	//&x,&y
//	//1.传入参数
//	//2.带回值
//
//	int ret = find_num(arr, &x, &y, k);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//		printf("下标是%d %d\n", x, y);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}

//字符串左旋
//题目内容：
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

////①直接左旋
//void string_left_rotate(char* str, int k)
//{
//	int i = 0;
//	int n = strlen(str);
//	for (i = 0; i < k; i++)
//	{
//		//1.每次旋转一个字符
//		char tmp = *str;
//		//2.后边的n-1个字符往前挪动
//		int j = 0;
//		for (j = 0; j < n - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		//3.把tmp放在最后
//		*(str + n - 1) = tmp;
//	}
//}

//#include <assert.h>
////三步反转法
////我理解为 排队 分前后  前面往后转  后面往后转  在整体往后转 等价于  把前面丢到后面去
//
//void reverse(char* left, char* right)
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void string_left_rotate(char str[], int k)
//{
//	assert(str);
//	int n = strlen(str);
//	reverse(str, str + k - 1); //左边翻转
//	reverse(str + k, str + n - 1); //右边翻转
//	reverse(str, str + n - 1); //整体翻转
//}
//
//int main()
//{
//	char arr[10] = "ABCDEF";
//	int k = 4;
//	string_left_rotate(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

//写法①  遍历 穷举
//int is_string_rotate(char* str1, const char* str2)
//{
//	int i = 0;
//	int n = strlen(str1); //5
//
//	for (i = 0; i < n; i++)
//	{
//		//每次都左旋转一个字符
//		char tmp = *str1;
//		//后边的n-1个字符往前挪动
//		int j = 0;
//		for (j = 0; j < n - 1; j++)
//		{
//			*(str1 + j) = *(str1 + j + 1);
//		}
//		//tmp放在最后
//		*(str1 + n - 1) = tmp;
//
//		//每左旋一次，做一次比对
//		if (strcmp(str1, str2) == 0)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}

//#include <assert.h>
////写法②  巧妙一点
//int is_string_rotate(char* str1, const char* str2)  //判断str1是不是str2旋转得来的
//{
//	assert(str1);
//	assert(str2);
//	//若长度不相等，那么肯定不是选装得来的
//	if (strlen(str1) != strlen(str2))
//	{
//		return 0;
//	}
//
//	//1.str1字符串的后边追加一个str1
//	//AABCDAABCD
//	int len = strlen(str1);
//	strncat(str1, str2, len);
//	//2.判断str2是否为str1的字串
//	char* ret = strstr(str1, str2);//strstr的返回值使str1中第一次出现str2的位置  -- 地址
//
//	return ret != NULL; //ret等于NULL即为找不到
//	//等价于
//	/*if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}*/
//}
//
//int main()
//{
//	char arr1[20] = "AABCD";
//	char arr2[] = "BCDAA";
//	int ret = is_string_rotate(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//
//	return 0;
//}

//模拟实现strcat
//#include <assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	//1.找目标字符串中\0的位置
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.追加源字符串，包含\0
//	while (*dest++ = *src++);
//
//	return ret;//返回目标启示地址
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//
//	printf("%s\n", my_strcat(arr1, arr2));
//
//	return 0;
//}

//模拟实现strcmp
//#include <assert.h>
//
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//		{
//			return 0;
//		}
//
//		s1++;
//		s2++;
//	}
//
//	return *s1 - *s2;
//}
//
//int main()
//{
//	char* p = "abbdef";
//	char* q = "abcdef";
//	int ret = my_strcmp(p, q);
//
//	if (ret > 0)
//	{
//		printf("p > q\n");
//	}
//	else if (ret < 0)
//	{
//		printf("p < q\n");
//	}
//	else
//	{
//		printf("p == q\n");
//	}
//	return 0;
//}

//模拟实现strstr
//#include <assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	//实际用s1,s2去查找
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* cp = str1; //用于记录每查找一次的起始位置
//
//	//原本str2就是空字符串呢？
//	if (*str2 == '\0')
//	{
//		return str1;
//	}
//
//	//若str2不是空字符串
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//
//		while (*s1 && *s2 && (*s1 == *s2)) //*s1 *s2没结束  并且两个相同则进入
//		{
//			s1++;
//			s2++;
//		}
//		
//		if (*s2 == '\0')
//		{
//			//返回值为str2在str1中的位置
//			return cp;//思考：是否需要强制类型转换成char*?
//		}
//
//		//若此轮没找到,则cp++,进入下一个字符作为起始位置开始查找
//		cp++;
//	}
//	
//	return NULL;//没找到则返回空指针
//}
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bbc";
//	//在arr1中查找是否包含arr2数组
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了:%s\n", ret);
//	}
//	return 0;
//}

//研究strtok
//int main()
//{
//	char arr[] = "11947361@qq.com";
//	char* p = "@";
//	char tmp[30] = { 0 };
//	strcpy(tmp, arr);
//	char* ret = NULL;
//
//	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//
//	//ret = strtok(tmp, p);
//	//printf("%s\n", ret);
//
//	//ret = strtok(NULL, p);
//	//printf("%s\n", ret);
//
//	return 0;
//}

//研究strerror
//int main()
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));
//	printf("%s\n", strerror(5));
//	return 0;
//}

//模拟实现memcpy，memcpy函数应该拷贝不重叠的内存
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, int num)
//{
//	assert(dest && src);
//
//	void* ret = dest;//用于保存返回值信息
//
//	while (num--) //在循环条件里用这种形式还是挺有意思的，值得学习:)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1, 20);
//	return 0;
//}

//模拟实现memmove,memmove函数可以处理内存重叠的情况
//#include <assert.h>
//void* my_memmove(void* dest, void* src, int num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if (dest < src)
//	{
//		//从前往后
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//从后往前
//		while (num--) //如果num一开始为20,第一次进来的时候num已经变成19，那么可以控制到第二十个字符，以此类推
//		{
//			//指向位置完全受num控制
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 2, arr1, 20);
//
//	return 0;
//}

//打印用*组成的X型图案
//多组输入，一个整数(2~20),表示输出的行数，也表示组成X的反斜线和正斜线的长度
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if (i == j)
//				{
//					printf("*");
//				}
//				else if (i + j == n - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//有7位考官，从键盘输入若干组成绩，每军组个分数(百分制)，去掉一个最高分和一个最低分，输出每组的平均成绩
//输入描述:一行，输入7个整数(0~100)，代表7个成绩，用空格分隔。
//输出描述:一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行

//int main()
//{
//	int score = 0;
//	int sum = 0;
//	int i = 0;
//	//分数区间为0-100
//	int max = 0;
//	int min = 100;
//	//这样一轮循环就可以操作完成，省去了多次遍历，录入，求最大值，最小值的步骤
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &score);
//		sum += score;
//
//		if (score > max)
//		{
//			max = score;
//		}
//
//		if (score < min)
//		{
//			min = score;
//		}
//	}
//
//	printf("%.2f", (sum - max - min) / 5.0);
//
//	return 0;
//}

//输入年份和月份，计算这一年这个月有多少天
//输入描述：多组输入，一行有两个整数，分别表示年份和月份，用空格分隔
//输出描述：针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天

//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	while (scanf("%d %d", &year, &month) != EOF)
//	{
//		day = days[month];
//		
//		if (month == 2)
//		{
//			//判断是否闰年
//			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//			{
//				day++;
//			}
//		}
//		printf("%d\n", day);
//	}
//
//	return 0;
//}

//模拟实现atoi
//#include <ctype.h>
//#include <limits.h>
//
////State 记录的是my_atoi返回的值是否是合法转化的值
//enum State
//{
//	INVALID,
//	VALID
//};
//
//enum State state = INVALID;
//
//int my_atoi(char* p)
//{
//	int flag = 1;
//	//空指针
//	if (p == NULL)
//	{
//		return 0;
//	}
//
//	//空字符串
//	if (*p == '\0')
//	{
//		return 0;
//	}
//
//	//跳过空白字符
//	while (isspace(*p))
//	{
//		p++;
//	}
//
//	//判断正负号+/-
//	if (*p == '+')
//	{
//		flag = 1;
//		p++;
//	}
//	else if (*p == '-')
//	{
//		flag = -1;
//		p++;
//	}
//
//	//处理数字字符的转换
//	long long n = 0;
//	while (isdigit(*p))
//	{
//		n = n * 10 + flag * (*p - '0');
//		//超出int可容纳上限时，也为非法值
//		if (n > INT_MAX || n < INT_MIN)
//		{
//			return 0;
//		}
//		p++;
//	}
//	//怎样退出循环的呢？
//	if (*p == '\0')
//	{
//		//合法数值
//		state = VALID;
//		return n;
//	}
//	else
//	{
//		state = VALID;
//		return (int)n;
//	}
//}
//
//int main()
//{
//	//要处理的异常状态
//	//1.空指针 √
//	//2.空字符串 √
//	//3.遇到了非数字字符 √
//	//4.超出范围 √
//	const char* p = "     -123a"; //常量字符串本来就不可修改，所以加上const更合理一些
//	int ret = my_atoi(p);
//
//	if (state == VALID)
//	{
//		printf("正常的转换:%d\n", ret);
//	}
//	else
//	{
//		printf("非法的转换:%d\n", ret);
//	}
//
//	return 0;
//}

//例如:1 2 3 4 5 1 2 3 4
//一个数组中只有两个数字是出现了一次，其他所有数字都出现了两次
//编写一个函数找出这两个只出现一次的数字

//void Find(int arr[], int sz, int* px, int* py)
//{
//	//1.所有数字异或
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//计算ret的哪一位为1(分组方法)
//	//为什么要这样呢？
//	//把所有数字异或，相同的异或出来为0，剩下两个不同的，那么相同为0，相异为1
//	//第一个出现1的地方就是他们二进制位第一个不同的地方
//
//	int pos = 0;//表示ret第pos位为1(下标）
//	for (i = 0; i < 32; i++)
//	{
//		if ((ret >> i) & 1 == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	
//	//把从地位到高位第pos位为1，为0的放在两个组
//	int num1 = 0;
//	int num2 = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if ((arr[i] >> pos) & 1 == 1)
//		{
//			num1 ^= arr[i];
//		}
//		else
//		{
//			num2 ^= arr[i];
//		}
//	}
//	//循环结束时，num1,num2就是找到的两个值
//	*px = num1;
//	*py = num2;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
//	//5:00000101
//	//6:00000110
//	//1.分组
//	//2.分组的要点：5和6必须在不同的组
//	//3.找出这两个只出现一次的数字
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int x = 0;
//	int y = 0;
//
//	Find(arr, sz, &x, &y);
//
//	printf("%d %d\n", x, y);
//
//	return 0;
//}

//写一个宏，将一个整数的二进制的奇数位和偶数位互换
//如何实现？
//假设第一位为1，则奇数位左移一位，偶数位右移一位


//#define SWAP(N) ((N & 0xaaaaaaaa)>>1) + ((N & 0x55555555)<<1)
////          获取偶数位，并且右移一位 || 获取奇数位，并且左移一位
////偶数位 + 奇数位，则为调整后的数字
//
//int main()
//{
//	//原理分析  --  按位与
//	//10101010101010101010101010101010 从原数字从拿出偶数位 -- 原偶数位全部保留原本状态，奇数位置零  0xaaaaaaaa
//	//01010101010101010101010101010101 从原数字用拿出奇数位 -- 原奇数位全部保留原本状态，偶数位置零  0x55555555
//	
//	int num = 10;
//	int ret = SWAP(num);
//
//	printf("%d\n", ret);
//
//	return 0;
//}

//模拟实现offsetof  -- 写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明

//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
////
//#define OFFSETOF(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)
////假设结构体第一位在0地址处
////往后访问成员的时候，成员的地址
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct A, a));
//	printf("%d\n", OFFSETOF(struct A, b));
//	printf("%d\n", OFFSETOF(struct A, c));
//	printf("%d\n", OFFSETOF(struct A, d));
//
//	return 0;
//}

//题目描述：
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如：第一个字符串是"They are students."，第二个字符串是”aeiou"。删除之后的第一个字符串变成"Thy r stdnts."。
//保证两个字符串的长度均不超过100。
//输入描述：输入两行，每行一个字符串。
//输出描述：输出删除后的字符串。

//int main()
//{
//	char arr1[100] = { 0 };
//	char arr2[100] = { 0 };
//	int i = 0;
//	int j = 0;
//	int t = 0;
//	int count = 0;
//	gets(arr1);
//	gets(arr2);
//	int sz = strlen(arr1);
//
//	for (i = 0; arr2[i] != '\0'; i++)//从arr2中每次拿出一个字符出来比较
//	{
//		for (j = 0; arr1[j] != '\0'; j++)//和arr1中的每个字符比较
//		{
//			if (arr2[i] == arr1[j])//找到了相等的
//			{
//				//把后面的数据往后面搬，即可实现删除效果
//				for (t = j; t < sz - count; t++)
//				{
//					arr1[t] = arr1[t + 1];
//				}
//				count++;
//				j--;
//			}
//		}
//	}
//
//	puts(arr1);
//
//	return 0;
//}

//题目描述：
//对于一个较大的整数 N(1 <= N <= 2, 000, 000, 000)
//比如 980364535，我们常常需要一位一位数这个数字是几位数，但是如果在这 个数字每三位加一个逗号，它会变得更加易于朗读。
//因此，这个数字加上逗号成如下的模样：980, 364, 535请写一个程序帮她完成这件事情
//输入描述：一行一个整数 N
//输出描述：一行一个字符串表示添加完逗号的结果

//int main()
//{
//	int n = 0;
//	int control = 0;
//	scanf("%d", &n);
//	char arr[100] = { 0 };
//
//	sprintf(arr, "%d", n);
//	int sz = strlen(arr);
//	int symbol_num = sz / 3 - 1;
//	char* pend = arr + sz - 1;//最开始指向\0
//
//	//从后往前搬，每三个中间插一个,
//	while (pend != arr)
//	{
//		if (control % 3 == 0 && control != 0)
//		{
//			*(pend + symbol_num) = ',';
//			symbol_num--;
//		}
//		*(pend + symbol_num) = *pend;
//		pend--;
//		control++;
//	}
//
//	puts(arr);
//
//	return 0;
//}

//实现一个函数，将一个字符串中的每个空格替换成"%20"
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy

//#include <ctype.h>
//int main()
//{
//	int spacecnt = 0;
//	char arr[30] = "We Are Happy";
//	char* p = arr;
//	int length = strlen(arr);
//	//数空格
//	while (*p)
//	{
//		if (isspace(*p))
//		{
//			spacecnt++;
//		}
//		p++;
//	}
//
//	int newlen = length + 2 * spacecnt;
//	int end1 = length;
//	int end2 = newlen;
//
//	while (end1 != end2)
//	{
//		if (arr[end1] != ' ')
//		{
//			arr[end2--] = arr[end1--];
//		}
//		else
//		{
//			arr[end2--] = '0';
//			arr[end2--] = '2';
//			arr[end2--] = '%';
//			end1--;
//
//		}
//	}
//
//	printf("%s", arr);
//
//	return 0;
//}

//在一个斐波那契数列中，给处一个数N，算出离它最近的一个斐波那契数和它的距离

//#include <math.h>
//int main()
//{
//	int a = 0;
//	int b = 1;
//	int c = 1;
//	int n = 0;
//
//	scanf("%d", &n);
//
//	while (1)
//	{
//		if (b == n || a == n)
//		{
//			printf("0\n");
//			break;
//		}
//		else if (b > n)
//		{
//			printf("%d\n", (abs(n - a) < abs(n - b)) ? abs(n - a) : abs(n - b));
//			break;
//		}
//		else
//		{
//			//如果n不在原来的a b之间，就让a b往后走，直到可以夹住n
//			//下面为斐波那契计算
//			a = b;
//			b = c;
//			c = a + b;
//		}
//	}
//
//	return 0;
//}

//利用可变参数列表，做一个寻找最大值的函数
//#include <stdarg.h>
//
////此处,num表示传入参数的个数
//int FindMax(int num, ...)
//{
//	int i = 0;
//
//	va_list p_ret;  //定义一个char*类型的指针，此指针变量可访问可变参数部分的变量
//	va_start(p_ret, num);//使p_ret指向可变参数部分,已经指向可变参数部分的第一个数据了
//	int max = va_arg(p_ret, int);//根据类型，获取可变参数变量列表中的第一个数据，并且此时p_ret已经指向可变参数部分的下一个数据
//
//	for (i = 0; i < num - 1; i++)  //获取并比较其他的
//	{
//		int tmp = va_arg(p_ret, int);//拿出当前指向数据，并且p_ret向后偏移
//		if (tmp > max)
//		{
//			max = tmp;
//		}
//	}
//
//	va_end(p_ret);
//
//	return max;
//}
//
//int main()
//{
//	printf("%d\n", FindMax(5, 13, 11, 65, 23, 24));
//	return 0;
//}

//消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。编写代码找出那个缺失的整数。
//要求：时间复杂度在O(N)内

//思路1：类似哈希表  O(N)
//int FindMissingNum(int arr[], int sz)
//{
//	int* hash = (int*)malloc((sz + 1) * sizeof(int));//malloc出一个额外数组
//	if (NULL == hash)  //开辟失败的情况
//	{
//		perror("main");
//		exit(1);
//	}
//	memset(hash, -1, sz * sizeof(int));//以字节为单位设置内存  --  初始化数组为-1
//
//	int i = 0;
//
//	//遍历原有数组，遇到一个数字，就在哈希表对应位置+1
//	for (i = 0; i < sz; i++)
//	{
//		hash[arr[i]] += 1;
//	}
//
//	//遍历数组，哪个位置为-1,那这个位置的下标就是缺失的数字
//	for (i = 0; i < sz + 1; i++)
//	{
//		if (-1 == hash[i])
//		{
//			free(hash);
//			hash = NULL;
//			return i;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 0,1,3,5,7,2,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	printf("%d\n", FindMissingNum(arr,sz));
//	return 0;
//}

//思路2：用异或  O(N)

//int FindMissingNum(int arr[], int sz)
//{
//	int i = 0;
//	int ret = 0;
//	//先和缺失数组异或
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//再和原数组异或
//	for (i = 0; i < sz + 1; i++)
//	{
//		ret ^= i;
//	}
//	
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 0,1,3,5,7,2,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	printf("%d\n", FindMissingNum(arr, sz));
//	return 0;
//}

//思路3：排序 + 二分查找  冒泡O(N^2)  快排O(N*logN) - 效率相对较低
//int main()
//{
//
//	return 0;
//}

//思路4：公式计算 - 算出原数组 - 缺失数组 = 缺失数字    O(N)

//int FindMissingNum(int arr[], int sz)
//{
//	int sum = 0;
//	int i = 0;
//
//	for (i = 0; i < sz + 1; i++)
//	{
//		sum += i;
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		sum -= arr[i];
//	}
//
//	return sum;
//}
//
//int main()
//{
//	int arr[] = { 0,1,3,5,7,2,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	printf("%d\n", FindMissingNum(arr, sz));
//	return 0;
//}

//轮转数组  --  给一个数组，将数组中的元素向右轮转k个位置
//尽可能多的解决方案
//要求：空间复杂度为O(1),时间复杂度O(N)

//思路1：每次旋转一个，旋转k次 - O(N*K)

//void rotate(int arr[], int sz, int k)
//{
//	//如果k>sz怎么办？
//	k %= sz;
//
//	while (k--)
//	{
//		//先把第一个往后放
//		int tmp = arr[0];
//
//		//再把后面的往后搬
//		int i = 0;
//		for (i = 0; i < sz - 1; i++)
//		{
//			arr[i] = arr[i + 1];
//		}
//
//		arr[sz - 1] = tmp;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 3;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//	rotate(arr, sz, k);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//思路2：以空间换时间 - 拿一个新的数组出来 - O(N)

//void rotate(int arr[], int sz, int k)
//{
//	int i = 0;
//	int j = 0;
//	int* p = (int*)malloc(sizeof(int) * sz);
//	if (NULL == p) //判断是否开辟好空间
//	{
//		perror("main");
//		exit(1);
//	}
//	
//	//将前k个放在新数组后面
//	for (i = 0; i < k; i++)
//	{
//		p[sz - k + i] = arr[i];
//	}
//
//	//将后n-k个放在新数组前面
//	for (i = k, j = 0; i < sz; i++, j++)
//	{
//		p[j] = arr[i];
//	}
//
//	//覆盖原数组
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = p[i];
//	}
//
//	free(p);
//	p = NULL;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 3;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//	rotate(arr, sz, k);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//思路3：三步翻转法 - 最优解法  时间复杂度O(N)   空间复杂度O(1)

//void reverse(int arr[], int* left, int* right)
//{
//	while (left < right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void rotate(int arr[], int sz, int k)
//{
//	k %= sz;
// 
//	//先反转前k个
//	reverse(arr, arr, arr + k - 1);
//	//再翻转后n-k个
//	reverse(arr, arr + k, arr + sz - 1);
//	//全体反转
//	reverse(arr, arr, arr + sz - 1);
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 3;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//	rotate(arr, sz, k);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//移除元素 -- 给一个数组nums和一个值val,需要原地移除所有数值等于val的元素，并返回移除后数组的新长度
//要求：不能使用额外的数组空间  --  空间复杂度O(1)  时间复杂度O(N)
//元素的顺序可以改变，不需要考虑数组中超出新长度后面的元素

//思路1：覆盖删除  --  O(N^2)
//思路2：保留不是val的值，挪到新数组  --  空间复杂度O(N)
//思路3: 双指针，保留不是val的值，覆盖前面的值

//int RemoveElement(int arr[], int sz, int val)
//{
//	int src = 0;
//	int dest = 0;
//
//	while (src < sz)
//	{
//		if (arr[src] == val)
//		{
//			src++;
//		}
//		else
//		{
//			arr[dest++] = arr[src++];
//		}
//	}
//
//	return dest;
//}
//
//int main()
//{
//	int arr[] = { 3,2,2,3,1,5,2,6,7,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	printf("%d\n", RemoveElement(arr, sz, 2));
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//删除有序数组中的重复项  --  去重算法
//给定一个升序数组nums,请原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度
//元素的相对顺序应该保持一致

//仍然可用双指针
//int RemoveDuplicates(int arr[], int sz)
//{
//	int src = 1;
//	int dest = 0;
//
//	while (src < sz)
//	{
//		if (arr[dest] == arr[src])
//		{
//			src++;
//		}
//		else
//		{
//			arr[++dest] = arr[src++];
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 0,0,1,1,1,2,2,3,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	RemoveDuplicates(arr, sz);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//合并两个有序数组
//给定两个非递减顺序排列的整数数组nums1和nums2
//m、n分别表示nums1和nums2中元素的数目
//请合并nums2到nums1中，使合并后的数组同样按非递减顺序排列
//要求：时间复杂度 - O(N+M)

//void merge(int nums1[], int nums2[], int m, int n)
//{
//	int end1 = m - 1;
//	int end2 = n - 1;
//	int end = m + n - 1;
//
//	while (end1 >= 0 && end2 >= 0) //有一个结束就结束了   是且 - &&
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end--] = nums1[end1--];
//		}
//		else
//		{
//			nums1[end--] = nums2[end2--];
//		}
//	}
//
//	//如果是end2结束，end1没结束，则不需要处理
//	//因为end1就在nums1前面，且顺序合乎要求
//
//	while (end2 > 0) //如果是end2没结束，那就把end2剩余的放到nums1中最前面
//	{
//		nums1[end--] = nums2[end2--];
//	}
//
//}
//
//int main()
//{
//	int nums1[6] = { 1,2,3 };
//	int nums2[3] = { 2,5,6 };
//	int m = 3;
//	int n = 3;
//
//	merge(nums1, nums2, m, n);
//
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", nums1[i]);
//	}
//	return 0;
//}

//移除链表元素
//给定一个链表的头节点head和一个整数val
//请删除链表中所有满足Node.val == val的节点，并返回新的头节点
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}ListNode;
//
////方法一  --  直接干
//ListNode* removeElements(ListNode* head, int val) 
//{
//	struct ListNode* cur = head;
//	struct ListNode* pre = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			if (head == cur)
//			{
//				//头删
//				head = head->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				//删除
//				pre->next = cur->next;
//				free(cur);
//				cur = pre->next;
//			}
//		}
//		else
//		{
//			//更新信息
//			pre = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//
////方法二  --  遍历原链表，把不是val的节点拿出来进行尾插到新链表
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* tail = NULL;
//	head = NULL;  //防止全是要删除的，head会成为野指针
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			struct ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//		}
//		else
//		{
//			if (tail == NULL)
//			{
//				head = tail = cur;
//			}
//			else
//			{
//				//尾插
//				tail->next = cur;
//				tail = tail->next;
//			}
//
//			cur = cur->next;
//		}
//	}
//
//	if (tail)  //防止是空链表，tail原本是NULL，无法访问
//	{
//		tail->next = NULL;  //防止最后一个要删，删完后，新链表最后一个节点的next是野指针
//	}
//
//	return head;
//}
//
////方法三  --  哨兵位头节点
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* tail = NULL;
//	struct ListNode* cur = head;
//
//	//哨兵位的头节点
//	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	tail->next = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			struct ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//		}
//		else
//		{
//			tail->next = cur;
//			tail = tail->next;
//
//			cur = cur->next;
//		}
//	}
//
//	tail->next = NULL;
//
//	//释放哨兵位头节点，否则内存溢出
//	struct ListNode* del = head;
//	head = head->next;
//	free(del);
//
//	return head;
//}

//反转链表
//给定单链表的头节点head，请反转链表，并返回反转后的链表
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
// 
////方法一  --  头插
//struct ListNode* reverseList(struct ListNode* head) {
//	struct ListNode* cur = head;
//	struct ListNode* newhead = NULL;
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//		//头插
//		cur->next = newhead;
//		newhead = cur;
//
//		cur = next;
//	}
//
//	return newhead;
//}
////方法二  --  指针的方向颠倒
//struct ListNode* reverseList(struct ListNode* head) 
//{
//
//	if (head == NULL)
//	{
//		return NULL;
//	}
//
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* n3 = head->next;
//
//	while (n2)
//	{
//		//倒指向
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3)
//		{
//			n3 = n3->next;
//		}
//	}
//
//	return n1;
//}


//链表的中间节点
//给定一个头节点位head的非空单链表，返回链表的中间节点
//如果有两个中间节点，则返回第二个中间节点
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
////方法  --  快慢指针
//struct ListNode* middleNode(struct ListNode* head) {
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//
//	while (fast && fast->next)  //不可以写fast->next && fast  --  思考为什么？
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	return slow;
//}

//链表中倒数第K个节点
//输入一个链表，输出该链表中倒数第k个节点
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
////方法  --  快慢指针  --  fast比slow先走k
//struct ListNode* getKthFromEnd(struct ListNode* head, int k)
//{
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//
//	while (k--)  //k-- 是循环k次     --k是循环k-1次
//	{
//		//fast还没走出k步，链表没有k步长
//		if (fast == NULL)
//		{
//			return NULL;
//		}
//
//		//fast先走k步
//		fast = fast->next;
//	}
//
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//
//	return slow;
//}

//合并两个有序链表
//将两个升序链表合并为一个新的升序链表并返回
//新链表是通过拼接给定的两个链表的所有节点组成的
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
//
////方法：归并  --  从头比较，取小的尾插的新链表
////版本一：不带哨兵位的头节点
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	if (list1 == NULL)
//	{
//		return list2;
//	}
//	if (list2 == NULL)
//	{
//		return list1;
//	}
//
//	struct ListNode* tail = NULL;
//	struct ListNode* head = NULL;
//
//	while (list1 && list2)
//	{
//		if (list1->val > list2->val)
//		{
//			if (tail == NULL)
//			{
//				head = tail = list2;
//			}
//			else
//			{
//				tail->next = list2;
//				tail = tail->next;
//			}
//
//			list2 = list2->next;
//		}
//		else
//		{
//			if (tail == NULL)
//			{
//				head = tail = list1;
//			}
//			else
//			{
//				tail->next = list1;
//				tail = tail->next;
//			}
//
//			list1 = list1->next;
//		}
//	}
//
//	if (list1)
//	{
//		tail->next = list1;
//	}
//
//	if (list2)
//	{
//		tail->next = list2;
//	}
//
//	return head;
//}
//
////版本二：带哨兵位的头节点
////这个例子可以深切体会到哨兵位头节点的好处
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	struct ListNode* tail, * head;
//	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	head->next = NULL;
//
//	while (list1 && list2)  //有一个为空，则结束
//	{
//		if (list1->val > list2->val)
//		{
//			tail->next = list2;
//			tail = tail->next;
//
//			list2 = list2->next;
//		}
//		else
//		{
//			tail->next = list1;
//			tail = tail->next;
//
//			list1 = list1->next;
//		}
//	}
//
//	if (list1)
//	{
//		tail->next = list1;
//	}
//
//	if (list2)
//	{
//		tail->next = list2;
//	}
//
//	struct ListNode* list = head->next;
//	free(head);
//	return list;
//}

//链表分割
//有一链表的头指针 ListNode* pHead，给一定值x
//编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* partition(struct ListNode* pHead, int x)
//{
//	struct ListNode* greaterhead, * greatertail, * lesshead, * lesstail;
//	//带哨兵位头节点
//	greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	greatertail->next = NULL;
//	lesstail->next = NULL;
//
//	struct ListNode* cur = pHead;
//	while (cur)
//	{
//		if (cur->val < x)
//		{
//			//比x小的尾插入到第一个链表
//			lesstail->next = cur;
//			lesstail = lesstail->next;
//		}
//		else
//		{
//			//比x大的尾插入第二个链表
//			greatertail->next = cur;
//			greatertail = greatertail->next;
//		}
//
//		cur = cur->next;
//	}
//	//相连临界头尾
//	lesstail->next = greaterhead->next;
//	greatertail->next = NULL;  //将尾节点置空
//
//	struct ListNode* head = lesshead->next;
//	free(lesshead);
//	free(greaterhead);
//
//	return head;
//}

//回文链表
//判断链表是否为回文结构  --  中心对称
//要求：时间复杂度：O(N)  空间复杂度：O(1)
//思路：找中间节点，再逆置，再比较
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* MiddleNode(struct ListNode* head)
//{
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//
//	while (fast && fast->next)  //有一个结束就结束
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	return slow;
//}
//
//struct ListNode* ReverseList(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* newhead = NULL;
//	//头插
//	while (cur)
//	{
//		//保留cur下一个信息
//		struct ListNode* next = cur->next;
//		//头插
//		cur->next = newhead;
//		newhead = cur;
//
//		cur = next;
//	}
//
//	return newhead;
//}
//
//int isPalindrome(struct ListNode* head)
//{
//	//先找中间节点
//	struct ListNode* middle = MiddleNode(head);
//	//再从中间节点逆置
//	struct ListNode* rhead = ReverseList(middle);
//
//	//把头和逆置后的头往后作比较
//	while (rhead)  //有一个结束就结束
//	{
//		if (head->val == rhead->val)
//		{
//			head = head->next;
//			rhead = rhead->next;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	return 1;
//}
//
// int main()
// {
// 	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n1);
//
// 	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n2);
//
// 	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n3);
//
// 	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n4);
//
// 	n1->val = 1;
// 	n2->val = 2;
// 	n3->val = 2;
// 	n4->val = 1;
//
// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = n4;
// 	n4->next = NULL;
//
//
//	isPalindrome(n1);
// 	return 0;
// }

//相交链表
//给你两个单链表的头节点 headA 和 headB
//找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//	//防止有空链表，则无相交
//	if (headA == NULL || headB == NULL)
//	{
//		return NULL;
//	}
//
//	struct ListNode* curA = headA, * curB = headB;
//	//按下面那样计算长度会少一个，虽然不打紧，求的是A-B的差值，但是都从1开始无妨
//	int lenA = 1;
//	int lenB = 1;
//	//求长度顺便找尾巴
//	while (curA->next)
//	{
//		lenA++;
//		curA = curA->next;
//	}
//
//	while (curB->next)
//	{
//		lenA++;
//		curB = curB->next;
//	}
//
//	//此时curA curB均指向两段链表最末尾
//	//比较末尾是否地址相同，若末尾不相同，肯定不相交
//	if (curA != curB)
//	{
//		return NULL;
//	}
//
//	//必然会有相交
//	//求第一个交点
//	//这是一个技巧性编程，替代了if else判断lenA和lenB谁大谁小
//	struct ListNode* shortlist = headA;
//	struct ListNode* longlist = headB;
//	if (lenA > lenB)
//	{
//		longlist = headA;
//		shortlist = headB;
//	}
//
//	int gap = abs(lenA - lenB);
//
//	//长的先走gap步
//	while (gap--)  //gap--走gap步    --gap走(gap-1)步
//	{
//		longlist = longlist->next;
//	}
//
//	//比地址，找相同
//	while (longlist != shortlist)
//	{
//		//不同则往下走
//		longlist = longlist->next;
//		shortlist = shortlist->next;
//	}
//
//	//找到相同地址了
//	return longlist;
//}
//
// int main()
// {
// 	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n1);
//
// 	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n2);
//
// 	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n3);
//
// 	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
// 	assert(n4);
//
// 	n1->val = 1;
// 	n2->val = 2;
// 	n3->val = 2;
// 	n4->val = 1;
//
// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = n4;
// 	n4->next = NULL;
//
//	struct ListNode* ret = getIntersectionNode(n1, n2);
//
// 	return 0;
// }

//环形链表
//给你一个链表的头节点 head ，判断链表中是否有环
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
//
//int hasCycle(struct ListNode* head)
//{
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//
//	//快慢指针  --  龟兔赛跑
//	while (fast && fast->next)  //如果没环，则一定会结束
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//
//		if (slow == fast)  //若有环，则快指针一定会追上慢指针
//		{
//			//追上，则说明有环  --  有环才能追上
//			return 1;
//		}
//	}
//
//	return 0;
//}

//环形链表2
//给定一个链表的头节点head,返回链表开始入环的第一个节点。如果链表无环，则返回 null
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
//
////理论推导
////L = (N-1)*C + (C-X)
////结论：一个指针从meet开始走，一个指针从head开始走，他们会在入口点相遇
//struct ListNode* detectCycle(struct ListNode* head)
//{
//	//找相遇点
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//
//	while (fast && fast->next)  //结束则代表链表不含环
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//
//		if (slow == fast)
//		{
//			//找到相遇点
//			struct ListNode* meet = slow;
//			while (meet != head)
//			{
//				//meet head都往后走
//				meet = meet->next;
//				head = head->next;
//			}
//
//			return meet;
//		}
//	}
//
//	return NULL;
//}

//复制带随机指针的链表
//给定一个长度为n的链表，每个节点包含一个额外增加的指针random，该指针可以指向链表中的任何节点或空节点
//构造这个链表的深拷贝  --  结构完全相同
//struct Node
//{
//	int val;
//	struct Node* next;
//	struct Node* random;
//};
//
//struct Node* copyRandomList(struct Node* head)
//{
//	//1.copy节点链接在源节点的后面
//	struct Node* cur = head;
//	while (cur)
//	{
//		//每次开辟一个新节点
//		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
//		copy->val = cur->val;
//
//		copy->next = cur->next;
//		cur->next = copy;
//
//		cur = copy->next;  //调整cur指向原链表下一位置
//	}
//	//2.copy->random = cur->random->next
//	cur = head;
//	while (cur)
//	{
//		struct Node* copy = cur->next;
//		if (cur->random == NULL)
//		{
//			copy->random = NULL;
//		}
//		else
//		{
//			copy->random = cur->random->next;
//		}
//
//		cur = copy->next;
//	}
//	//3.拷贝节点解下来，链接到一起。恢复原链表
//	cur = head;
//	//尾插  --  带哨兵位头节点
//	struct Node* copyHead, * copyTail;
//	copyHead = copyTail = (struct Node*)malloc(sizeof(struct Node));
//	copyTail->next = NULL;
//
//	while (cur)
//	{
//		struct Node* copy = cur->next;
//		struct Node* next = copy->next;
//
//		//尾插
//		copyTail->next = copy;
//		copyTail = copyTail->next;
//
//		cur->next = next;
//		cur = next;
//	}
//
//	struct Node* del = copyHead;
//	copyHead = copyHead->next;
//	free(del);
//
//	return copyHead;
//}

//给定一个只包括(){}[]的字符串s，判断字符串是否有效
//有效字符串需满足：
//1.左括号必须用相同类型的右括号闭合
//2.左括号必须以正确的顺序闭合
//3.每个右括号都有一个对应的相同类型的左括号
//用栈实现
//
//typedef char STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}Stack;
//
//void StackInit(Stack* ps);
//void StackDestroy(Stack* ps);
//void StackPush(Stack* ps, STDataType x);
//void StackPop(Stack* ps);
//STDataType StackTop(Stack* ps);
//bool isStackEmpty(Stack* ps);
//int StackSize(Stack* ps);
//
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->top = ps->capacity = 0;
//}
//
//void StackPush(Stack* ps, STDataType x)
//{
//	assert(ps);
//
//	//检测扩容
//	if (ps->top == ps->capacity)
//	{
//		ps->capacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity);
//		if (tmp == NULL)
//		{
//			perror("realloc");
//			exit(1);
//		}
//		ps->a = tmp;
//	}
//
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	assert(!isStackEmpty(ps));
//
//	ps->top--;  //访问不到这个数据即可视为删除
//}
//
//STDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	assert(!isStackEmpty(ps));
//
//	return ps->a[ps->top - 1];
//}
//
//bool isStackEmpty(Stack* ps)
//{
//	assert(ps);
//
//	return ps->top == 0;
//}
//
//int StackSize(Stack* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}
//
//bool isValid(char* s)
//{
//	Stack st;
//	StackInit(&st);
//
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			if (isStackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//
//			if (top == '(' && *s == ')'
//				|| top == '[' && *s == ']'
//				|| top == '{' && *s == '}')
//			{
//				s++;
//			}
//			else
//			{
//				StackDestroy(&st);
//				return false;
//			}
//		}
//	}
//
//	bool ret = isStackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//int main()
//{
//	char s[] = "()";
//	if (isValid(s))
//	{
//		printf("true\n");
//	}
//	else
//	{
//		printf("false\n");
//	}
//
//	return 0;
//}

//用队列实现栈
//仅使用两个队列实现一个后入先出的栈
//并支持普通栈的全部四种操作 - push,pop,top,empty
//双队列实现

//typedef int QDataType;
////每个队列节点
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QNode;
////用于维护每个队列
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//}Queue;
//
//void QueueInit(Queue* pq);
//void QueueDestroy(Queue* pq);
//void QueuePush(Queue* pq, QDataType x);
//void QueuePop(Queue* pq);
//QDataType QueueFront(Queue* pq);
//QDataType QueueBack(Queue* pq);
//bool isQueueEmpty(Queue* pq);
//int Queuesize(Queue* pq);
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("malloc");
//		exit(1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->head == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		//尾插
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!isQueueEmpty(pq));
//	//1.一个节点
//	if (pq->head == pq->tail)
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		//2.多个节点
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//}
//
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!isQueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!isQueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//bool isQueueEmpty(Queue* pq)
//{
//	assert(pq);
//
//	return pq->head == NULL;
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	int size = 0;
//
//	while (cur)
//	{
//		size++;
//		cur = cur->next;
//	}
//
//	return size;
//}
//
//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&obj->q1);
//	QueueInit(&obj->q2);
//
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//	if (!isQueueEmpty(&obj->q1))
//	{
//		//向q1压入数据
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		//向q2压入数据
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj)
//{
//	Queue* emptyQ = &obj->q1;
//	Queue* nonEmptyQ = &obj->q2;
//	if (!isQueueEmpty(&obj->q1))
//	{
//		emptyQ = &obj->q2;
//		nonEmptyQ = &obj->q1;
//	}
//
//	//除了队尾数据，都从nonempty搬至empty
//	while (QueueSize(nonEmptyQ) > 1)
//	{
//		QueuePush(emptyQ, QueueFront(nonEmptyQ));
//		QueuePop(nonEmptyQ);
//
//	}
//
//	//只剩队尾数据
//	int top = QueueFront(nonEmptyQ);
//	QueuePop(nonEmptyQ);
//
//	return top;
//}
//
//int myStackTop(MyStack* obj)
//{
//	if (!isQueueEmpty(&obj->q1))
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//	return isQueueEmpty(&obj->q1) && isQueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//
//	free(obj);
//}