#include <iostream>
#include <string>
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

// 链接：https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
// 字符串最后一个单词的长度
//int main()
//{
//    string str;
//
//    // 获取一行字符串
//    // 思考：为什么不用cin呢？
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

// 链接：https://leetcode.cn/problems/first-unique-character-in-a-string/
// 字符串中的第一个唯一字符
//class Solution {
//public:
//    int firstUniqChar(string s)
//    {
//        // 哈希
//        int countArr[26] = { 0 };
//        for (auto ch : s)
//        {
//            countArr[ch - 'a']++;
//        }
//
//        // 遍历原字符串,找出现次数为1的
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

// 链接：https://leetcode.cn/problems/valid-palindrome/
// 验证回文串
//class Solution {
//public:
//    bool isPalindrome(string s)
//    {
//        // 为便于处理，都转化为小写字母
//        for (auto& ch : s)
//        {
//            if (ch >= 'A' && ch <= 'Z')
//            {
//                ch += 32;
//            }
//        }
//
//        int begin = 0, end = s.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !isalnum(s[begin]))  // 记得防越界处理
//            {
//                begin++;
//            }
//
//            while (begin < end && !isalnum(s[end]))
//            {
//                end--;
//            }
//
//            if (s[begin] == s[end])
//            {
//                begin++;
//                end--;
//            }
//            else
//            {
//                return false;
//            }
//        }
//
//        return true;
//    }
//};

// 链接：https://leetcode.cn/problems/single-number/description/
// 只出现一次的数字
//class Solution {
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        int ret = 0;
//
//        for (auto e : nums)
//        {
//            ret ^= e;
//        }
//
//        return ret;
//    }
//};

// 链接：https://leetcode.cn/problems/pascals-triangle/description/
// 杨辉三角
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        // 用vector实现二维数组
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//
//        // 初始化每个一维数组
//        for (size_t i = 0; i < vv.size(); i++)
//        {
//            vv[i].resize(i + 1, 0);
//            vv[i].front() = vv[i].back() = 1;
//        }
//
//        // 处理杨辉三角
//        for (size_t i = 2; i < vv.size(); i++)
//        {
//            // 每一行
//            for (size_t j = 0; j < vv[i].size(); j++)
//            {
//                if (vv[i][j] == 0) // --> vv.operator[](i).operator[](j);
//                {
//                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//                }
//            }
//        }
//
//        return vv;
//    }
//};

// 链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/
// 电话号码的字母组合
// 典型的排列组合问题

//class Solution {
//public:
//    // 为便于获得每个数字对应的字符串，先建立一个映射关系
//    char* numTostr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//
//    // 深度优先遍历 - 典型的多路递归
//    // 为了递归，用这个子函数
//    void Combine(string& digits, int di, vector<string>& retv, string combineStr = "")
//    {
//        if (di == digits.size()) //递归结束条件
//        {
//            retv.push_back(combineStr);
//            return;
//        }
//
//        // 取数字字符映射相印字符串
//        int num = digits[di] - '0';
//        string str = numTostr[num]; // 拷贝构造
//
//        for (auto ch : str)
//        {
//            Combine(digits, di + 1, retv, combineStr + ch);
//        }
//
//    }
//
//    vector<string> letterCombinations(string digits)
//    {
//        vector<string> v;
//
//        if (digits.empty())
//        {
//            return v;
//        }
//
//        Combine(digits, 0, v);
//
//        return v;
//    }
//};

// 链接：https://leetcode-cn.com/problems/min-stack/
// 最小栈

//class MinStack {
//public:
//    MinStack()
//    {
//        // 不需要写构造函数，会去调用成员的默认构造函数
//    }
//
//    void push(int val)
//    {
//        _st.push(val);
//
//        if (_minst.empty() || val <= _minst.top())
//        {
//            _minst.push(val);
//        }
//    }
//
//    void pop()
//    {
//        if (_st.top() == _minst.top())
//        {
//            _minst.pop();
//        }
//        _st.pop();
//    }
//
//    int top()
//    {
//        return _st.top();
//    }
//
//    int getMin()
//    {
//        return _minst.top();
//    }
//private:
//    stack<int> _st;
//    stack<int> _minst;
//};

// 链接：https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
// 栈的弹出压入序列
// 大思路：用栈模拟这个过程 --> 是否能这样出栈

//bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
//{
//    stack<int> st;
//    int popi = 0;
//
//    for (auto& pushVal : pushV)
//    {
//        // 正常压入数据
//        st.push(pushVal);
//
//        // 出栈序列匹配后要持续比较，可能会有多个匹配
//        while (!st.empty() && st.top() == popV[popi])
//        {
//            ++popi;
//            st.pop();
//        }
//
//    }
//
//    return st.empty(); //return popi == popV.size(); // 这个也可以
//}

// 链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
// 逆波兰表达式求值  --  后缀表达式求值
// 思路：用栈模拟这个过程
// 1.遇到数字，入栈
// 2.遇到运算符，取出栈顶两个元素，计算结果，再入栈

//class Solution {
//public:
//    // 本题已经省去了将中缀表达式转为后缀表达式的过程了 :P
//    int evalRPN(vector<string>& tokens)
//    {
//        stack<int> st;
//
//        for (auto& str : tokens) // 一直获取vector中的字符串
//        {
//            if (str == "+" || str == "-"
//                || str == "*" || str == "/")
//            {
//                // 遇到运算符，取出栈顶两个元素
//                int right = st.top();
//                st.pop();
//                int left = st.top();
//                st.pop();
//
//                // 计算结果，再入栈
//                switch (str[0]) // 取到符号字符串时，字符串里只有符号
//                {              // 所以可以这样将字符串转化为char
//                case '+':
//                    st.push(left + right);
//                    break;
//                case '-':
//                    st.push(left - right);
//                    break;
//                case '*':
//                    st.push(left * right);
//                    break;
//                case '/':
//                    st.push(left / right);
//                    break;
//                }
//            }
//            else
//            {
//                // 数据入栈
//                st.push(stoi(str));
//            }
//        } // end of for()
//
//        return st.top();
//    }
//};
