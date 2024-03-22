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

        _head = new Node(-1, 1); // ͷ�ڵ㣬������1
    }

    bool Search(int target)
    {
        Node* cur = _head;
        int level = _head->_nextV.size() - 1;

        while (level >= 0)
        {

            if (cur->_nextV[level] && target > cur->_nextV[level]->_val)
            {
                // Ŀ��ֵ����һ�����ֵ��������
                cur = cur->_nextV[level];
            }
            else if (!cur->_nextV[level] || target < cur->_nextV[level]->_val)
            {
                // ��һ������ǿ�(β) || Ŀ��ֵ����һ���ڵ�ֵҪС��������
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

        // ���n������ǰ���Ĳ������Ǿ�����һ��_head�Ĳ���
        if (n > _head->_nextV.size())
        {
            _head->_nextV.resize(n, nullptr);
            preV.resize(n, _head);
        }

        // ����ǰ����
        for (size_t i = 0; i < n; i++)
        {
            newnode->_nextV[i] = preV[i]->_nextV[i];
            preV[i]->_nextV[i] = newnode;
        }
    }

    bool Erase(int num)
    {
        vector<Node*> preV = FindPrevNode(num);

        // ��һ����һ������val����val���ڱ���
        if (!preV[0]->_nextV[0] || preV[0]->_nextV[0]->_val != num)
        {
            return false;
        }

        Node* del = preV[0]->_nextV[0];

        // del���ÿһ��ǰ��ָ����������
        for (size_t i = 0; i < del->_nextV.size(); i++)
        {
            preV[i]->_nextV[i] = del->_nextV[i];
        }
        delete del;

        // ���ɾ����߲��㣬��ͷ�ڵ�Ĳ���Ҳ��һ��
        // ������΢��߲���Ч��
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

    // SkipList����
    vector<Node*> FindPrevNode(int num)
    {
        Node* cur = _head;
        int level = _head->_nextV.size() - 1;

        // ����λ��ÿһ��ǰһ�����ָ��
        vector<Node*> preV(level + 1, _head);

        while (level >= 0)
        {
            if (cur->_nextV[level] && num > cur->_nextV[level]->_val)
            {
                // Ŀ��ֵ����һ�����ֵ��������
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