#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>>

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

////��ʾ����ַ��������ƶ������м���
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
//		Sleep(200);//˯��1s�����ó���1s�����
//		system("cls");//�����Ļ
//		left++;
//		right--;
//	}
//	printf("%s\n", exam);
//
//	return 0;
//}

//��д����ʵ�֣�ģ���û���½�龰������ֻ�ܵ�¼����
//#include <string.h>
//int main()
//{
//	//�ٶ�����Ϊ123456
//
//	int i = 0;//��¼���� �������ƴ���
//	char password[20] = { 0 };//�������볤�����Ϊ20
//	for (i = 0; i < 3; i++)
//	{
//		printf("�������¼����:>");
//		scanf("%s", password);
//		//if(password == "123456") --err �����ַ����Ƚϣ�������==��Ӧ��ʹ��strcap��string compare��
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("������ȷ������ɹ�");
//			break;
//		}
//		else
//		{
//			printf("�������������");
//		}
//	}
//
//	return 0;
//}

//дһ��������Ϸ
/*˼·��1.�Զ�����1-100֮��������
		2.������
			(1)�¶��ˣ���ϲ�㣬��Ϸ����
			(2)�´��ˣ�����ߴ��˻���С�ˣ�������
		3.��Ϸһֱ���У������˳���Ϸ*/

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
		//	//���������������ʱ������
		//	int num = rand() % 100 + 1;//%100��������0-99��Ȼ��+1���ɴ�ɷ�ΧΪ1-100
		//
		//	//�������
		//	int guess = 0;
		//	while (1)
		//	{
		//		printf("�������:>");
		//		scanf("%d", &guess);
		//		if (guess > num)
		//		{
		//			printf("�´���\n");
		//		}
		//		else if (guess < num)
		//		{
		//			printf("��С��\n");
		//		}
		//		else
		//		{
		//			printf("��ϲ�㣬�¶��ˣ���ȷ��Ϊ%d\n", num);
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
		//	//�ȵ���srand() ����rand()����Ҫ�����������
		//	//������һ�������У���һ�����ɼ���
		//	//���Է�����������ͷ��
		//	srand((unsigned int)time(NULL));
		//
		//	do 
		//	{
		//		//��ʼ��Ϸ�ȴ�ӡ�˵�
		//		menu();
		//		printf("��ѡ��:>");
		//		//ѡ����Ϸģʽ
		//		scanf("%d", &input);
		//
		//		//�ж���Ϸ�Ƿ���У���״̬��
		//		//switch ������Ϸ���
		//		//game()������Ϸ�������
		//		switch (input)
		//		{
		//		case 1:
		//			game();
		//			break;
		//		case 0:
		//			printf("�˳���Ϸ\n");
		//			break;
		//		default:
		//			printf("ѡ�����������ѡ��\n");
		//			break;
		//		}
		//	} while (input);
		//	
		//	return 0;
		//}

		//�������������Ӵ�С���
		//����о����ȫ�ֱ����;ֲ�����

		//int main()
		//{
		//	int a = 0;
		//	int b = 0;
		//	int c = 0;
		//	printf("������Ҫ�����������:>");
		//	//����
		//	scanf("%d%d%d", &a, &b, &c);
		//	
		//	//����˳��
		//	if (a < b)
		//	{
		//		int tep = a;//�м���ȱ���
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
		//	//��� - �Ӵ�С
		//	printf("%d %d %d", a, b, c);
		//	return 0;
		//}

		//��ӡ1-100֮��3�ı���������

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

		//���������������������������Լ��

		//int main()
		//{
		//	int m = 0;
		//	int n = 0;
		//	int min = 0;
		//	scanf("%d%d", &m, &n);
		//
		//	//������ if���
		//	/*if (m > n)
		//	{
		//		min = n;
		//	}
		//	else
		//	{
		//		min = m;
		//	}*/
		//
		//	//������ ������������ exp1 ? exp2 : exp3
		//	min = (m > n) ? n : m;//�ȼ����Ϸ���if���
		//
		//	while (1)
		//	{
		//		if (m % min == 0 && n % min == 0)
		//		{
		//			printf("���Լ��Ϊ%d", min);
		//			break;
		//		}
		//		min--;
		//	}
		//
		//	return 0;
		//} 

		//����������շת�����
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
		//	printf("���Լ����%d", n);
		//	return 0;
		// //��С������ = m*n/������� 
		//}

		//��ӡ1000-2000֮�������

		//int main()
		//{
		//	//�ܱ�4���������ܱ�100������Ϊ����
		//	//�ܱ�400������Ϊ����
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
		//	//�Ż��������� ��|| �߼������ϲ�����if�ж���������ַ���
		//	for (year = 1000; year <= 2000; year++)
		//	{
		//		if (((year % 4 == 0) && (year % 400 != 0)) || (year % 400 == 0))
		//		{
		//			printf("%d ", year);
		//			count++;
		//		}
		//	}
		//
		//	printf("\n\n��������Ϊ%d\n", count);
		//	return 0;
		//}

		//��ӡ100-200֮�������
		//int main()
		//{
		//	//�������ж�
		//	//����ֻ��1�ͱ���
		//	int i = 0;
		//	for (i = 100; i <= 200; i++) //���for�����Ϊ������100-200
		//	{
		//		//�ж�i�Ƿ�Ϊ����
		//		//��������2 -> i-1֮�������ȥ�Գ������ܲ�������
		//		//����ܣ�����������
		//		int j = 0;
		//
		//		for (j = 2; j < i; j++) //���for������ж��Ƿ�Ϊ�����õ�
		//		{
		//			if (i % j == 0)
		//			{
		//				break;
		//			}
		//		}
		//		//break��������
		//		if (i == j)//��Ϊ����·�������Ե�������ط���������if����ж����������
		//		{
		//			printf("%d ", i);//��ӡ����
		//		}
		//	}
		//	return 0;
		//}

		//������Ŀ��һ���ж�˼·

		//int main()
		//{
		//	//�������ж�
		//	//����ֻ��1�ͱ���
		//	int i = 0;
		//	for (i = 100; i <= 200; i++) //���for�����Ϊ������100-200
		//	{
		//		//�ж�i�Ƿ�Ϊ����
		//		//��������2 -> i-1֮�������ȥ�Գ������ܲ�������
		//		//����ܣ�����������
		//		int j = 0;
		//		int flag = 1;//����i��������
		//		for (j = 2; j < i; j++) //���for������ж��Ƿ�Ϊ�����õ�
		//		{
		//			if (i % j == 0)
		//			{
		//				flag = 0;//i��������
		//				break;
		//			}
		//		}
		//		//break��������
		//		if (flag == 1)
		//		{
		//			printf("%d ", i);//��ӡ����
		//		}
		//	}
		//	return 0;
		//}

		//�����������һ��д��
		//#include <math.h>
		//
		//int main()
		//{
		//	//�������ж�
		//	//����ֻ��1�ͱ���
		//	//���m=a*b
		//	//a��b��һ��������һ��������<=m��ƽ����
		//	//��16 = 2*8 = 4*4  sqrt(16)=4
		//	//�����Գ� ֻ��Ҫ���� <=m��ƽ�������ɣ���Ϊ���������ԣ���ô����Ҳ��Ȼ���Դ���һ������ʹ�������Գ�
		//	int i = 0;
		//	for (i = 101; i <= 200; i+=2) //���for�����Ϊ������100-200       ��101��ʼ��ÿ��+=2����Դͷ�϶ž����ж�ż���Ŀ���  ��Ϊż����2Ϊ����
		//	{
		//		//�ж�i�Ƿ�Ϊ����
		//		//��������2 -> sqrt(i)֮�������ȥ�Գ������ܲ�������
		//		//����ܣ�����������
		//		int j = 0;
		//		int flag = 1;//����i��������    �˴�flagΪ���Ʊ���
		//		for (j = 2; j < sqrt(i); j++) //������ѭ���������Ż�����Ч��
		//		{
		//			if (i % j == 0)
		//			{
		//				flag = 0;//i��������
		//				break;
		//			}
		//		}
		//		//break��������
		//		if (flag == 1)
		//		{
		//			printf("%d ", i);//��ӡ����
		//		}
		//	}
		//	return 0;
		//}

		//�ػ�
		//#include <string.h>
		//
		//int main()
		//{
		//	char input[20] = { 0 };//���������Ϣ
		//	system("shutdown -s -t 60"); //������ - stdlib.h
		//	
		//again:
		//
		//	printf("���ĵ��Խ���60s��ػ�����Ҫȡ����������:������,\"����ȡ���ػ�\"\n");
		//	scanf("%s", input);
		//
		//	if (strcmp(input, "������") == 0)
		//	{
		//		system("shutdown -a");
		//		printf("�ɹ�ȡ��");
		//	}
		//	else 
		//	{
		//		goto again;   //������whileѭ������goto 
		//	}
		//
		//	return 0;
		//}

		//дһ�����������ҳ����������еĽϴ�ֵ

		//int get_max(int x,int y)
		//{
		//	int z = 0;
		//	z = (x > y) ? x : y;
		//	return z;//����z-�������ֵ
		//}
		//
		//int main()
		//{
		//	int a = 10;
		//	int b = 20;
		//	//�����ĵ���
		//	int max = get_max(a, b);
		//	printf("max = %d\n");
		//	return 0;
		//}

		//дһ������ - �����������ͱ�����ֵ

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
		//	printf("����ǰ��ֵΪ%d %d\n", a, b);
		//	//���ý�����ֵ����
		//	exchange_int(&a,&b);
		//	printf("�������ֵΪ%d %d\n", a, b);
		//
		//	return 0;
		//}

		//дһ�����������ж�һ�����ǲ�������
		//
		//#include <math.h>
		//
		//int judge_prime(int x)
		//{
		//	//��ô�ж�һ��������
		//	//������ ��Ҫ�жϵ���ȥ��2 - ��num-1�����Ҷ�����֮����������������������
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
		//	//�ж�100-200�м������
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

		//дһ�������ж�һ���ǲ�������
		//1000-2000��֮�������

		//���庯��
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

		//дһ��������ʵ��һ��������������Ķ��ֲ���

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
		//		printf("�Ҳ�����/(��o��)/~~\n");
		//	}
		//	else
		//	{
		//		printf("%d���±�Ϊ��%d\n", k, get_num(arr, k, sz)); //��ʽ����
		//	}
		//	return 0;
		//}

		//дһ��������ÿ����һ��������������Ὣnum��ֵ����1

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

		//������Ƕ�׵���
		//void test3()
		//{
		//	printf("�Ǻ�\n");
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

		//����һ������ֵ���޷��ţ�����˳���ӡ����ÿһλ  ���磺1234�����1 2 3 4
		//����ĿΪ��ϰ�����ĵݹ飨�Լ������Լ���
		//�ݹ���Ҫ˼����ʽ���Ѵ��»�С 

		//void print(int n)
		//{
		//	if (n > 9)   //��Ҫ������������������֯����һֱ�ݹ�    ��ÿ�ݹ�һ�Σ�Խ��Խ�ӽ���������
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

		//ģ��ʵ��һ��strlen����   �����ַ������Ⱥ���

		//int my_strlen(char* str)//strΪһ���ַ���ָ�����
		//{
		//	//������ʱ�����ķ���
		//	//int count = 0;
		//	//while (*str != 0) //ָ��������ʱ����ŵ��ǵ�һ��Ԫ�صĵ�ַ��������������
		//	//{
		//	//	str++;
		//	//	count++;
		//	//}
		//	//return count;
		//
		//	//����������ʱ���������ú����ݹ�
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
		//	//[S][n][o][w][K][\0]   \0Ϊ�ַ���������ʾ����ռ���ַ������Ⱥʹ�С
		//
		//	printf("%d\n", my_strlen(arr));//��������ʽ����
		//	return 0;
		//}

		//��n�Ľ��
		//�����ķ�ʽ

		//int main()
		//{
		//	int n = 0;   //��n�Ľ�ˣ�������n�����ƴ���
		//	int i = 0;
		//	scanf("%d", &n);
		//	int ret = 1; //ret��Ϊ��ת�õı���
		// 
		//  ����
		//	for (i = 1; i <= n; i++)
		//	{
		//		ret = ret * i;
		//	}
		//	
		//	printf("%d", ret);
		//	return 0;
		//}

		////��n�Ľ��  �õݹ�ķ�ʽ
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

		//��쳲��������еĵ�n����
		//�õ����ķ���ȥ��

		//����һ��ȫ�ֱ���count  ��������
		//int count = 0;
		//
		//int Fib(int n)
		//{
		//	if (n == 3)
		//	{
		//		count++; //���ڼ�����n=3�����˶��ٱ�
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

		//��n��쳲�������
		//�õ����ķ�ʽȥ��

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
		//	printf("Ҫ����ڼ���쳲�������:");
		//	scanf("%d", &n);
		//	int result = Fib(n);
		//	printf("%d", result);
		//
		//	return 0;
		//}


		//��д������һ��1��100 �����������г��ֶ��ٸ�����9
		//9 19 29 39 49 59 69 79 89 99

		//int main()
		//{	
		//	int count = 0;
		//	//����������
		//	int i = 0;
		//	for (i = 1; i <= 100; i++)
		//	{
		//		//�жϸ�λ9
		//		if (i % 10 == 9)
		//		{
		//			count++;
		//		}
		//
		//		//�ж�ʮλ10
		//		if (i / 10 == 9)
		//		{
		//			count++;
		//		}
		//	}
		//
		//	printf("�ܹ���%d��9", count);
		//	return 0;
		//}


		//����1/1-1/2+1/3-1/4+1/5 ......+ 1/99 - 1/100��ֵ����ӡ�����
		//int main()
		//{
		//	int i = 0;
		//	double sum = 0.0;
		//	int flag = 1;
		//	for (int i = 1; i <= 100; i++)
		//	{
		//		//�˴�ģ2��Ϊ���жϲ��ҿ���������
		//	/*	if (i % 2 == 0)
		//			sum -= 1.0 / i;
		//		else
		//			sum += 1.0 / i;*/
		//
		//		//��һ�ֿ�����������
		//		sum += 1.0 / i * flag;
		//		flag = -flag;  //����������
		//
		//	}
		//	printf("%lf", sum);
		//	return 0;
		//}

		//��10�����е����ֵ  ��� �Ҳ�������

		//int main()
		//{
		//	int arr[7] = { 188,261,233,666,100,1835,1752 };
		//	int max = arr[0];  //������ʼmax��Ϊ�����е�һ����  ������0   ��Ϊ���Ϊ���������޷��ж�
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
		//��ӡ�žų˷���
			//1*1=1 
			//2*1=2 2*2=4
			//3*1=3 3*2=4

		//int main()
		//{
		//	int i = 0;
		//	for (i = 1; i <= 9; i++)//��������
		//	{
		//		int j = 0; //������������
		//
		//		for (j = 1; j <= 9; j++)
		//		{
		//			printf("%d*%d=%-2d ", i, j, i * j);//%-2d���˿�����λ���������    %2dΪ�Ҷ���
		//			                                  //ʹ�����int�͵���ֵ��2λ�Ĺ̶�λ��������������2λ������ǰ�油�ո�
		//		}
		//		printf("\n"); //�����Ű棬ʹÿһ�н�β����
		//	}
		//	return 0;
		//}
		//

		//ʵ��X*X�˷���
		//
		//void print_table(int n)
		//{
		//	int i = 0;
		//	for (i = 1; i <= n; i++)
		//	{
		//		//һ��
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
		//	int n = 0; //����x*x
		//	printf("��������ҪX*X:");
		//	scanf("%d", &n);
		//
		//	print_table(n);
		//	return 0;
		//}

		//�ַ�������(�ݹ�ʵ��)��Ŀ����:
		//��дһ������reverse_string(char * string)(�ݹ�ʵ��)
		//ʵ��:�������ַ����е��ַ��������У����������ӡ��Ҫ��:����ʹ��C�������е��ַ�����������

		//int my_strlen(char* arr)//дһ������  ģ��⺯��strlen()�Ĺ���
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

		//����  ���õݹ�ʵ��  �õ���
		//void reverse_string(char* arr)//�β���ָ��
		//{
		//	int left = 0;
		//	int right = my_strlen(arr) - 1;
		//	while (left < right)
		//	{
		//		//��һ�ֱ�����ʽ
		//		//char tmp = arr[left];
		//		//arr[left] = arr[right];
		//		//arr[right] = tmp;
		//		//left++;
		//		//right--;
		//
		//		//�ڶ��ֱ�����ʽ   ������
		// 		char tmp = *(arr + left);//�ȼ��� arr[left];
		//		*(arr + left) = *(arr + right);
		//		*(arr + right) = tmp;
		//		left++;
		//		right--;
		//	}
		//}

		//���� �õݹ�ʵ��
		//void reverse_string(char* arr)
		//{
		//	char tmp = *arr;
		//	int len = my_strlen(arr) - 1;
		//	*arr = *(arr + len);
		//	*(arr + len) = '\0'; //�Ȳ�����ǰ��һ��ֵ�������  ��ֹ�´ε���ʱ ��������  �ʹﲻ��Ŀ��
		//	//�ж�����
		//	if (my_strlen(arr + 1) >= 2)
		//	{
		//		reverse_string(arr + 1);
		//	}
		//	*(arr + len) = tmp;//����ٰѵ�һ��ֵ���������
		//}
		//
		//int main()
		//{
		//	//����һ���ַ���
		//	char arr[10] = "DiesnowK" ;
		//	reverse_string(arr);//�������ȥ �����ǵ�һ���ַ��ĵ�ַ
		//	printf("%s", arr);
		//	return 0;
		//}

		//����һ������ÿλ֮��(�Ǹ���)  �õݹ�ʵ��

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

		//��дһ������ʵ��n��k�η����õݹ�ʵ��  ��������������
		//��k�η�Ϊ���ģ���ΪС������������������double

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

		//ð������

		//void bubble_sort(int* arr, int sz)
		//{
		//	//ȷ��Ҫ������
		//	int i = 0;
		//	int flag = 1;
		//	for (i = 0; i < sz - 1; i++)
		//	{
		//		//ÿһ��Ҫ������
		//		int j = 0;
		//		for (j = 0; j < sz - 1 - i; j++)
		//		{
		//			//һ��ð������Ĺ���
		//			if (arr[j] < arr[j + 1])
		//			{
		//				//����
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
		//	//��������
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

		//�������Ľ���

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

		//��Ϊ�淶ģ��strcpy  -  my_strcpy

		//#include <assert.h>
		//
		//char* my_strcpy(char* destination, const char* source) //����ʹ��const��ֹsource���޸�
		//{
		//	char* tmp = destination;
		//
		//	assert(source != NULL); //���ԣ�����debugʱ�����
		//
		//	while (*destination++ = *source++)
		//	{
		//		;
		//	}
		//	return tmp;  //����Ŀ��ռ����ʼ��ַ
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

		//��Ϊ�淶��ģ��strlen  -  my_strlen

		//#include <assert.h>
		//
		//unsigned int my_strlen(const char* arr)  //Ϊ����unsigned int?   --  ��Ϊ���Ȳ����ڸ������Է��κ���������
		//{
		//	assert(arr != NULL);
		//	//assert(arr); �ȼ����������ʽ
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

		//дһ������
		//Ҫ������һ���������������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ

		//��λ�ȡһ��ʮ�������ֵĶ�������ʽ��
		//����Ϊ����
		//15 - 00001111
		//15 % 2 = 1               //������ұ�һλ��1/0
		//15 / 2 = 7 - 00000111    //��ȥһλ
		//7 % 2 = 1
		//7 / 2 = 3 -- 00000011
		//3 % 2 = 1 -- 00000001
		//3 / 2 = 1 -- 00000001
		//1 % 2 = 1 -- 00000001

		//�˺����㷨���������   ����������������   ���Ǹ����أ�
		//int NumberOf(int n)
		//{
		//	int count = 0;//������
		//	while (n)
		//	{
		//		if (n % 2 == 1)  //�жϵ�һλ�Ƿ���1
		//		{
		//			count++;
		//		}
		//
		//		n /= 2;  //��ȡ��һλ
		//	}
		//
		//	return count;
		//}

		//ͨ��ֱ�Ӳ���������λ  ���Ա�����������
		//int NumberOf(int n)
		//{
		//	int count = 0;
		//	int i = 0;
		//	
		//	for (i = 0; i < 32; i++)
		//	{
		//		//��& ��λ��   
		//		//��1   00000001    ���ж����һλ���
		//
		//		if ((n >> i) & 1 == 1)    //n����λ����i����  һ������  ����Ҫÿ�ζ�����һλ
		//		{
		//			count++;
		//		}
		//	}
		//	
		//	return count;
		//}

		//���Ϻ����㷨���Ż�
		//n & (n - 1)  --  �����𲽼��ٶ�����λ�е�1
		//����λ����
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

		//����˼·�����������ж�һ�������ǲ���2��n�η�
		//2��n�η������֣�����ֻ��һ��1
		// 00100000 - n
		// 00011111 - n - 1
		//k & (k - 1) == 0

		//int NumberOf(int n)
		//{
		//	int count = 0;
		//
		//	while (n)  //һֱ���� n == 0ʱ������ѭ��
		//	{
		//		n = n & (n - 1); //ֻҪ�ܽ�������������λ�����ٶ������е�һ��1
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

		//���������������в�ͬλ�ĸ���
		// ��λ��򼴿�   ^   ��ͬΪ0  ����Ϊ1
		// ͳ������Ľ����1�ĸ���
		//����1999  2299    ��� - 7

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
//	ret = m ^ n;    //��ͬΪ0  ����Ϊ1
//	printf("%d\n", NumberOf(ret));
//
//	return 0;
//}

