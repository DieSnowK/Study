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
//class Solution {
//public:
//    bool isPalindrome(string s)
//    {
//        // Ϊ���ڴ�����ת��ΪСд��ĸ
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
//            while (begin < end && !isalnum(s[begin]))  // �ǵ÷�Խ�紦��
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

// ���ӣ�https://leetcode.cn/problems/single-number/description/
// ֻ����һ�ε�����
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

// ���ӣ�https://leetcode.cn/problems/pascals-triangle/description/
// �������
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        // ��vectorʵ�ֶ�ά����
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//
//        // ��ʼ��ÿ��һά����
//        for (size_t i = 0; i < vv.size(); i++)
//        {
//            vv[i].resize(i + 1, 0);
//            vv[i].front() = vv[i].back() = 1;
//        }
//
//        // �����������
//        for (size_t i = 2; i < vv.size(); i++)
//        {
//            // ÿһ��
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

// ���ӣ�https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/
// �绰�������ĸ���
// ���͵������������

//class Solution {
//public:
//    // Ϊ���ڻ��ÿ�����ֶ�Ӧ���ַ������Ƚ���һ��ӳ���ϵ
//    char* numTostr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//
//    // ������ȱ��� - ���͵Ķ�·�ݹ�
//    // Ϊ�˵ݹ飬������Ӻ���
//    void Combine(string& digits, int di, vector<string>& retv, string combineStr = "")
//    {
//        if (di == digits.size()) //�ݹ��������
//        {
//            retv.push_back(combineStr);
//            return;
//        }
//
//        // ȡ�����ַ�ӳ����ӡ�ַ���
//        int num = digits[di] - '0';
//        string str = numTostr[num]; // ��������
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

// ���ӣ�https://leetcode-cn.com/problems/min-stack/
// ��Сջ

//class MinStack {
//public:
//    MinStack()
//    {
//        // ����Ҫд���캯������ȥ���ó�Ա��Ĭ�Ϲ��캯��
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

// ���ӣ�https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
// ջ�ĵ���ѹ������
// ��˼·����ջģ��������� --> �Ƿ���������ջ

//bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
//{
//    stack<int> st;
//    int popi = 0;
//
//    for (auto& pushVal : pushV)
//    {
//        // ����ѹ������
//        st.push(pushVal);
//
//        // ��ջ����ƥ���Ҫ�����Ƚϣ����ܻ��ж��ƥ��
//        while (!st.empty() && st.top() == popV[popi])
//        {
//            ++popi;
//            st.pop();
//        }
//
//    }
//
//    return st.empty(); //return popi == popV.size(); // ���Ҳ����
//}

// ���ӣ�https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
// �沨�����ʽ��ֵ  --  ��׺���ʽ��ֵ
// ˼·����ջģ���������
// 1.�������֣���ջ
// 2.�����������ȡ��ջ������Ԫ�أ�������������ջ

//class Solution {
//public:
//    // �����Ѿ�ʡȥ�˽���׺���ʽתΪ��׺���ʽ�Ĺ����� :P
//    int evalRPN(vector<string>& tokens)
//    {
//        stack<int> st;
//
//        for (auto& str : tokens) // һֱ��ȡvector�е��ַ���
//        {
//            if (str == "+" || str == "-"
//                || str == "*" || str == "/")
//            {
//                // �����������ȡ��ջ������Ԫ��
//                int right = st.top();
//                st.pop();
//                int left = st.top();
//                st.pop();
//
//                // ������������ջ
//                switch (str[0]) // ȡ�������ַ���ʱ���ַ�����ֻ�з���
//                {              // ���Կ����������ַ���ת��Ϊchar
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
//                // ������ջ
//                st.push(stoi(str));
//            }
//        } // end of for()
//
//        return st.top();
//    }
//};

// ���ӣ�https://leetcode.cn/problems/kth-largest-element-in-an-array/
// �����еĵ�K�����Ԫ��
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k)
//    {
//        // ����� -- O(N)
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

// ���ӣ�https://leetcode-cn.com/problems/construct-string-from-binary-tree/
// ���ݶ����������ַ���
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
//		// ��߲�Ϊ�ջ������Ϊ�գ��ұ߲�Ϊ�գ������Ҫ������
//		if (root->left || root->right)
//		{
//			str += '(';
//			str += tree2str(root->left);
//			str += ')';
//		}
//
//		// �ұ߲�Ϊ�գ��ұ���Ҫ������
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

