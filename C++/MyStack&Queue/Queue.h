#pragma once
#include <deque>

template <class T, class Container = std::deque<T>> //����Ĭ�ϵ�������deque
class queue
{
public:
	void push(const T& val)
	{
		_con.push_back(val);
	}

	void pop()
	{
		_con.pop_front();
	}

	T& front()
	{
		return _con.front();
	}

	T& back()
	{
		return _con.back();
	}

	const T& front() const
	{
		return _con.front();
	}

	const T& back() const
	{
		return _con.back();
	}

	bool empty()
	{
		return _con.empty();
	}

	bool size()
	{
		return _con.size();
	}
private:
	Container _con;
};