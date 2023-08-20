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

		// ���캯�� - ���߳�ʼ���б�
		string(const char* str = "")  // �����˸�\0
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			
			strcpy(_str, str);
		}

		// �������캯�� - ��ͳд�� - �߳�ʼ���б�
		// ˼����Ϊʲô������ԣ����湹�캯��������?
		//string(const string& s)
		//	:_str(new char[s._capacity + 1])
		//	,_size(s._size)
		//	,_capacity(s._capacity)
		//{
		//	strcpy(_str, s._str);
		//}

		// ���ﴫ���÷��أ�������Ϊ�˿�����ɸ�ֵ����������Ϊ�˿���������ֵ
		//string& operator=(const string& s)
		//{
		//	// Ϊ�˷�ֹ�Լ����Լ���ֵ
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

		// �ִ�д�� -- �ϰ�˼ά
		// �����ʼ���б���Ϊ�˷�ֹ�����󣬿������������ڴ��ͷ�
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str); // ���ù��캯��
			swap(tmp);  // this->swap(tmp);

			// �������������tmp�ͻᱻ������������ʱ����ͷŵ�ԭ���Ŀռ�
		}

		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		//string tmp(s._str); // ���ù��캯��
		//		string tmp(s); // ���ÿ������캯�������߾���
		//		swap(tmp);
		//	}

		//	return *this;
		//}

		// �ִ�д�� -- �ʱ�����˼ά -- ����ѹե
		// s����tmp������
		string& operator=(string s) // �ڸ�ֵ��ʱ�򣬻���ÿ������캯��
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

		const char* c_str() const // Ϊ��ʹconst��Ա���Ե���
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

		// �Ÿ�const������õ����غ���
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				// nȷʵ����_capacity��ȥ���󣬷���������
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
				// ��������
				reserve(n); // ����

				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				// ɾ������
				_str[n] = '\0';
				_size = n;
			}
		}

		void push_back(char ch)
		{
			// ���˾�����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size++] = ch;
			_str[_size] = '\0';

			//insert(_size, ch); // ���ϴ�����ô˷�װ����
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			
			// ����/����������
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;

			//insert(_size, str); // ���ϴ�����ô˷�װ����
		}
		
		// �ٷ�string��append�����ذ汾�����Ҳʵ��һ��
		void append(const string& s)
		{
			append(s._str);
		}

		void append(size_t n, char ch)
		{
			// ����/����������
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

			// ���˾�����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			// Ų������
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			// ��������
			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			// ����/����������
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// Ų������
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}

			strncpy(_str + pos, str, len); // ��ֹstrcpy��\0��������ȥ
			_size += len;

			return *this;
		}

		void erase(size_t pos, size_t len = npos) // ȱʡֵ
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

			// ȡ��һ�£�����strstr
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
		// const static C++�﷨���⴦��
		// ֱ�ӿ��Ե��ɶ����ʼ��
		// static��Ա��Ӧ�������ʼ��
		const static size_t npos = -1; // �޷�������-1����һ���ܴ����
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

	//	// �����ַ����ܳ�������+=��Ч�ʺܵ�
	//	char ch;
	//	ch = in.get();
	//	s.reserve(64); // ��ǰ��һЩ�ռ䣬��ֹ�ռ�Сʱ��Ƶ�����ݣ��Կռ任ʱ��

	//	while (ch != ' ' && ch != '\n')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}

	//	return in;
	//}

	// �Ż��汾
	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();

		const size_t N = 32;
		char buff[N]; //����һ����������һ���Զ�ȡһ���������ݣ����ٶ�ȡ����
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