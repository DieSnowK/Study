#include <iostream>
#include <assert.h>
using namespace std;

// ���ӣ�https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// �������ڵ�����ת��
// ������������ڣ���������һ��ĵڼ���
// ��֤���Ϊ��λ�������ںϷ�
//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//
//    // ��һ�·�֮ǰ������ + ��һ���¹��˶�����
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

// ���ӣ�https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// ��1+2+3+...+n
// Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��
// ��ʹ��ȫ�ֱ�����ֻ�þ�̬��Ա����
class Sum
{
public:
    Sum() //���캯����ÿ�ι����Զ�����
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
        Sum a[n]; // ����n��sum�Ĺ��캯��
        return Sum::GetSum();
    }
};