// ���ӣ�https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// �������Ĳ�α���
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        queue<TreeNode*> q;
//        size_t levelSize = 0; // ���ڿ���ÿ��Ԫ��ʣ����������֮һ�� :P
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
//            // ����һ��һ���
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
//            // ��ǰ������ˣ���һ�㶼�����У����е�size������һ���levelSize
//            levelSize = q.size();
//        }
//
//        return vv;
//    }
//};

// ���ӣ�https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
// �������������������

// ��һ
//class Solution {
//public:
//    bool Find(TreeNode* sub, TreeNode* x) // ���ʾ���ǰ�����
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
//        if (root == q || root == p) // ����һ��Ϊ������ô����������Ⱦ��Ǵ˸�
//        {
//            return root;
//        }
//
//        bool pInLeft, pInRight, qInLeft, qInRight; // ��������Ϊ�ؼ�����
//        pInLeft = Find(root->left, p);
//        pInRight = !pInLeft;
//
//        qInLeft = Find(root->left, q);
//        qInRight = !qInLeft;
//
//        // 1.һ������һ�����ң�root�����������
//        if (pInLeft && qInRight || qInLeft && pInRight)
//        {
//            return root;
//        }
//        else if (pInLeft && qInLeft) // 2.�����󣬵ݹ�ȥ������
//        {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else if (pInRight && qInRight) // 3.�����ң��ݹ�ȥ������
//        {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        else
//        {
//            return nullptr; // ������ԣ����۲����ߵ�����
//        }
//    }
//};

// ����
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
//        // ���������ཻ
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

// ���ӣ�https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
// ������������˫������
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
//		InOrderConvert(pRootOfTree, prev); // ����������Ը������ӹ�ϵ
//
//		// ��ͷ�ڵ㣬���ڷ���
//		TreeNode* head = pRootOfTree;
//		while (head && head->left)
//		{
//			head = head->left;
//		}
//
//		return head;
//	}
//};

// ���ӣ�https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// ��ǰ��������������й��������
 // ��˼·��ǰ�򴴽���������ָ���������
 // ��������ȷ���Ƿ�����ݹ鴴���������������������ǿ���
//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend)
//    {
//        if (inbegin > inend)
//        {
//            return nullptr;
//        }
//
//        TreeNode* root = new TreeNode(preorder[prei++]); // ����ýڵ�(��)
//
//        // �ָ�����
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

// ���ӣ�https://leetcode.cn/problems/binary-tree-preorder-traversal/
// ��������ǰ��������ǵݹ�汾

 // ��·�ڵ�
 // ��·�ڵ�������  -->  ������
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root)
//    {
//        stack<TreeNode*> st; // ���ڲ������·�ڵ� --> ��·�ڵ�
//        vector<int> v;
//        TreeNode* cur = root;
//
//        while (cur || !st.empty()) // ��û�����꣬ջû�գ���Ҫ����
//        {
//            // ��ʼ����һ����
//            // 1.��·�ڵ�
//            while (cur)
//            {
//                v.push_back(cur->val);
//                st.push(cur);
//
//                cur = cur->left;
//            }
//
//            // ��·�ڵ����������Ҫ����
//            TreeNode* top = st.top();
//            st.pop();
//
//            // һ���ڵ��ջ���������ζ��
//            // ����ڵ㼰�����������������ˣ���ʣ������
//
//            cur = top->right; // ���������������
//        }
//
//        return v;
//    }
//};

// ���ӣ�https://leetcode.cn/problems/binary-tree-inorder-traversal/
// ������������������ǵݹ�汾

// ��·�ڵ�
// ��·�ڵ�������  -->  ������
//class Solution 
//{
//public:
//    vector<int> inorderTraversal(TreeNode* root)
//    {
//        stack<TreeNode*> st; // ���ڲ������·�ڵ� --> ��·�ڵ�
//        vector<int> v;
//        TreeNode* cur = root;
//
//        while (cur || !st.empty()) // ��û�����꣬ջû�գ���Ҫ����
//        {
//            // ��ʼ����һ����
//            // 1.��·�ڵ�
//            while (cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            // ��·�ڵ����������Ҫ����
//            TreeNode* top = st.top();
//            st.pop();
//            v.push_back(top->val);
//
//            // һ���ڵ��ջ���������ζ��
//            // ����ڵ㼰�����������������ˣ���ʣ������
//
//            cur = top->right; // ���������������
//        }
//
//        return v;
//    }
//};

