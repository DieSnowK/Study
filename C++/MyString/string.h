#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>

namespace SnowK
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		// 构造函数 - 不走初始化列表
		string(const char* str = "")  // 隐藏了个\0
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			
			strcpy(_str, str);
		}

		// 拷贝构造函数 - 传统写法 - 走初始化列表
		// 思考：为什么这里可以，上面构造函数不可以?
		//string(const string& s)
		//	:_str(new char[s._capacity + 1])
		//	,_size(s._size)
		//	,_capacity(s._capacity)
		//{
		//	strcpy(_str, s._str);
		//}

		// 这里传引用返回，并不是为了可以完成赋值操作，而是为了可以连续赋值
		//string& operator=(const string& s)
		//{
		//	// 为了防止自己给自己赋值
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);

		//		delete[] _str;

		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// 现代写法 -- 老板思维
		// 这里初始化列表是为了防止交换后，可以正常进行内存释放
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str); // 调用构造函数
			swap(tmp);  // this->swap(tmp);

			// 出了这个函数，tmp就会被析构，析构的时候会释放掉原来的空间
		}

		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		//string tmp(s._str); // 调用构造函数
		//		string tmp(s); // 调用拷贝构造函数，两者均可
		//		swap(tmp);
		//	}

		//	return *this;
		//}

		// 现代写法 -- 资本主义思维 -- 极致压榨
		// s顶替tmp做打工人
		string& operator=(string s) // 在赋值的时候，会调用拷贝构造函数
		{
			swap(s);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const // 为了使const成员可以调用
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		// 放给const对象调用的重载函数
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				// n确实大于_capacity才去扩大，否则不做处理
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);

				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				// 插入数据
				reserve(n); // 扩容

				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				// 删除数据
				_str[n] = '\0';
				_size = n;
			}
		}

		void push_back(char ch)
		{
			// 满了就扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size++] = ch;
			_str[_size] = '\0';

			//insert(_size, ch); // 以上代码可用此封装代替
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			
			// 满了/不够就扩容
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;

			//insert(_size, str); // 以上代码可用此封装代替
		}
		
		// 官方string中append有重载版本，这边也实现一下
		void append(const string& s)
		{
			append(s._str);
		}

		void append(size_t n, char ch)
		{
			// 满了/不够就扩容
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}

			for (size_t i = 0; i < n; i++)
			{
				push_back(ch);
			}
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			// 满了就扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			// 挪动数据
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			// 插入数据
			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			// 满了/不够就扩容
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// 挪动数据
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}

			strncpy(_str + pos, str, len); // 防止strcpy连\0都拷贝过去
			_size += len;

			return *this;
		}

		void erase(size_t pos, size_t len = npos) // 缺省值
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(sub);
			assert(pos < _size);

			// 取巧一下，调用strstr
			const char* ptr = strstr(_str + pos, sub);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		string substr(size_t pos, size_t len = npos) const
		{
			assert(pos < _size);
			size_t realLen = len;
			if (len == npos || pos + len > _size)
			{
				realLen = _size - pos;
			}

			string sub;
			for (size_t i = 0; i < realLen; i++)
			{
				sub += _str[pos + i];
			}

			return sub;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}

		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		// const static C++语法特殊处理
		// 直接可以当成定义初始化
		// static成员理应在类外初始化
		const static size_t npos = -1; // 无符号数，-1会变成一个很大的数
	};

	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}

		return out;
	}

	//std::istream& operator>>(std::istream& in, string& s)
	//{
	//	s.clear();

	//	// 输入字符串很长，不断+=，效率很低
	//	char ch;
	//	ch = in.get();
	//	s.reserve(64); // 提前开一些空间，防止空间小时，频繁扩容，以空间换时间

	//	while (ch != ' ' && ch != '\n')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}

	//	return in;
	//}

	// 优化版本
	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();

		const size_t N = 32;
		char buff[N]; //设置一个缓冲区，一次性读取一定量的数据，减少读取次数
		size_t i = 0;

		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			ch = in.get();
		}

		buff[i] = '\0';
		s += buff;

		return in;
	}
}