//����������һ�ִ�����
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

//��ӡ���������Ƶ�����λ��ż��λ

//int main()
//{
//	int x = 15;
//	int i = 0;
//	//00000000000000000000000000001000
//	//��ӡż��λ
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (x >> i) & 1);
//	}
//	printf("\n");
//
//	//��ӡ����λ
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (x >> i) & 1);
//	}
//
//	return 0;
//}

//����������������������ʱ������

//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	a = a ^ b;
//	b = a ^ b; // a ^ b ^ b        b ^ b == 0     ��ʱb == a
//
//	a = b ^ a; // a ^ a ^ b  ͬ��
//
//	printf("a = %d  b = %d", a, b);
//
//	return 0;
//}

//����С������  ����㷨

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
//	//���ϴ�����Ż�
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

//��һ�仰�ĵ��ʽ��е��ã���㲻���ã����� l like beijing.
//���ú� beijing. like l
//#include <string.h>
//
//void reverse(char* left, char* right) //����������������
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
//	//������ת��
//	//1.�ַ������巭ת
//	reverse(arr, arr + len - 1);
//	//2.ÿ����������
//	char* start = arr;
//	while (*start)
//	{
//		char* end = start;
//
//		//�ҵ�ÿһ������ͣ�ٵ�λ��
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//		//����ÿһ������
//		reverse(start, end - 1);
//
//		//��������һ������
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

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ������
//����:2+22+222+2222 +22222

