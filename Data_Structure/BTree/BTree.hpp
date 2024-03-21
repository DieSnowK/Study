#pragma once
#include <iostream>
using namespace std;

template<class K, size_t M>
struct BTreeNode
{
	// 为了方便插入以后再分裂，多给一个空间
	K _keys[M];
	BTreeNode<K, M>* _subs[M + 1];     

	BTreeNode<K, M>* _parent = nullptr;;
	size_t _n = 0; // 记录实际存储关键字的个数

	BTreeNode()
	{
		for (size_t i = 0; i < M; i++)
		{
			_keys[i] = K();
			_subs[i] = nullptr;
		}

		_subs[M] = nullptr;
	}
};


// 数据是存在磁盘的，K是磁盘地址
template <class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:

	// 返回值带回 结点 及 查找的数
	pair<Node*, int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			// 在一个结点查找
			size_t i = 0;
			while (i < cur->_n)
			{
				if (key < cur->_keys[i])
				{
					break;
				}
				else if(key > cur->_keys[i])
				{
					i++;
				}
				else
				{
					return { cur, i };
				}
			}

			// 往孩子去跳
			parent = cur;
			cur = cur->_subs[i];
		}

		return { parent, -1 };
	}

	void InsertKey(Node* node, const K& key, Node* child)
	{
		// 直接插入排序
		int end = node->_n - 1;

		while (end >= 0)
		{
			if (key < node->_keys[end])
			{
				node->_keys[end + 1] = node->_keys[end];
				node->_subs[end + 2] = node->_subs[end + 1];
				end--;
			}
			else
			{
				break;
			}
		}

		node->_keys[end + 1] = key;
		node->_subs[end + 2] = child; // 该结点的右子树
		if (child)
		{
			child->_parent = node;
		}

		node++;
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;

			return true;
		}


		// key已存在，不允许插入
		pair<Node*, int> ret = Find(key);
		if (ret.second >= 0)
		{
			return false;
		}

		// 如果没有找到，Find()顺便带回了要插入的那个叶子结点
		// 循环每次往cur插入，newkey和child
		Node* parent = ret.first;
		K newKey = key;
		Node* child = nullptr;

		while (1)
		{
			InsertKey(parent, newKey, child);

			// 没有满，插入就结束
			if (parent->_n < M)
			{
				return true;
			}
			
			// 满了就要分裂
			// 分裂一般[mid + 1, M - 1]给兄弟
			Node* bro = new Node;
			size_t mid = M / 2;
			size_t i = mid + 1;
			size_t j = 0;
			
			for (; i < M; i++)
			{
				// 分裂拷贝key和key的左孩子
				bro->_keys[j] = parent->_keys[i];
				bro->_subs[j++] = parent->_subs[i];
				
				// 更新parent->_keys[i]父节点为bro
				if (parent->_keys[i])
				{
					parent->_keys[i]->_parent = bro;
				}

				// 拷走之后，重置为默认值，方便观察
				parent->_keys[i] = K();
				parent->_subs[i] = nullptr;
			}

			// 还有最后一个最右孩子
			bro->_subs[j] = parent->_subs[i];
			if (parent->_keys[i])
			{
				parent->_keys[i]->_parent = bro;
			}
			parent->_subs[i] = nullptr;

			bro->_n = j;
			parent->_n -= (bro->_n + 1);

			K midkey = parent->_keys[mid];
			parent->_keys = K();

			// 说明刚刚分裂的是根节点
			if (parent->_parent == nullptr)
			{
				_root = new Node;
				_root->_keys[0] = midkey;
				_root->_subs[0] = parent;
				_root->_subs[1] - bro;
				_root->_n = 1;

				parent->_parent = _root;
				bro->_parent = _root;
				break;
			}
			else
			{
				// 转换成往parent->_parent中去插入midKey和bro
				newKey = midkey;
				child = bro;
				parent = parent->_parent;
			}
		}

		return true;
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
		{
			return;
		}

		// 左 根 左 根 ... 右
		for (size_t i = 0; i < M; i++)
		{
			_InOrder(cur->_subs[i]); // 左子树
			cout << cur->_keys[i] << " "; // 根
		}
		_InOrder(cur->_subs[i]); // 最右子树
	}

	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root = nullptr;
};