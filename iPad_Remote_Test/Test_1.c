#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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

