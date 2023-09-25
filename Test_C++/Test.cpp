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

// 链接：https://leetcode.cn/problems/kth-largest-element-in-an-array/
// 数组中的第K个最大元素
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k)
//    {
//        // 建大堆 -- O(N)
//        priority_queue<int> maxHeap(nums.begin(), nums.end());
//
//        while (--k)
//        {
//            maxHeap.pop();
//        }
//
//        return maxHeap.top();
//    }
//};

// 链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree/
// 根据二叉树创建字符串
//class Solution {
//public:
//	string tree2str(TreeNode* root)
//	{
//		if (root == nullptr)
//		{
//			return string();
//		}
//
//		string str;
//		str += to_string(root->val);
//
//		// 左边不为空或者左边为空，右边不为空，左边需要加括号
//		if (root->left || root->right)
//		{
//			str += '(';
//			str += tree2str(root->left);
//			str += ')';
//		}
//
//		// 右边不为空，右边需要加括号
//		if (root->right)
//		{
//			str += '(';
//			str += tree2str(root->right);
//			str += ')';
//		}
//
//		return str;
//	}
//};

// 链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// 二叉树的层次遍历
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        queue<TreeNode*> q;
//        size_t levelSize = 0; // 用于控制每层元素剩余数量，神之一手 :P
//
//        if (root)
//        {
//            q.push(root);
//            levelSize = 1;
//        }
//
//        vector<vector<int>> vv;
//
//        while (!q.empty())
//        {
//            // 控制一层一层出
//            vector<int> v;
//            for (size_t i = 0; i < levelSize; i++)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//                v.push_back(front->val);
//
//                if (front->left)
//                {
//                    q.push(front->left);
//                }
//
//                if (front->right)
//                {
//                    q.push(front->right);
//                }
//            }
//
//            vv.push_back(v);
//            // 当前层出完了，下一层都进队列，队列的size就是下一层的levelSize
//            levelSize = q.size();
//        }
//
//        return vv;
//    }
//};

// 链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
// 二叉树的最近公共祖先

// 法一
//class Solution {
//public:
//    bool Find(TreeNode* sub, TreeNode* x) // 本质就是前序遍历
//    {
//        if (sub == nullptr)
//        {
//            return false;
//        }
//
//        return sub == x
//            || Find(sub->left, x)
//            || Find(sub->right, x);
//    }
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (root == nullptr)
//        {
//            return nullptr;
//        }
//
//        if (root == q || root == p) // 其中一个为根，那么最近公共祖先就是此根
//        {
//            return root;
//        }
//
//        bool pInLeft, pInRight, qInLeft, qInRight; // 命名合适为关键所在
//        pInLeft = Find(root->left, p);
//        pInRight = !pInLeft;
//
//        qInLeft = Find(root->left, q);
//        qInRight = !qInLeft;
//
//        // 1.一个在左，一个在右，root就是最近祖先
//        if (pInLeft && qInRight || qInLeft && pInRight)
//        {
//            return root;
//        }
//        else if (pInLeft && qInLeft) // 2.都在左，递归去左树找
//        {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else if (pInRight && qInRight) // 3.都在右，递归去右树找
//        {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        else
//        {
//            return nullptr; // 本题而言，理论不会走到这里
//        }
//    }
//};

// 法二
//class Solution {
//public:
//    bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
//    {
//        if (root == nullptr)
//        {
//            return false;
//        }
//
//        path.push(root);
//        if (root == x)
//        {
//            return true;
//        }
//
//        if (FindPath(root->left, x, path))
//        {
//            return true;
//        }
//
//        if (FindPath(root->right, x, path))
//        {
//            return true;
//        }
//
//        path.pop();
//        return false;
//    }
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        stack<TreeNode*> pPath, qPath;
//        FindPath(root, p, pPath);
//        FindPath(root, q, qPath);
//
//        // 类似链表相交
//        while (pPath.size() != qPath.size())
//        {
//            if (pPath.size() > qPath.size())
//            {
//                pPath.pop();
//            }
//            else
//            {
//                qPath.pop();
//            }
//        }
//
//        while (pPath.top() != qPath.top())
//        {
//            pPath.pop();
//            qPath.pop();
//        }
//
//        return pPath.top();
//    }
//};

// 链接：https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
// 二叉搜索树与双向链表
//class Solution
//{
//public:
//	void InOrderConvert(TreeNode* cur, TreeNode*& prev)
//	{
//		if (cur == nullptr)
//		{
//			return;
//		}
//
//		InOrderConvert(cur->left, prev);
//
//		cur->left = prev;
//		if (prev)
//		{
//			prev->right = cur;
//		}
//
//		prev = cur;
//
//		InOrderConvert(cur->right, prev);
//	}
//
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		TreeNode* prev = nullptr;
//		InOrderConvert(pRootOfTree, prev); // 中序遍历，以更改链接关系
//
//		// 找头节点，用于返回
//		TreeNode* head = pRootOfTree;
//		while (head && head->left)
//		{
//			head = head->left;
//		}
//
//		return head;
//	}
//};

