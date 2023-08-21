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

		// �õ��������г�ʼ������
		// Ϊ������ʹ��ģ���أ� --> ����ô֪���û�������ʲô���͵ĵ������� :P
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

		vector(size_t n, const T& val = T()) // T()Ϊ�������󣬻����T��Ĭ�Ϲ��캯��
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

		// ��ͳд��
		//vector(const vector<T>& v) 
		//{
		//	_start = new T[v.size()]; // v.capacity()Ҳ����
		//	//memcpy(_start, v._start, sizeof(T) * v.size()); //������У�ǳ����
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

		// �ִ�д��
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

		// �ִ�д�� -- ��Ȼ�Ǽ��µİ��� :P
		vector<T>& operator=(vector<T> v) // ��ֵ�����ÿ������캯��
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

		// �Ե�����ʧЧ���д���
		void reserve(size_t n)  
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start) // ���Ƿ�Ϊ�գ��Ƿ���Ҫ������
				{
					//memcpy(tmp, _start, sizeof(T) * sz); // ������У�ǳ����
					for (size_t i = 0; i < sz; ++i) 
					{
						tmp[i] = _start[i]; //���  --  ֵ�ö���˼��
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T()) // T()Ϊ�������󣬻����T��Ĭ�Ϲ��캯��
		{
			if (n > capacity())
			{
				reserve(n);
			}
			
			if (n > size())
			{
				// ��ʼ����ֵ
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

			//insert(end(), val); // ���ϴ�����ô˷�װ����
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
				// ������֮��pos��ʧЧ������Ҫ�ǵø���pos
				size_t len = pos - _start;
				reserve(capacity == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			// Ų������
			iterator end = _finish - 1;
			while (pos <= end)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = val;
			++_finish;

			return pos; // ��׼��vector���ص��ǲ����Ԫ�صĵ�����
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

			//if (size() < capacity() / 3) //��ѡ
			//{
			//	// ���ݣ���ʱ�任�ռ�
			//}

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

}