//int main()
//{
//	int a = 0;
//	int n = 0;
//
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int ret = 0; //һ��
//	for (i = 0; i < n; i++)
//	{
//		//���һ��
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d", sum);
//
//	return 0;
//}

//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ��
//arr��һ������һά����

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	//��
//	int* pend = arr + sz - 1;
//	while (p <= pend)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//
//	////��
//	//int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(p + i));
//	//}
//	
//	return 0;
//}

//���0��100000֮������С�ˮ�ɻ����������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������//�磺153=1^3+5^3+3^3����153��һ����ˮ�ɻ�����

//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 10000; i++)
//	{
//		//�ж�һ�����ǲ���������
//		//1.����n��λ�� - n
//		int n = 1;
//		int tmp = i;
//		while (tmp / 10)
//		{
//			n++;
//			tmp /= 10;
//		}
//
//		//2.����i��ÿһλ��n�η�֮��
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//
//		//3.�ж�
//		if (sum == i)
//		{
//			printf("%d ", sum);
//		}
//	}
//	return 0;
//}

//дһ����������������һ���ַ���������
//#include <string.h>
//#include <assert.h>
//void reverse(char* str)
//{
//	assert(str != NULL);
//	//��ֱ����assert(str);����  ��strΪ��ָ�룬��Ĭ��ΪNULL
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

