#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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

//�о��⺯��qsort();
void qsort(
	void* base,
	size_t num,
	size_t width,
	int(__cdecl* compare)(const void*, const void*)
);

int main()
{

	return 0;
}

//��������qsort(); �Լ�дһ�������Կ���ð������
//int main()
//{
//
//	return 0;
//}

//���Ͼ���
//��Ŀ���ݣ�
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
//��
//1 2 3 
//4 5 6
//7 8 9

//int main()
//{
//
//	return 0;
//}