// 链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// 从前序与中序遍历序列构造二叉树
 // 大思路：前序创建树，中序分割左右子树
 // 子树区间确认是否继续递归创建字数，不存在区间则是空树
//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend)
//    {
//        if (inbegin > inend)
//        {
//            return nullptr;
//        }
//
//        TreeNode* root = new TreeNode(preorder[prei++]); // 存入该节点(根)
//
//        // 分割中序
//        int ini = inbegin;
//        while (ini <= inend)
//        {
//            if (inorder[ini] == root->val)
//            {
//                break;
//            }
//            else
//            {
//                ini++;
//            }
//        }
//
//        // []inbegin, ini-1] ini [ini+1, inend]
//        root->left = _buildTree(preorder, inorder, prei, inbegin, ini - 1);
//        root->right = _buildTree(preorder, inorder, prei, ini + 1, inend);
//
//        return root;
//    }
//
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//    {
//        int i = 0;
//        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
//    }
//};

// 链接：https://leetcode.cn/problems/binary-tree-preorder-traversal/
// 二叉树的前序遍历：非递归版本

 // 左路节点
 // 左路节点右子树  -->  子问题
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root)
//    {
//        stack<TreeNode*> st; // 用于察觉从左路节点 --> 子路节点
//        vector<int> v;
//        TreeNode* cur = root;
//
//        while (cur || !st.empty()) // 树没遍历完，栈没空，都要继续
//        {
//            // 开始访问一棵树
//            // 1.左路节点
//            while (cur)
//            {
//                v.push_back(cur->val);
//                st.push(cur);
//
//                cur = cur->left;
//            }
//
//            // 左路节点的右子树需要访问
//            TreeNode* top = st.top();
//            st.pop();
//
//            // 一个节点从栈里面出来意味着
//            // 这个节点及他的左子树访问完了，还剩右子树
//
//            cur = top->right; // 子问题访问右子树
//        }
//
//        return v;
//    }
//};

// 链接：https://leetcode.cn/problems/binary-tree-inorder-traversal/
// 二叉树的中序遍历：非递归版本

// 左路节点
// 左路节点右子树  -->  子问题
//class Solution 
//{
//public:
//    vector<int> inorderTraversal(TreeNode* root)
//    {
//        stack<TreeNode*> st; // 用于察觉从左路节点 --> 子路节点
//        vector<int> v;
//        TreeNode* cur = root;
//
//        while (cur || !st.empty()) // 树没遍历完，栈没空，都要继续
//        {
//            // 开始访问一棵树
//            // 1.左路节点
//            while (cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            // 左路节点的右子树需要访问
//            TreeNode* top = st.top();
//            st.pop();
//            v.push_back(top->val);
//
//            // 一个节点从栈里面出来意味着
//            // 这个节点及他的左子树访问完了，还剩右子树
//
//            cur = top->right; // 子问题访问右子树
//        }
//
//        return v;
//    }
//};

// 链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
// 二叉树的后序遍历：非递归版本
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root)
//    {
//        stack<TreeNode*> st; // 用于察觉从左路节点 --> 子路节点
//        vector<int> v;
//        TreeNode* cur = root;
//        TreeNode* prev = nullptr; // prev用于记录路径
//
//        while (cur || !st.empty()) // 树没遍历完，栈没空，都要继续
//        {
//            // 开始访问一棵树
//            // 1.左路节点
//            while (cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            // 一个节点从栈里面出来意味着这个节点及他的左子树访问完了，还剩右子树
//            TreeNode* top = st.top();
//
//            // 栈顶节点右子树为空或者上一个访问节点是右子树的根，说明右子树已经访问过了，可以访问
//            // 否则，子问题访问top的右子树
//            if (top->right == nullptr || top->right == prev)
//            {
//                v.push_back(top->val);
//                prev = top;
//
//                st.pop();
//            }
//            else
//            {
//                cur = top->right; // 子问题访问右子树
//            }
//        }
//
//        return v;
//    }
//};