//��������
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	scanf("%d", &n);
//	int line = n / 2 + 1; //�ϰ벿��
//	//�����ϰ벿��
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
//	//�����°벿��
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

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣�
//int main()
//{
//	int money = 0;
//	int total = money;
//	int empty = money;
//	scanf("%d", &money);
//	
//	//��ʼ�û�ƿ��
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d", total);
//
//	return 0;
//}

//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿��
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
//		//����������һ��ż��
//		while (left < right && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//����������һ������
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

//��ӡ�������
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
//			//��ʼ���㲿��
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

//������
//A˵��������
//B˵����C
//C˵����D
//D˵��C�ں�˵
//��֪������˵���滰��һ����˵���Ǽٻ�
//дһ��������ȷ��˭����������

//int main()
//{
//	char killer = 0;
//	//��ÿ���˶������ֵĽǶȣ�ȥ����һ�飬�����ж����ǵĻ�
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c", killer);
//		}
//	}
//	return 0;
//}

//��λ�˶�Ա��ˮ����������������Ԥ��������
//A˵��B�ڶ����ҵ�����
//B˵���ҵڶ���E����
//C˵���ҵ�һ��D�ڶ���
//D˵��C����ҵ���
//E˵���ҵ��ģ�A��һ
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ������������

//int main()
//{
//	//ö�ٳ������  ����  ���ѭ���׳�����˵�����
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
//						if ((b == 2) + (a == 3) == 1      //ÿ�����а�����  ��ôҲ�����ж�ֵ���Ϊ1
//							&& (b == 2) + (e == 4) == 1
//							&& (c == 1) + (d == 2) == 1
//							&& (c == 5) + (d == 3) == 1
//							&& (e == 4) + (a == 1) == 1
//							)
//						{
//							if (a * b * c * d * e == 120)  //�����޶����ظ������
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

