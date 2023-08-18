#pragma once
#include <iostream>
#include <assert.h>

namespace SnowK
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const iterator end() const
		{
			return _finish;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

}
