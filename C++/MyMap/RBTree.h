#pragma once
#include <iostream>
#include <utility>
#include <assert.h>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template <class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED) // 默认插入红色节点
		, _data(data)
	{}
};

template <class T, class Ref, class Ptr>
struct __RBTree_Iterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTree_Iterator<T, Ref, Ptr> Self;
	Node* _node;

	__RBTree_Iterator(Node* node)
		: _node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(operator*());
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			// 下一个就是右子树的最左节点
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}

			_node = left;
		}
		else
		{
			// 找祖先里面 孩子不是父亲的右 的那个祖先
			Node* parent = _node->_parent;
			Node* cur = _node;

			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self operator--()
	{
		if (_node->_left)
		{
			// 下一个节点是左子树的最右节点
			Node* right = _node->_left;
			while (right->_right)
			{
				right = right->_right;
			}

			_node = right;
		}
		else
		{
			// 找祖先里面 孩子不是父亲的左 的那个祖先
			Node* parent = _node->_parent;
			Node* cur = _node;

			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
	}
};

template <class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __RBTree_Iterator<T, T&, T*> iterator;
	typedef __RBTree_Iterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left) // left --> 防止空树
		{
			left = left->_left;
		}

		return iterator(left); // 匿名结构体
	}

	const_iterator begin() const
	{
		Node* left = _root;
		while (left && left->_left) // left --> 防止空树
		{
			left = left->_left;
		}

		return iterator(left); // 匿名结构体
	}

	iterator end()
	{
		return iterator(nullptr); // 非带头节点版本
	}

	const_iterator end() const
	{
		return iterator(nullptr); // 非带头节点版本
	}

	pair<iterator, bool> Insert(const T& data) // 返回值用于返回插入值迭代器位置和是否插入成功
	{
		KeyOfT kot; // 仿函数 --> 用于获取data的键值

		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newnode = cur; // 用于保存插入值的实际地址，因为后续cur会变化

		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		// 处理颜色
		while (parent && parent->_col == RED)
		{
			Node* grandparent = parent->_parent;
			assert(grandparent);
			assert(grandparent->_col == BLACK);

			// 关键看叔叔
			if (grandparent->_left == parent)
			{
				Node* uncle = grandparent->_right;
				if (uncle && uncle->_col == RED)
				{
					// 1.uncle存在且为红
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					// 继续往上处理
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					// 2.uncle不存在/存在且为黑
					if (parent->_left == cur)  // 情况二：右单旋 + 变色
					{
						RotateR(grandparent);

						parent->_col = BLACK;
						grandparent->_col = RED;
					}
					else  // 情况三：左右双旋 + 变色
					{
						RotateL(parent);
						RotateR(grandparent);

						cur->_col = BLACK;
						grandparent->_col = RED;
					}

					break;
				}

			}
			else // grandparent->_right == parent
			{
				Node* uncle = grandparent->_left;
				if (uncle && uncle->_col == RED)
				{
					// 1.uncle存在且为红
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					// 继续往上处理
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					// 2.uncle不存在/存在且为黑
					if (parent->_right == cur)  // 情况二：左单旋 + 变色
					{
						RotateL(grandparent);

						parent->_col = BLACK;
						grandparent->_col = RED;
					}
					else  // 情况三：右左双旋 + 变色
					{
						RotateR(parent);
						RotateL(grandparent);

						cur->_col = BLACK;
						grandparent->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK; // 防止一直到根且根节点为红色
		return make_pair(iterator(newnode), true);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}

		if (_root->_col == RED)
		{
			cout << "根节点不是黑色" << endl;
			return false;
		}

		// 获取黑色节点数量基准值  -->  每一条路黑色节点数量相同
		Node* cur = _root;
		int benchmark = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++benchmark;
			}

			cur = cur->_left;
		}

		return PreCheck(_root, 0, benchmark);
	}
private:
	bool PreCheck(Node* root, int blackNum, int& benchmark)
	{
		if (root == nullptr)
		{
			if (blackNum != benchmark)
			{
				cout << "某条黑色节点的数量不相等" << endl;
				return false;
			}
			else
			{
				return true;
			}
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
		}

		return PreCheck(root->_left, blackNum, benchmark)
			&& PreCheck(root->_right, blackNum, benchmark);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL) // 防止subRL本来就为空，对空指针访问
		{
			subRL->_parent = parent;
		}

		// 用于判断原来的parent是否是子树
		Node* grandParent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (grandParent->_left == parent)
			{
				grandParent->_left = subR;
			}
			else
			{
				grandParent->_right = subR;
			}

			subR->_parent = grandParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* grandParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (grandParent->_left == parent)
			{
				grandParent->_left = subL;
			}
			else
			{
				grandParent->_right = subL;
			}

			subL->_parent = grandParent;
		}
	}

	Node* _root = nullptr; // 缺省参数，让默认构造自己处理
};