//ģ�������calc  �����𽥽��е��� ���� �Ż�  (������Χ��)
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

//�汾��
//���Ҫ����a&b a|b a>>b a<<b a^b�أ�
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
//			printf("����������������:>");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 2:
//			printf("����������������:>");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 3:
//			printf("����������������:>");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 4:
//			printf("����������������:>");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			printf("ret = %d\n", ret);
//			break;
//
//		case 0:
//			printf("�˳�����\n");
//			break;
//
//		default:
//			printf("���������������\n");
//			break;
//		}
//
//	} while (input);
//	return 0;
//}

////�汾��  �ú���ָ�����������ú���
////����ָ���������;��ת�Ʊ�
//int main()
//{
//	int input = 0;
//
//	do {
//		menu();
//		int(*pfarr[5])(int,int) = { NULL,Add,Sub,Mul,Div };  //����ָ������
//		int x = 0;
//		int y = 0;
//		int ret = 0;
//
//		scanf("%d", &input);
//
//		if (input >= 1 && input <= 4)
//		{
//			//ʵ�ʵ��ü���ģ��
//			printf("����������������:>");
//			scanf("%d %d", &x, &y);
//			ret = pfarr[input](x, y);  //ͨ������ָ�����������ú���
//			printf("ret = %d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�����\n");
//			break;
//		}
//		else
//		{
//			printf("ѡ���������ѡ��\n");
//		}
//
//	} while (input);
//
//	return 0;
//}

////�汾��  �ص�����
//int Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("����������������:>");
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
//		printf("��ѡ��:>");
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
//			printf("�˳�����\n");
//			break;
//		default:
//			printf("�����������ѡ��\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}

////�о��⺯��qsort();
////void qsort(
////	void* base,  //Ŀ������Ŀ�ͷ
////	size_t num,	 //��������Ԫ�صĸ���
////	size_t width, //����������һ��Ԫ�صĴ�С����λ���ֽ�
////	int(__cdecl* compare)(const void*e1, const void*e2) //�������Ƚϴ����������е�����Ԫ�صĺ���������ֵ��int���� 
////													//>0��e1>e2
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
//	//>0 ��e1>e2  <0 ��e1<e2  ����
//	return *(int*)e1 - *(int*)e2;
//	
//	//����
//	//return *(int*)e2 - *(int*)e1;
//}
//
//void test1()
//{
//	//�������ݵ�����
//	int  arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//����
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	//��ӡ
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
//	//��������������
//	//qsort(s, sz, sizeof(s[0]), sort_by_age);
//
//	//��������������
//	qsort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//void swap(char* buffer1, char* buffer2, int width)
//{
//	//bufferΪ����������˼,�Ժ���buf��д����
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
////ģ��qsort()�Լ�дһ��ð������
//void bubble_sort(void* base, unsigned int sz, unsigned int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ�˵�����
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//����Ԫ�صıȽ�
//			//arr[j] > arr[j+1]
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//				//Ϊ��ǿ��ת����char*�أ�
//				//char* ������С��Ϊһ���ֽڣ�����ͨ�� (��С�Ŀ��) * (width) �����Ƶ���������(int struct short�ȵ�)
//			{
//				//����
//				//���ǲ�֪�����������,����ν����أ�
//				//����һ���ֽ�һ���ֽڵĽ��� ֱ�����һ�����͵Ĵ�С - ��������Ԫ�ض�Ӧλ�õ��ֽ�
//				//����int���ͣ�����4�ζ�Ӧ���ֽڣ��򽻻��������Ԫ��
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void test3()
//{
//	//�������ݵ�����
//	int  arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//����
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	//��ӡ
//	print_arr(arr, sz);
//}
//
//void test4()
//{
//	//ʹ��qsort��������ṹ������
//	struct Stu s[3] = { {"zhangsan", 30},{"lisi", 34},{"wangwu", 20} };
//
//	int sz = sizeof(s) / sizeof(s[0]);
//	//��������������
//	bubble_sort(s, sz, sizeof(s[0]), sort_by_age);
//	//��������������
//	//bubble_sort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//
//int main()
//{
//	//test1();//�������β���
//	//test2();//����ṹ�����
//	//test3();
//	test4();
//	return 0;
//}

//���Ͼ���
//��Ŀ���ݣ�
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
// �ǾͲ��ܱ�������Ȼʱ�临�ӶȲ�����Ҫ��
//��
//1 2 3 
//4 5 6
//7 8 9

//int find_num(int arr[3][3], int* px, int* py, int k)
//{
//	//�����Ͻǿ�ʼ��  ȥ��
//	int x = 0;
//	int y = *py - 1;
//	while (x < *px && y >= 0) //��ֹԽ��
//	{
//		if (arr[x][y] < k)
//		{
//			x++;//ȥ��һ��
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;//ȥ��һ��
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1; //�ҵ���
//		}
//	}
//	return 0; //�Ҳ���
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	//����ҵ�����1���Ҳ�������0
//	int x = 3;
//	int y = 3;
//	//&x,&y
//	//1.�������
//	//2.����ֵ
//
//	int ret = find_num(arr, &x, &y, k);
//	if (ret == 1)
//	{
//		printf("�ҵ���\n");
//		printf("�±���%d %d\n", x, y);
//	}
//	else
//	{
//		printf("�Ҳ���\n");
//	}
//
//	return 0;
//}

//�ַ�������
//��Ŀ���ݣ�
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

////��ֱ������
//void string_left_rotate(char* str, int k)
//{
//	int i = 0;
//	int n = strlen(str);
//	for (i = 0; i < k; i++)
//	{
//		//1.ÿ����תһ���ַ�
//		char tmp = *str;
//		//2.��ߵ�n-1���ַ���ǰŲ��
//		int j = 0;
//		for (j = 0; j < n - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		//3.��tmp�������
//		*(str + n - 1) = tmp;
//	}
//}

//#include <assert.h>
////������ת��
////�����Ϊ �Ŷ� ��ǰ��  ǰ������ת  ��������ת  ����������ת �ȼ���  ��ǰ�涪������ȥ
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
//	reverse(str, str + k - 1); //��߷�ת
//	reverse(str + k, str + n - 1); //�ұ߷�ת
//	reverse(str, str + n - 1); //���巭ת
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

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

