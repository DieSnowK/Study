#pragma once

namespace SnowK
{
	// 反向迭代器是个迭代器适配器，它可以将其他迭代器转换为反向迭代器
	// STL中采用对称设计
	template <class Iterator, class Ref, class Ptr>
	struct __reverse_iterator
	{
		Iterator _cur; // 拿一个正向的迭代器当作成员变量，对其进行封装
		typedef __reverse_iterator<Iterator, Ref, Ptr> RIterator;

		__reverse_iterator(Iterator it)
			: _cur(it)
		{}

		RIterator operator++()
		{
			--_cur;
			return *this
		}

		RIterator operator++(int)
		{
			Riterator tmp = *this;
			--_cur;

			return tmp;
		}

		RIterator operator--()
		{
			++_cur;
			return *this;
		}

		RIterator operator--(int)
		{
			RIterator tmp = *this;
			++_cur;

			return tmp;
		}

		Ref operator*()
		{
			return *(--_cur);
		}

		Ptr operator->()
		{
			return &(operator*()); //return _cur.operator->(); 也可
		}

		bool operator!=(const RIterator& it)
		{
			return _cur != it._cur;
		}
	};
}
