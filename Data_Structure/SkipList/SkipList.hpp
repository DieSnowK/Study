#pragma once
#include <vector>
#include <ctime>
using namespace std;

struct SkipListNode
{
    int _val;
    vector<SkipListNode*> _nextV;

    SkipListNode(int val, int level)
        : _val(val)
        , _nextV(level, nullptr)
    {}
};

class Skiplist
{
    typedef SkipListNode Node;
public:
    Skiplist()
    {
        srand(time(nullptr));

        _head = new Node(-1, 1); // 头节点，层数是1
    }

    bool Search(int target)
    {
        Node* cur = _head;
        int level = _head->_nextV.size() - 1;

        while (level >= 0)
        {

            if (cur->_nextV[level] && target > cur->_nextV[level]->_val)
            {
                // 目标值比下一个结点值大，向右走
                cur = cur->_nextV[level];
            }
            else if (!cur->_nextV[level] || target < cur->_nextV[level]->_val)
            {
                // 下一个结点是空(尾) || 目标值比下一个节点值要小，向下走
                level--;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    void Add(int num)
    {
        vector<Node*> preV = FindPrevNode(num);

        int n = RandomLevel();
        Node* newnode = new Node(num, n);

        // 如果n超过当前最大的层数，那就升高一下_head的层数
        if (n > _head->_nextV.size())
        {
            _head->_nextV.resize(n, nullptr);
            preV.resize(n, _head);
        }

        // 链接前后结点
        for (size_t i = 0; i < n; i++)
        {
            newnode->_nextV[i] = preV[i]->_nextV[i];
            preV[i]->_nextV[i] = newnode;
        }
    }

    bool Erase(int num)
    {
        vector<Node*> preV = FindPrevNode(num);

        // 第一层下一个不是val，则val不在表中
        if (!preV[0]->_nextV[0] || preV[0]->_nextV[0]->_val != num)
        {
            return false;
        }

        Node* del = preV[0]->_nextV[0];

        // del结点每一层前后指针链接起来
        for (size_t i = 0; i < del->_nextV.size(); i++)
        {
            preV[i]->_nextV[i] = del->_nextV[i];
        }
        delete del;

        // 如果删除最高层结点，把头节点的层数也降一下
        // 可以稍微提高查找效率
        int i = _head->_nextV.size() - 1;
        while (i >= 0)
        {
            if (!_head->_nextV[i])
            {
                i--;
            }
            else
            {
                break;
            }
        }
        _head->_nextV.resize(i + 1);

        return true;
    }

    // SkipList精髓
    vector<Node*> FindPrevNode(int num)
    {
        Node* cur = _head;
        int level = _head->_nextV.size() - 1;

        // 插入位置每一层前一个结点指针
        vector<Node*> preV(level + 1, _head);

        while (level >= 0)
        {
            if (cur->_nextV[level] && num > cur->_nextV[level]->_val)
            {
                // 目标值比下一个结点值大，向右走
                cur = cur->_nextV[level];
            }
            else if (!cur->_nextV[level] || num <= cur->_nextV[level]->_val)
            {
                preV[level--] = cur;
            }
        }

        return preV;
    }

    // v1.0 C
    int RandomLevel()
    {
        size_t level = 1;

        // rand() / RAND_MAX -> [0, 1]
        while (rand() <= RAND_MAX * _p && level <= _maxLevel)
        {
            level++;
        }

        return level;
    }

    // v2.0 C++
    // int RandomLevel()
    // {
    //     static std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    // 	static std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // 	size_t level = 1;
    // 	while (distribution(generator) <= _p && level < _maxLevel)
    // 	{
    // 		++level;
    // 	}

    // 	return level;
    // }
private:
    Node* _head;
    size_t _maxLevel = 32;
    double _p = 0.5;
};