//д����  ���� ���
//int is_string_rotate(char* str1, const char* str2)
//{
//	int i = 0;
//	int n = strlen(str1); //5
//
//	for (i = 0; i < n; i++)
//	{
//		//ÿ�ζ�����תһ���ַ�
//		char tmp = *str1;
//		//��ߵ�n-1���ַ���ǰŲ��
//		int j = 0;
//		for (j = 0; j < n - 1; j++)
//		{
//			*(str1 + j) = *(str1 + j + 1);
//		}
//		//tmp�������
//		*(str1 + n - 1) = tmp;
//
//		//ÿ����һ�Σ���һ�αȶ�
//		if (strcmp(str1, str2) == 0)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}

//#include <assert.h>
////д����  ����һ��
//int is_string_rotate(char* str1, const char* str2)  //�ж�str1�ǲ���str2��ת������
//{
//	assert(str1);
//	assert(str2);
//	//�����Ȳ���ȣ���ô�϶�����ѡװ������
//	if (strlen(str1) != strlen(str2))
//	{
//		return 0;
//	}
//
//	//1.str1�ַ����ĺ��׷��һ��str1
//	//AABCDAABCD
//	int len = strlen(str1);
//	strncat(str1, str2, len);
//	//2.�ж�str2�Ƿ�Ϊstr1���ִ�
//	char* ret = strstr(str1, str2);//strstr�ķ���ֵʹstr1�е�һ�γ���str2��λ��  -- ��ַ
//
//	return ret != NULL; //ret����NULL��Ϊ�Ҳ���
//	//�ȼ���
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

//ģ��ʵ��strcat
//#include <assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	//1.��Ŀ���ַ�����\0��λ��
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.׷��Դ�ַ���������\0
//	while (*dest++ = *src++);
//
//	return ret;//����Ŀ����ʾ��ַ
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

//ģ��ʵ��strcmp
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

//ģ��ʵ��strstr
//#include <assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	//ʵ����s1,s2ȥ����
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* cp = str1; //���ڼ�¼ÿ����һ�ε���ʼλ��
//
//	//ԭ��str2���ǿ��ַ����أ�
//	if (*str2 == '\0')
//	{
//		return str1;
//	}
//
//	//��str2���ǿ��ַ���
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//
//		while (*s1 && *s2 && (*s1 == *s2)) //*s1 *s2û����  ����������ͬ�����
//		{
//			s1++;
//			s2++;
//		}
//		
//		if (*s2 == '\0')
//		{
//			//����ֵΪstr2��str1�е�λ��
//			return cp;//˼�����Ƿ���Ҫǿ������ת����char*?
//		}
//
//		//������û�ҵ�,��cp++,������һ���ַ���Ϊ��ʼλ�ÿ�ʼ����
//		cp++;
//	}
//	
//	return NULL;//û�ҵ��򷵻ؿ�ָ��
//}
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bbc";
//	//��arr1�в����Ƿ����arr2����
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("û�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ���:%s\n", ret);
//	}
//	return 0;
//}

//�о�strtok
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

//�о�strerror
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

//ģ��ʵ��memcpy��memcpy����Ӧ�ÿ������ص����ڴ�
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, int num)
//{
//	assert(dest && src);
//
//	void* ret = dest;//���ڱ��淵��ֵ��Ϣ
//
//	while (num--) //��ѭ����������������ʽ����ͦ����˼�ģ�ֵ��ѧϰ:)
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

//ģ��ʵ��memmove,memmove�������Դ����ڴ��ص������
//#include <assert.h>
//void* my_memmove(void* dest, void* src, int num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if (dest < src)
//	{
//		//��ǰ����
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//�Ӻ���ǰ
//		while (num--) //���numһ��ʼΪ20,��һ�ν�����ʱ��num�Ѿ����19����ô���Կ��Ƶ��ڶ�ʮ���ַ����Դ�����
//		{
//			//ָ��λ����ȫ��num����
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

//��ӡ��*��ɵ�X��ͼ��
//�������룬һ������(2~20),��ʾ�����������Ҳ��ʾ���X�ķ�б�ߺ���б�ߵĳ���
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

//��7λ���٣��Ӽ�������������ɼ���ÿ���������(�ٷ���)��ȥ��һ����߷ֺ�һ����ͷ֣����ÿ���ƽ���ɼ�
//��������:һ�У�����7������(0~100)������7���ɼ����ÿո�ָ���
//�������:һ�У����ȥ����߷ֺ���ͷֵ�ƽ���ɼ���С�������2λ��ÿ���������

//int main()
//{
//	int score = 0;
//	int sum = 0;
//	int i = 0;
//	//��������Ϊ0-100
//	int max = 0;
//	int min = 100;
//	//����һ��ѭ���Ϳ��Բ�����ɣ�ʡȥ�˶�α�����¼�룬�����ֵ����Сֵ�Ĳ���
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

//������ݺ��·ݣ�������һ��������ж�����
//�����������������룬һ���������������ֱ��ʾ��ݺ��·ݣ��ÿո�ָ�
//������������ÿ�����룬���Ϊһ�У�һ����������ʾ��һ��������ж�����

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
//			//�ж��Ƿ�����
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

//ģ��ʵ��atoi
//#include <ctype.h>
//#include <limits.h>
//
////State ��¼����my_atoi���ص�ֵ�Ƿ��ǺϷ�ת����ֵ
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
//	//��ָ��
//	if (p == NULL)
//	{
//		return 0;
//	}
//
//	//���ַ���
//	if (*p == '\0')
//	{
//		return 0;
//	}
//
//	//�����հ��ַ�
//	while (isspace(*p))
//	{
//		p++;
//	}
//
//	//�ж�������+/-
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
//	//���������ַ���ת��
//	long long n = 0;
//	while (isdigit(*p))
//	{
//		n = n * 10 + flag * (*p - '0');
//		//����int����������ʱ��ҲΪ�Ƿ�ֵ
//		if (n > INT_MAX || n < INT_MIN)
//		{
//			return 0;
//		}
//		p++;
//	}
//	//�����˳�ѭ�����أ�
//	if (*p == '\0')
//	{
//		//�Ϸ���ֵ
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
//	//Ҫ������쳣״̬
//	//1.��ָ�� ��
//	//2.���ַ��� ��
//	//3.�����˷������ַ� ��
//	//4.������Χ ��
//	const char* p = "     -123a"; //�����ַ��������Ͳ����޸ģ����Լ���const������һЩ
//	int ret = my_atoi(p);
//
//	if (state == VALID)
//	{
//		printf("������ת��:%d\n", ret);
//	}
//	else
//	{
//		printf("�Ƿ���ת��:%d\n", ret);
//	}
//
//	return 0;
//}

//����:1 2 3 4 5 1 2 3 4
//һ��������ֻ�����������ǳ�����һ�Σ������������ֶ�����������
//��дһ�������ҳ�������ֻ����һ�ε�����

