#include <iostream>
#include <string>
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
//class Sum
//{
//public:
//    Sum() //���캯����ÿ�ι����Զ�����
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
//        Sum a[n]; // ����n��sum�Ĺ��캯��
//        return Sum::GetSum();
//    }
//};

// ���ӣ�https://leetcode.cn/problems/reverse-only-letters/description/
// ������ת��ĸ
//class Solution 
//{
//public:
//    string reverseOnlyLetters(string s)
//    {
//        size_t begin = 0, end = s.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !isalpha(s[begin])) // ע���Խ�紦��
//            {
//                begin++;
//            }
//
//            while (begin < end && !isalpha(s[end]))
//            {
//                end--;
//            }
//
//            //��λ��ʱ���Ѿ���������ĸ��
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//
//        return s;
//    }
//};

// ����:https://leetcode.cn/problems/add-strings/submissions/
// �ַ������
// �汾һ - ͷ��Ч�ʵ���
//class Solution {
//public:
//    string addStrings(string num1, string num2)
//    {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0;
//        string strRet;
//
//        while (end1 >= 0 || end2 >= 0) // �������������Ž�������
//        {
//            // ��ֵ���ַ�������ȡ����,��Ҫ���ǵ��Ƿ���ȡ�꣬0��λ
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = val1 + val2 + next;
//            next = ret > 9 ? 1 : 0;
//
//            //ͷ��
//            strRet.insert(strRet.begin(), (ret % 10) + '0');
//
//            end1--;
//            end2--;
//        }
//
//        // �����λ - 
//        if (next == 1)
//        {
//            strRet.insert(strRet.begin(), '1');
//        }
//
//        return strRet;
//    }
//};

// �汾�� - β�壬�Կռ任ʱ��
//class Solution {
//public:
//    string addStrings(string num1, string num2)
//    {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0;
//        string strRet;
//
//        while (end1 >= 0 || end2 >= 0) // �������������Ž�������
//        {
//            // ��ֵ���ַ�������ȡ����,��Ҫ���ǵ��Ƿ���ȡ�꣬0��λ
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = val1 + val2 + next;
//            next = ret > 9 ? 1 : 0;
//
//            // β�壬���һ�����ã���O(N)�ռ任ʱ��
//            strRet += (ret % 10) + '0';
//
//            end1--;
//            end2--;
//        }
//
//        // �����λ
//        if (next == 1)
//        {
//            strRet += '1';
//        }
//
//        // ����
//        reverse(strRet.begin(), strRet.end());
//
//        return strRet;
//    }
//};

// ���ӣ�https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
// �ַ������һ�����ʵĳ���
//int main()
//{
//    string str;
//
//    // ��ȡһ���ַ���
//    // ˼����Ϊʲô����cin�أ�
//    getline(cin, str);
//
//    size_t pos = str.rfind(' ');
//    if (pos != string::npos)
//    {
//        cout << str.size() - pos - 1 << endl;
//    }
//    else
//    {
//        cout << str.size() << endl;
//    }
//
//    return 0;
//}

// ���ӣ�https://leetcode.cn/problems/first-unique-character-in-a-string/
// �ַ����еĵ�һ��Ψһ�ַ�
//class Solution {
//public:
//    int firstUniqChar(string s)
//    {
//        // ��ϣ
//        int countArr[26] = { 0 };
//        for (auto ch : s)
//        {
//            countArr[ch - 'a']++;
//        }
//
//        // ����ԭ�ַ���,�ҳ��ִ���Ϊ1��
//        for (size_t i = 0; i < s.size(); i++)
//        {
//            if (countArr[s[i] - 'a'] == 1)
//            {
//                return i;
//            }
//        }
//
//        return -1;
//    }
//};

// ���ӣ�https://leetcode.cn/problems/valid-palindrome/
// ��֤���Ĵ