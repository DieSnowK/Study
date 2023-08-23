#pragma once
#include <deque>

namespace SnowK
{
	template <class T, class Container = std::deque<T>> //库里默认的容器是deque
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
		//vector<T> _con //stack用vector作为底层容器
		Container _con; 
	};

}