// ���ӣ�https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
// �������ĺ���������ǵݹ�汾
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root)
//    {
//        stack<TreeNode*> st; // ���ڲ������·�ڵ� --> ��·�ڵ�
//        vector<int> v;
//        TreeNode* cur = root;
//        TreeNode* prev = nullptr; // prev���ڼ�¼·��
//
//        while (cur || !st.empty()) // ��û�����꣬ջû�գ���Ҫ����
//        {
//            // ��ʼ����һ����
//            // 1.��·�ڵ�
//            while (cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            // һ���ڵ��ջ���������ζ������ڵ㼰�����������������ˣ���ʣ������
//            TreeNode* top = st.top();
//
//            // ջ���ڵ�������Ϊ�ջ�����һ�����ʽڵ����������ĸ���˵���������Ѿ����ʹ��ˣ����Է���
//            // �������������top��������
//            if (top->right == nullptr || top->right == prev)
//            {
//                v.push_back(top->val);
//                prev = top;
//
//                st.pop();
//            }
//            else
//            {
//                cur = top->right; // ���������������
//            }
//        }
//
//        return v;
//    }
//};

// ���ӣ�https://leetcode.cn/problems/top-k-frequent-words/
// ǰK����Ƶ����
// ��һ��TOPK + �º���
//class Solution
//{
//public:
//    struct Less
//    {
//        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2) const
//        {
//            if (kv1.second < kv2.second) // �����Ƚ�
//            {
//                return true;
//            }
//
//            if (kv1.second == kv2.second && kv1.first > kv2.first) // ͬƵ�ʣ��ֵ�˳�����
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
//        // ͳ�ƴ���
//        map<string, int> countMap;
//        for (auto& str : words)
//        {
//            countMap[str]++;
//        }
//
//        // topk - ͬʱ������ͬƵ�ʵĵ������� --> ���÷º���
//        // Less - Ĭ�Ͻ����
//        priority_queue<pair<string, int>, vector<pair<string, int>>, Less> maxHeap(countMap.begin(), countMap.end());
//
//        // ���������
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

// ����������
//class Solution
//{
//public:
//    struct Greater
//    {
//        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2) const
//        {
//            if (kv1.second > kv2.second) // �����Ƚ�
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
//        // ͳ�ƴ��� - ��string���򣬼������ֵ�˳��Ҫ��
//        map<string, int> countMap;
//        for (auto& str : words)
//        {
//            countMap[str]++;
//        }
//
//        // �ȶ����� - ���ƻ�string�����˳��
//        vector<pair<string, int>> sortV(countMap.begin(), countMap.end()); // ת�����ݣ�����������ΪsortҪ���������
//        stable_sort(sortV.begin(), sortV.end(), Greater());
//
//        // ���������
//        vector<string> v;
//        for (size_t i = 0; i < k; i++)
//        {
//            v.push_back(sortV[i].first);
//        }
//
//        return v;
//    }
//};

// ������multimap����
//class Solution
//{
//public:
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        // ͳ�ƴ��� - ��string���򣬼������ֵ�˳��Ҫ��
//        map<string, int> countMap;
//        for (auto& str : words)
//        {
//            countMap[str]++;
//        }
//
//        // �ٰ�Ƶ��������multimap������ڶ����ͬ��ֵ
//        // ��������Ȼ���������ȡ��˼��Ϊʲô��
//        multimap<int, string, greater<int>> sortMap;
//        for (auto& kv : countMap)
//        {
//            sortMap.insert(make_pair(kv.second, kv.first));
//        }
//
//        // ���������
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

// ���ӣ�https://leetcode.cn/problems/intersection-of-two-arrays/
// ��������Ľ���
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//    {
//        // ��set���� + ȥ��
//        set<int> s1(nums1.begin(), nums1.end());
//        set<int> s2(nums2.begin(), nums2.end());
//        set<int>::iterator it1 = s1.begin();
//        set<int>::iterator it2 = s2.begin();
//        vector<int> v;
//
//        while (it1 != s1.end() && it2 != s2.end()) //����һ�����������
//        {
//            // С��++
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
//                // ��Ⱦ��ǽ�����ͬʱ++
//                v.push_back(*it1);
//                ++it1;
//                ++it2;
//            }
//        }
//
//        return v;
//    }
//};

// ���ӣ�https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/
// �ڳ���Ϊ2N���������ҳ��ظ�N�ε�Ԫ��
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