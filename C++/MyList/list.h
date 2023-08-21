#pragma once
#include <assert.h>
#include <iostream>

namespace SnowK
{
	template <class T>
	struct list_node // 这里用struct是因为默认访问权限是public
	{
		T _data;
		list_node* prev;
		list_node* next;

		list_node(const T& x)
			: _data(x)
			, prev(nullptr)
			, next(nullptr)
		{}
	};

	// list迭代器为一个类
	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> iterator;
	};


	template <class T>
	class list
	{
		typedef list_node<T> Node;
	public:



	private:
		Node* _head;
	};
}
