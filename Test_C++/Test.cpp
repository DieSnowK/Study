#include <iostream>
#include <assert.h>
using namespace std;

// 链接：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// 计算日期到天数转换
// 根据输入的日期，计算是这一年的第几天
// 保证年份为四位数且日期合法
//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//
//    // 这一月份之前的天数 + 这一个月过了多少天
//    int monthDays1_N[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
//
//    int n = monthDays1_N[month - 1] + day;
//
//    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//    {
//        n += 1;
//    }
//
//    cout << n << endl;
//
//    return 0;
//}

// 链接：https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// 求1+2+3+...+n
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
// 不使用全局变量，只用静态成员变量
class Sum
{
public:
    Sum() //构造函数，每次构造自动调用
    {
        _sum += _i;
        _i++;
    }

    static int GetSum()
    {
        return _sum;
    }

private:
    static int _sum;
    static int _i;
};

int Sum::_sum = 0;
int Sum::_i = 1;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        Sum a[n]; // 调用n次sum的构造函数
        return Sum::GetSum();
    }
};