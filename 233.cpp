#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
//这是一个测试文件

int main()
{
	/*double dnum = 10.0 / 3.0;
	//控制cout的显示精度
	//1、强制以小数的形式输出
	cout << fixed;
	//2、控制显示的精度
	cout << setprecision(2);
	//控制宽度,且只控制随后的一个输出对象
	//cout << setw(8);

	cout << dnum << endl;*/


	/*//设置控制台标题
	SetConsoleTitle("打印德玛西亚之力的详细信息");
	double attack = 57.88;
	double attack_growth = 4.5;
	double attack_distance = 172;
	double defence = 27.54;
	double defence_growth = 3.2;
	
	cout << "名称：德玛西亚之力" << endl;
	cout << "伤害" << attack << "(+" << attack_growth << ")";
	cout << "\t";
	cout << "攻击距离：" << attack_distance;*/

	/*int num;
	char ch;
	cout << "请输入一个数字：";
	cin >> num;
	cin >> ch;
	cout << num << "\t" << ch << endl;*/

	/*
	//string是字符串类型
	string str = "你好啊，我是殇雪，我爱你，么么哒";
	cout << str << endl;*/

	/*
	//为数据类型取别名
	typedef int K;
	K num = 233;
	int num1 = 666;
	cout << num << "\t" << num1 << endl;*/

	/*
	double attack = 272;
	double attack1 = 250;
	double attack2 = 240;
	
	cout << left;//1、左对齐 
	cout << setfill('_');//2、亦可用填充来排版
	//需要#include <iomanip> iomanip这个头文件 限定符
	cout << setw(8) << attack
		<< setw(8) << attack1
		<< setw(8) << attack2 << endl;*/

	/*int num1 = 5, num2 = 2;
	cout << num1 / num2 << endl;
	cout << num1 % num2 << endl;
	//取模的场景
	//1、取某个数字的各位 1234%10
	//2、45天是一个月零几天 45&30
	double num3 = num1 / num2;
	cout << num3 << endl;
	//先算右边整形num1/num2
	//然后把算出来的结果给左边的double类型的num3
	//所以说num1/num2的结果只能是整形，这也就是num3=2的原因
	double num4 = (double)num1 / num2;
	//亦可在定义变量时，强制把整形转换为double类型
	cout << num4 << endl;*/
	cout << "2333333";
	


	cin.get();
	cin.get();
	return 0;
}