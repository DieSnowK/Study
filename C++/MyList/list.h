#pragma once
#include <assert.h>
#include <iostream>

namespace SnowK
{
	template <class T>
	struct list_node // 这里用struct是因为默认访问权限是public
	{
		T _data;
		list_node* _prev;
		list_node* _next;

		list_node(const T& val = T())
			: _data(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};


	// list迭代器为一个类 --> 像指针一样的对象
	// 专门服务于list类
	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		// 如何区分?
		// typedef __list_iterator<T, T&, T*>             iterator;
		// typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> iterator;

		Node* _node;

		// 构造函数
		__list_iterator(Node* node)
			: _node(node)
		{}

		// 拷贝构造函数用编译器自动生成的即可

		bool operator==(const iterator& it) const
		{
			return _node == it._node;
		}

		bool operator!=(const iterator& it) const
		{
			return _node != it._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		// ++it
		iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		iterator operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// --it
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		// it--
		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
	};

	// 带头双向循环链表
	template <class T>
	class list 
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next); // 匿名对象
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return iterator(_head->_next); // 匿名对象
		}

		const_iterator end() const
		{
			return iterator(_head);
		}

		void empty_init()
		{
			// 创建并初始化哨兵位头节点
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// 两个链表交换
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end()); //调用范围构造函数
			swap(tmp);
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_back(const T& val)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(val);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//insert(end(), val); //以上代码可用此封装代替
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(val);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode); //匿名对象
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			
			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;

			next->_prev = prev;
			prev->_next = next;
			delete cur;

			return iterator(next); //匿名对象
		}

	private:
		Node* _head;
	};
}
