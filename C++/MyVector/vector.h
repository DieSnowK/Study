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

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		// 用迭代器进行初始化构造
		// 为何这里使用模板呢？ --> 我怎么知道用户传的是什么类型的迭代器呢 :P
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullter)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++fitst;
			}
		}

		vector(size_t n, const T& val = T()) // T()为匿名对象，会调用T的默认构造函数
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(val);
			}
		}

		// 传统写法
		//vector(const vector<T>& v) 
		//{
		//	_start = new T[v.size()]; // v.capacity()也可以
		//	//memcpy(_start, v._start, sizeof(T) * v.size()); //这个不行，浅拷贝
		//	for (size_t i = 0; i < v.size(); ++i)
		//	{
		//		_start[i] = v._start[i];
		//	}
		//	_finish = _start + v.size();
		//	_end_of_storage = _start + v.size();
		//}

		//vector(const vector<T>& v)
		//	: _start(nullptr)
		//	, _finish(nullptr)
		//	, _end_of_storage(nullptr)
		//{
		//	reserve(v.size());
		//	for (const auto& e : v)
		//	{
		//		push_back(e);
		//	}
		//}

		// 现代写法
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		// 现代写法 -- 依然是极致的剥削 :P
		vector<T>& operator=(vector<T> v) // 传值，调用拷贝构造函数
		{
			swap(v);
			return *this;
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < _finish);

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < _finish);

			return _start[pos];
		}

		void swap(const vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		// 对迭代器失效进行处理
		void reserve(size_t n)  
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start) // 看是否为空，是否需要腾数据
				{
					//memcpy(tmp, _start, sizeof(T) * sz); // 这个不行，浅拷贝
					for (size_t i = 0; i < sz; ++i) //深拷贝
					{
						tmp[i] = _start[i]; //存疑，需要稍后研究
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T()) // T()为匿名对象，会调用T的默认构造函数
		{
			if (n > capacity())
			{
				reserve(n);
			}
			
			if (n > size())
			{
				// 初始化填值
				while (n > size())
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity == 0 ? 4 : capacity() * 2);
			}

			*_finish = val;
			++_finish;

			//insert(end(), val); // 以上代码可用此封装代替
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

		T& front()
		{
			assert(_finish > _start);

			return *_start;
		}

		T& back()
		{
			assert(_finish > _start);

			return *(_finish - 1);
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos <= _finish && pos >= _start);

			if (_finish == _end_of_storage)
			{
				// 扩容完之后，pos会失效，所以要记得更新pos
				size_t len = pos - _start;
				reserve(capacity == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			// 挪动数据
			iterator end = _finish - 1;
			while (pos <= end)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = val;
			++_finish;

			return pos; // 标准库vector返回的是插入的元素的迭代器
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;

			//if (size() < capacity() / 3) //可选
			//{
			//	// 缩容，以时间换空间
			//}

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

}
