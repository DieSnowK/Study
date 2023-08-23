#pragma once
#include <deque>

namespace SnowK
{
	template <class T, class Container = std::deque<T>> //����Ĭ�ϵ�������deque
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top() const
		{
			return _con.back();
		}

		bool empty() const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}
	private:
		//vector<T> _con //stack��vector��Ϊ�ײ�����
		Container _con; 
	};

}