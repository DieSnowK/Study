#pragma once
#include <assert.h>
#include <iostream>

namespace SnowK
{
	template <class T>
	struct list_node // ������struct����ΪĬ�Ϸ���Ȩ����public
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


	// list������Ϊһ���� --> ��ָ��һ���Ķ���
	// ר�ŷ�����list��
	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		// �������?
		// typedef __list_iterator<T, T&, T*>             iterator;
		// typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> iterator;

		Node* _node;

		// ���캯��
		__list_iterator(Node* node)
			: _node(node)
		{}

		// �������캯���ñ������Զ����ɵļ���

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

	// ��ͷ˫��ѭ������
	template <class T>
	class list 
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next); // ��������
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return iterator(_head->_next); // ��������
		}

		const_iterator end() const
		{
			return iterator(_head);
		}

		void empty_init()
		{
			// ��������ʼ���ڱ�λͷ�ڵ�
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

		// ����������
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end()); //���÷�Χ���캯��
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

			//insert(end(), val); //���ϴ�����ô˷�װ����
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

			return iterator(newnode); //��������
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

			return iterator(next); //��������
		}

	private:
		Node* _head;
	};
}
