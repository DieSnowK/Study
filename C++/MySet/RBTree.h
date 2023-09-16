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
		, _col(RED) // Ĭ�ϲ����ɫ�ڵ�
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
			// ��һ������������������ڵ�
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}

			_node = left;
		}
		else
		{
			// ���������� ���Ӳ��Ǹ��׵��� ���Ǹ�����
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
			// ��һ���ڵ��������������ҽڵ�
			Node* right = _node->_left;
			while (right->_right)
			{
				right = right->_right;
			}

			_node = right;
		}
		else
		{
			// ���������� ���Ӳ��Ǹ��׵��� ���Ǹ�����
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
		while (left && left->_left) // left --> ��ֹ����
		{
			left = left->_left;
		}

		return iterator(left); // �����ṹ��
	}

	const_iterator begin() const
	{
		Node* left = _root;
		while (left && left->_left) // left --> ��ֹ����
		{
			left = left->_left;
		}

		return iterator(left); // �����ṹ��
	}

	iterator end()
	{
		return iterator(nullptr); // �Ǵ�ͷ�ڵ�汾
	}

	const_iterator end() const
	{
		return iterator(nullptr); // �Ǵ�ͷ�ڵ�汾
	}

	pair<iterator, bool> Insert(const T& data) // ����ֵ���ڷ��ز���ֵ������λ�ú��Ƿ����ɹ�
	{
		KeyOfT kot; // �º��� --> ���ڻ�ȡdata�ļ�ֵ

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
		Node* newnode = cur; // ���ڱ������ֵ��ʵ�ʵ�ַ����Ϊ����cur��仯

		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		// ������ɫ
		while (parent && parent->_col == RED)
		{
			Node* grandparent = parent->_parent;
			assert(grandparent);
			assert(grandparent->_col == BLACK);

			// �ؼ�������
			if (grandparent->_left == parent)
			{
				Node* uncle = grandparent->_right;
				if (uncle && uncle->_col == RED)
				{
					// 1.uncle������Ϊ��
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					// �������ϴ���
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					// 2.uncle������/������Ϊ��
					if (parent->_left == cur)  // ��������ҵ��� + ��ɫ
					{
						RotateR(grandparent);

						parent->_col = BLACK;
						grandparent->_col = RED;
					}
					else  // �����������˫�� + ��ɫ
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
					// 1.uncle������Ϊ��
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					// �������ϴ���
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					// 2.uncle������/������Ϊ��
					if (parent->_right == cur)  // ����������� + ��ɫ
					{
						RotateL(grandparent);

						parent->_col = BLACK;
						grandparent->_col = RED;
					}
					else  // �����������˫�� + ��ɫ
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

		_root->_col = BLACK; // ��ֹһֱ�����Ҹ��ڵ�Ϊ��ɫ
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
			cout << "���ڵ㲻�Ǻ�ɫ" << endl;
			return false;
		}

		// ��ȡ��ɫ�ڵ�������׼ֵ  -->  ÿһ��·��ɫ�ڵ�������ͬ
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
				cout << "ĳ����ɫ�ڵ�����������" << endl;
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
			cout << "���������ĺ�ɫ�ڵ�" << endl;
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
		if (subRL) // ��ֹsubRL������Ϊ�գ��Կ�ָ�����
		{
			subRL->_parent = parent;
		}

		// �����ж�ԭ����parent�Ƿ�������
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

	Node* _root = nullptr; // ȱʡ��������Ĭ�Ϲ����Լ�����
};