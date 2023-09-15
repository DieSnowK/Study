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

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED) // Ĭ�ϲ����ɫ�ڵ�
		, _kv(kv)
	{}
};

template <class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
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
		return true;
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