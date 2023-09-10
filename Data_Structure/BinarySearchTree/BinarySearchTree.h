#pragma once
#include <iostream>

// Keyģ��
namespace Key
{
	template <class K>
	struct BSTreeNode // Ϊ������������ʣ���struct
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template <class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		//BSTree()
		//{}

		// C++11���÷���ǿ�Ʊ���������Ĭ�ϵĹ��캯��
		BSTree() = default;

		BSTree(const BSTree<K>& t)
		{
			_root = _Copy(t._root);
			return *this;
		}

		~BSTree()
		{
			_Destroy(_root);
		}

		BSTree<K> operator=(BSTree<K> t)
		{
			std::swap(_root, t._root);
			return *this;
		}

		// �����������ķǵݹ��淨
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr; // ��¼���ڵ�λ�ã��Ա����
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false; // ����򲻲���
				}
			}

			// curΪ�գ����ҵ��˲���λ��
			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}

			return false;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// ɾ��
					if (cur->_left == nullptr) // ��Ϊ�գ�ֻ���Һ���
					{
						if (cur == _root) // ɾ�����ڵ�
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr) // ��Ϊ�գ�ֻ������
					{
						if (cur == _root) // ɾ�����ڵ�
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
						cur = nullptr;
					}
					else // ���Ҷ���Ϊ�գ�����������
					{
						// �滻��ɾ��������������С�ڵ�����滻
						Node* minParent = cur;
						Node* min = cur->_right;

						while (min->_left)
						{
							minParent = min;
							min = min->_left;
						}

						std::swap(min->_key, cur->_key);
						if (min == minParent->_left)
						{
							minParent->_left = min->_right; // �����ң�min�϶�Ϊ����
						}
						else
						{
							minParent->_right = min->_right; // min����cur���Һ���
						}

						delete min;
						min = nullptr;
					} 

					return true;
				} // end of delete
			} // end of find key

			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
		}
////////////////////////////////////////////////////////////////////////////////////////
		// �����������ĵݹ��淨
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* copyRoot = new Node(root->_key);
			copyRoot->_left = _Copy(root->_left);
			copyRoot->_right = _Copy(root->_right);

			return copyRoot;
		}

		void _Destroy(Node*& root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
			root = nullptr; // �����ã��ÿ���Ч��ֹҰָ��
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			std::cout << root->_key << " ";
			_InOrder(root->_right);
		}

		bool _InsertR(Node*& root, const K& key) // ����Node*&��֮һ�֣������ã������޸�root
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key); // �����ã������޸��²�root�������ӹ�ϵ����
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return true;;
			}
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				// ɾ��
				Node* del = root;
				if (root->_left == nullptr) // ��Ϊ�գ�ֻ���Һ���
				{
					root = root->_right; // root������һ��root->_right/_left�����ã��޸�root�����޸���һ������ӹ�ϵ
				}
				else if (root->_right == nullptr) // ��Ϊ�գ�ֻ������
				{
					root = root->_left;
				}
				else // ��������Ϊ�գ�����������
				{
					// �滻��ɾ��������������С�ڵ�����滻
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}

					std::swap(min->_key, root->_key);
					return _EraseR(root->_right, key); // �������ٴ˻��鵽ֻ��һ�����ӵ�/û���ӵ����
				}

				delete del;
				del = nullptr;
				return true;
			}
		}

	private:
		Node* _root = nullptr;
	};
}

// KeyValueģ��
namespace KeyValue
{
	template <class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			//...

			return true;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
}