//void Find(int arr[], int sz, int* px, int* py)
//{
//	//1.�����������
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//����ret����һλΪ1(���鷽��)
//	//ΪʲôҪ�����أ�
//	//���������������ͬ��������Ϊ0��ʣ��������ͬ�ģ���ô��ͬΪ0������Ϊ1
//	//��һ������1�ĵط��������Ƕ�����λ��һ����ͬ�ĵط�
//
//	int pos = 0;//��ʾret��posλΪ1(�±꣩
//	for (i = 0; i < 32; i++)
//	{
//		if ((ret >> i) & 1 == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	
//	//�Ѵӵ�λ����λ��posλΪ1��Ϊ0�ķ���������
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
//	//ѭ������ʱ��num1,num2�����ҵ�������ֵ
//	*px = num1;
//	*py = num2;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
//	//5:00000101
//	//6:00000110
//	//1.����
//	//2.�����Ҫ�㣺5��6�����ڲ�ͬ����
//	//3.�ҳ�������ֻ����һ�ε�����
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

//дһ���꣬��һ�������Ķ����Ƶ�����λ��ż��λ����
//���ʵ�֣�
//�����һλΪ1��������λ����һλ��ż��λ����һλ


//#define SWAP(N) ((N & 0xaaaaaaaa)>>1) + ((N & 0x55555555)<<1)
////          ��ȡż��λ����������һλ || ��ȡ����λ����������һλ
////ż��λ + ����λ����Ϊ�����������
//
//int main()
//{
//	//ԭ�����  --  ��λ��
//	//10101010101010101010101010101010 ��ԭ���ִ��ó�ż��λ -- ԭż��λȫ������ԭ��״̬������λ����  0xaaaaaaaa
//	//01010101010101010101010101010101 ��ԭ�������ó�����λ -- ԭ����λȫ������ԭ��״̬��ż��λ����  0x55555555
//	
//	int num = 10;
//	int ret = SWAP(num);
//
//	printf("%d\n", ret);
//
//	return 0;
//}

//ģ��ʵ��offsetof  -- дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��

//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
////
//#define OFFSETOF(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)
////����ṹ���һλ��0��ַ��
////������ʳ�Ա��ʱ�򣬳�Ա�ĵ�ַ
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

//��Ŀ������
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磺��һ���ַ�����"They are students."���ڶ����ַ����ǡ�aeiou"��ɾ��֮��ĵ�һ���ַ������"Thy r stdnts."��
//��֤�����ַ����ĳ��Ⱦ�������100��
//�����������������У�ÿ��һ���ַ�����
//������������ɾ������ַ�����

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
//	for (i = 0; arr2[i] != '\0'; i++)//��arr2��ÿ���ó�һ���ַ������Ƚ�
//	{
//		for (j = 0; arr1[j] != '\0'; j++)//��arr1�е�ÿ���ַ��Ƚ�
//		{
//			if (arr2[i] == arr1[j])//�ҵ�����ȵ�
//			{
//				//�Ѻ��������������ᣬ����ʵ��ɾ��Ч��
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

//��Ŀ������
//����һ���ϴ������ N(1 <= N <= 2, 000, 000, 000)
//���� 980364535�����ǳ�����Ҫһλһλ����������Ǽ�λ��������������� ������ÿ��λ��һ�����ţ������ø��������ʶ���
//��ˣ�������ּ��϶��ų����µ�ģ����980, 364, 535��дһ�������������������
//����������һ��һ������ N
//���������һ��һ���ַ�����ʾ����궺�ŵĽ��

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
//	char* pend = arr + sz - 1;//�ʼָ��\0
//
//	//�Ӻ���ǰ�ᣬÿ�����м��һ��,
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

//ʵ��һ����������һ���ַ����е�ÿ���ո��滻��"%20"
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy

//#include <ctype.h>
//int main()
//{
//	int spacecnt = 0;
//	char arr[30] = "We Are Happy";
//	char* p = arr;
//	int length = strlen(arr);
//	//���ո�
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

//��һ��쳲����������У�����һ����N��������������һ��쳲������������ľ���

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
//			//���n����ԭ����a b֮�䣬����a b�����ߣ�ֱ�����Լ�סn
//			//����Ϊ쳲���������
//			a = b;
//			b = c;
//			c = a + b;
//		}
//	}
//
//	return 0;
//}

//���ÿɱ�����б���һ��Ѱ�����ֵ�ĺ���
//#include <stdarg.h>
//
////�˴�,num��ʾ��������ĸ���
//int FindMax(int num, ...)
//{
//	int i = 0;
//
//	va_list p_ret;  //����һ��char*���͵�ָ�룬��ָ������ɷ��ʿɱ�������ֵı���
//	va_start(p_ret, num);//ʹp_retָ��ɱ��������,�Ѿ�ָ��ɱ�������ֵĵ�һ��������
//	int max = va_arg(p_ret, int);//�������ͣ���ȡ�ɱ���������б��еĵ�һ�����ݣ����Ҵ�ʱp_ret�Ѿ�ָ��ɱ�������ֵ���һ������
//
//	for (i = 0; i < num - 1; i++)  //��ȡ���Ƚ�������
//	{
//		int tmp = va_arg(p_ret, int);//�ó���ǰָ�����ݣ�����p_ret���ƫ��
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

//��ʧ������
//����nums������0��n������������������ȱ��һ������д�����ҳ��Ǹ�ȱʧ��������
//Ҫ��ʱ�临�Ӷ���O(N)��

//˼·1�����ƹ�ϣ��  O(N)
//int FindMissingNum(int arr[], int sz)
//{
//	int* hash = (int*)malloc((sz + 1) * sizeof(int));//malloc��һ����������
//	if (NULL == hash)  //����ʧ�ܵ����
//	{
//		perror("main");
//		exit(1);
//	}
//	memset(hash, -1, sz * sizeof(int));//���ֽ�Ϊ��λ�����ڴ�  --  ��ʼ������Ϊ-1
//
//	int i = 0;
//
//	//����ԭ�����飬����һ�����֣����ڹ�ϣ���Ӧλ��+1
//	for (i = 0; i < sz; i++)
//	{
//		hash[arr[i]] += 1;
//	}
//
//	//�������飬�ĸ�λ��Ϊ-1,�����λ�õ��±����ȱʧ������
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

//˼·2�������  O(N)

//int FindMissingNum(int arr[], int sz)
//{
//	int i = 0;
//	int ret = 0;
//	//�Ⱥ�ȱʧ�������
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//�ٺ�ԭ�������
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
 
