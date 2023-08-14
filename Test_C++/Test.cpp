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
//class Sum
//{
//public:
//    Sum() //构造函数，每次构造自动调用
//    {
//        _sum += _i;
//        _i++;
//    }
//
//    static int GetSum()
//    {
//        return _sum;
//    }
//
//private:
//    static int _sum;
//    static int _i;
//};
//
//int Sum::_sum = 0;
//int Sum::_i = 1;
//
//class Solution
//{
//public:
//    int Sum_Solution(int n)
//    {
//        Sum a[n]; // 调用n次sum的构造函数
//        return Sum::GetSum();
//    }
//};

// 链接：https://leetcode.cn/problems/reverse-only-letters/description/
// 仅仅反转字母
//class Solution 
//{
//public:
//    string reverseOnlyLetters(string s)
//    {
//        size_t begin = 0, end = s.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !isalpha(s[begin])) // 注意防越界处理
//            {
//                begin++;
//            }
//
//            while (begin < end && !isalpha(s[end]))
//            {
//                end--;
//            }
//
//            //此位置时，已经是两个字母了
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//
//        return s;
//    }
//};

// 链接:https://leetcode.cn/problems/add-strings/submissions/
// 字符串相加
// 版本一 - 头插效率低下
//class Solution {
//public:
//    string addStrings(string num1, string num2)
//    {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0;
//        string strRet;
//
//        while (end1 >= 0 || end2 >= 0) // 两个都结束，才结束运算
//        {
//            // 将值从字符串中提取出来,还要考虑到是否提取完，0补位
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = val1 + val2 + next;
//            next = ret > 9 ? 1 : 0;
//
//            //头插
//            strRet.insert(strRet.begin(), (ret % 10) + '0');
//
//            end1--;
//            end2--;
//        }
//
//        // 清理进位 - 
//        if (next == 1)
//        {
//            strRet.insert(strRet.begin(), '1');
//        }
//
//        return strRet;
//    }
//};

// 版本二 - 尾插，以空间换时间
//class Solution {
//public:
//    string addStrings(string num1, string num2)
//    {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0;
//        string strRet;
//
//        while (end1 >= 0 || end2 >= 0) // 两个都结束，才结束运算
//        {
//            // 将值从字符串中提取出来,还要考虑到是否提取完，0补位
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = val1 + val2 + next;
//            next = ret > 9 ? 1 : 0;
//
//            // 尾插，最后一起逆置，以O(N)空间换时间
//            strRet += (ret % 10) + '0';
//
//            end1--;
//            end2--;
//        }
//
//        // 清理进位
//        if (next == 1)
//        {
//            strRet += '1';
//        }
//
//        // 逆置
//        reverse(strRet.begin(), strRet.end());
//
//        return strRet;
//    }
//};