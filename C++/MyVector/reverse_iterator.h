#pragma once

namespace SnowK
{
	// ����������Ǹ��������������������Խ�����������ת��Ϊ���������
	// STL�в��öԳ����
	template <class Iterator, class Ref, class Ptr>
	struct __reverse_iterator
	{
		Iterator _cur; // ��һ������ĵ�����������Ա������������з�װ
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
			return &(operator*()); //return _cur.operator->(); Ҳ��
		}

		bool operator!=(const RIterator& it)
		{
			return _cur != it._cur;
		}
	};
}