//˼·3������ + ���ֲ���  ð��O(N^2)  ����O(N*logN) - Ч����Խϵ�
//int main()
//{
//
//	return 0;
//}

//˼·4����ʽ���� - ���ԭ���� - ȱʧ���� = ȱʧ����    O(N)

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

//��ת����  --  ��һ�����飬�������е�Ԫ��������תk��λ��
//�����ܶ�Ľ������
//Ҫ�󣺿ռ临�Ӷ�ΪO(1),ʱ�临�Ӷ�O(N)

//˼·1��ÿ����תһ������תk�� - O(N*K)

//void rotate(int arr[], int sz, int k)
//{
//	//���k>sz��ô�죿
//	k %= sz;
//
//	while (k--)
//	{
//		//�Ȱѵ�һ�������
//		int tmp = arr[0];
//
//		//�ٰѺ���������
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

//˼·2���Կռ任ʱ�� - ��һ���µ�������� - O(N)

//void rotate(int arr[], int sz, int k)
//{
//	int i = 0;
//	int j = 0;
//	int* p = (int*)malloc(sizeof(int) * sz);
//	if (NULL == p) //�ж��Ƿ񿪱ٺÿռ�
//	{
//		perror("main");
//		exit(1);
//	}
//	
//	//��ǰk���������������
//	for (i = 0; i < k; i++)
//	{
//		p[sz - k + i] = arr[i];
//	}
//
//	//����n-k������������ǰ��
//	for (i = k, j = 0; i < sz; i++, j++)
//	{
//		p[j] = arr[i];
//	}
//
//	//����ԭ����
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

//˼·3��������ת�� - ���Žⷨ  ʱ�临�Ӷ�O(N)   �ռ临�Ӷ�O(1)

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
//	//�ȷ�תǰk��
//	reverse(arr, arr, arr + k - 1);
//	//�ٷ�ת��n-k��
//	reverse(arr, arr + k, arr + sz - 1);
//	//ȫ�巴ת
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

//�Ƴ�Ԫ�� -- ��һ������nums��һ��ֵval,��Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³���
//Ҫ�󣺲���ʹ�ö��������ռ�  --  �ռ临�Ӷ�O(1)  ʱ�临�Ӷ�O(N)
//Ԫ�ص�˳����Ըı䣬����Ҫ���������г����³��Ⱥ����Ԫ��

//˼·1������ɾ��  --  O(N^2)
//˼·2����������val��ֵ��Ų��������  --  �ռ临�Ӷ�O(N)
//˼·3: ˫ָ�룬��������val��ֵ������ǰ���ֵ

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

//ɾ�����������е��ظ���  --  ȥ���㷨
//����һ����������nums,��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Σ�����ɾ����������³���
//Ԫ�ص����˳��Ӧ�ñ���һ��

//��Ȼ����˫ָ��
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

//�ϲ�������������
//���������ǵݼ�˳�����е���������nums1��nums2
//m��n�ֱ��ʾnums1��nums2��Ԫ�ص���Ŀ
//��ϲ�nums2��nums1�У�ʹ�ϲ��������ͬ�����ǵݼ�˳������
//Ҫ��ʱ�临�Ӷ� - O(N+M)

//void merge(int nums1[], int nums2[], int m, int n)
//{
//	int end1 = m - 1;
//	int end2 = n - 1;
//	int end = m + n - 1;
//
//	while (end1 >= 0 && end2 >= 0) //��һ�������ͽ�����   ���� - &&
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
//	//�����end2������end1û����������Ҫ����
//	//��Ϊend1����nums1ǰ�棬��˳��Ϻ�Ҫ��
//
//	while (end2 > 0) //�����end2û�������ǾͰ�end2ʣ��ķŵ�nums1����ǰ��
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

//�Ƴ�����Ԫ��
//����һ�������ͷ�ڵ�head��һ������val
//��ɾ����������������Node.val == val�Ľڵ㣬�������µ�ͷ�ڵ�
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}ListNode;
//
////����һ  --  ֱ�Ӹ�
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
//				//ͷɾ
//				head = head->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				//ɾ��
//				pre->next = cur->next;
//				free(cur);
//				cur = pre->next;
//			}
//		}
//		else
//		{
//			//������Ϣ
//			pre = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//
////������  --  ����ԭ�����Ѳ���val�Ľڵ��ó�������β�嵽������
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* tail = NULL;
//	head = NULL;  //��ֹȫ��Ҫɾ���ģ�head���ΪҰָ��
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
//				//β��
//				tail->next = cur;
//				tail = tail->next;
//			}
//
//			cur = cur->next;
//		}
//	}
//
//	if (tail)  //��ֹ�ǿ�����tailԭ����NULL���޷�����
//	{
//		tail->next = NULL;  //��ֹ���һ��Ҫɾ��ɾ������������һ���ڵ��next��Ұָ��
//	}
//
//	return head;
//}
//
////������  --  �ڱ�λͷ�ڵ�
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* tail = NULL;
//	struct ListNode* cur = head;
//
//	//�ڱ�λ��ͷ�ڵ�
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
//	//�ͷ��ڱ�λͷ�ڵ㣬�����ڴ����
//	struct ListNode* del = head;
//	head = head->next;
//	free(del);
//
//	return head;
//}

//��ת����
//�����������ͷ�ڵ�head���뷴ת���������ط�ת�������
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
// 
////����һ  --  ͷ��
//struct ListNode* reverseList(struct ListNode* head) {
//	struct ListNode* cur = head;
//	struct ListNode* newhead = NULL;
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//		//ͷ��
//		cur->next = newhead;
//		newhead = cur;
//
//		cur = next;
//	}
//
//	return newhead;
//}
////������  --  ָ��ķ���ߵ�
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
//		//��ָ��
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


//������м�ڵ�
//����һ��ͷ�ڵ�λhead�ķǿյ���������������м�ڵ�
//����������м�ڵ㣬�򷵻صڶ����м�ڵ�
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
////����  --  ����ָ��
//struct ListNode* middleNode(struct ListNode* head) {
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//
//	while (fast && fast->next)  //������дfast->next && fast  --  ˼��Ϊʲô��
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	return slow;
//}

//�����е�����K���ڵ�
//����һ����������������е�����k���ڵ�
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//};
////����  --  ����ָ��  --  fast��slow����k
//struct ListNode* getKthFromEnd(struct ListNode* head, int k)
//{
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//
//	while (k--)  //k-- ��ѭ��k��     --k��ѭ��k-1��
//	{
//		//fast��û�߳�k��������û��k����
//		if (fast == NULL)
//		{
//			return NULL;
//		}
//
//		//fast����k��
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
