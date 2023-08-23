#pragma once
#include <vector>

namespace SnowK
{
	// 大堆
	// Compare进行比较的仿函数  less -> 大堆
	// Compare进行比较的仿函数  greater -> 小堆
	// 这里个人觉得这样安排不合理，但是跟着stl标准库走
	template <class T, class Container = std::vector<T>, class Compare = std::less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{
			// 不用写，会去调用成员变量的默认构造
		}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// 建堆
			// 从最后一个非叶子节点开始向下调整
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				adjust_down(i);
			}
		}

		// logN
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		// logN
		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1; // 左孩子
			while (child < _con.size())
			{
				// 选出左右孩子中较大的那个
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//if (_con[child] > _con[parent])
				//if(_con[parent] < _con(child))
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& val)
		{
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			adjust_down(0);
		}

		const T& top() const
		{
			return _con[0];
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
		Container _con;
	};
}