// 链接：https://leetcode.cn/problems/top-k-frequent-words/
// 前K个高频单词
// 法一：TOPK + 仿函数
//class Solution
//{
//public:
//    struct Less
//    {
//        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2) const
//        {
//            if (kv1.second < kv2.second) // 次数比较
//            {
//                return true;
//            }
//
//            if (kv1.second == kv2.second && kv1.first > kv2.first) // 同频率，字典顺序输出
//            {
//                return true;
//            }
//
//            return false;
//        }
//    };
//
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        // 统计次数
//        map<string, int> countMap;
//        for (auto& str : words)
//        {
//            countMap[str]++;
//        }
//
//        // topk - 同时调整相同频率的单词排序 --> 利用仿函数
//        // Less - 默认建大堆
//        priority_queue<pair<string, int>, vector<pair<string, int>>, Less> maxHeap(countMap.begin(), countMap.end());
//
//        // 排序完入表
//        vector<string> v;
//        while (k--)
//        {
//            v.push_back(maxHeap.top().first);
//            maxHeap.pop();
//        }
//
//        return v;
//    }
//};

// 法二：排序
//class Solution
//{
//public:
//    struct Greater
//    {
//        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2) const
//        {
//            if (kv1.second > kv2.second) // 次数比较
//            {
//                return true;
//            }
//
//            return false;
//        }
//    };
//
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        // 统计次数 - 按string排序，即符合字典顺序要求
//        map<string, int> countMap;
//        for (auto& str : words)
//        {
//            countMap[str]++;
//        }
//
//        // 稳定排序 - 不破坏string的相对顺序
//        vector<pair<string, int>> sortV(countMap.begin(), countMap.end()); // 转移数据，用于排序，因为sort要随机迭代器
//        stable_sort(sortV.begin(), sortV.end(), Greater());
//
//        // 排序完入表
//        vector<string> v;
//        for (size_t i = 0; i < k; i++)
//        {
//            v.push_back(sortV[i].first);
//        }
//
//        return v;
//    }
//};

// 法三：multimap排序
//class Solution
//{
//public:
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        // 统计次数 - 按string排序，即符合字典顺序要求
//        map<string, int> countMap;
//        for (auto& str : words)
//        {
//            countMap[str]++;
//        }
//
//        // 再按频率排序，且multimap允许存在多个相同的值
//        // 不能升序然后反向迭代器取，思考为什么？
//        multimap<int, string, greater<int>> sortMap;
//        for (auto& kv : countMap)
//        {
//            sortMap.insert(make_pair(kv.second, kv.first));
//        }
//
//        // 排序完入表
//        vector<string> v;
//        multimap<int, string, greater<int>>::iterator it = sortMap.begin();
//        for (size_t i = 0; i < k; i++)
//        {
//            v.push_back(it->second);
//            ++it;
//        }
//
//        return v;
//    }
//};

// 链接：https://leetcode.cn/problems/intersection-of-two-arrays/
// 两个数组的交集
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//    {
//        // 用set排序 + 去重
//        set<int> s1(nums1.begin(), nums1.end());
//        set<int> s2(nums2.begin(), nums2.end());
//        set<int>::iterator it1 = s1.begin();
//        set<int>::iterator it2 = s2.begin();
//        vector<int> v;
//
//        while (it1 != s1.end() && it2 != s2.end()) //任意一个结束则结束
//        {
//            // 小的++
//            if (*it1 < *it2)
//            {
//                ++it1;
//            }
//            else if (*it1 > *it2)
//            {
//                ++it2;
//            }
//            else
//            {
//                // 相等就是交集，同时++
//                v.push_back(*it1);
//                ++it1;
//                ++it2;
//            }
//        }
//
//        return v;
//    }
//};

// 链接：https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/
// 在长度为2N的数组中找出重复N次的元素
//class Solution {
//public:
//    int repeatedNTimes(vector<int>& nums)
//    {
//        unordered_map<int, int> countMap;
//        for (auto& e : nums)
//        {
//            countMap[e]++;
//        }
//
//        for (auto& kv : countMap)
//        {
//            if (kv.second == nums.size() / 2)
//            {
//                return kv.first;
//            }
//        }
//
//        return 0;
//    }
//};

// 链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/submissions/
// 逆波兰表达式求值  --  用包装器处理
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens)
//    {
//        stack<long long> st;
//        // 用function包装器统一包装函数
//        map<string, function<long long(long long, long long)>> opFuncMap =
//        {
//            // 初始化列表 + initializer_list + lambda
//            {"+", [](long long a, long long b) {return a + b; }},
//            {"-", [](long long a, long long b) {return a - b; }},
//            {"*", [](long long a, long long b) {return a * b; }},
//            {"/", [](long long a, long long b) {return a / b; }},
//        };
//
//        for (auto& str : tokens)
//        {
//            if (opFuncMap.count(str)) // 操作符
//            {
//                long long right = st.top();
//                st.pop();
//                long long left = st.top();
//                st.pop();
//                st.push(opFuncMap[str](left, right));
//            }
//            else // 操作数
//            {
//                st.push(stoll(str));
//            }
//        }
//
//        return st.top();
//    }
//};