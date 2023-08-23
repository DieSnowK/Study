#pragma once
#include <vector>

namespace SnowK
{
	// ���
	// Compare���бȽϵķº���  less -> ���
	// Compare���бȽϵķº���  greater -> С��
	// ������˾����������Ų��������Ǹ���stl��׼����
	template <class T, class Container = std::vector<T>, class Compare = std::less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{
			// ����д����ȥ���ó�Ա������Ĭ�Ϲ���
		}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// ����
			// �����һ����Ҷ�ӽڵ㿪ʼ���µ���
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
			size_t child = parent * 2 + 1; // ����
			while (child < _con.size())
			{
				// ѡ�����Һ����нϴ���Ǹ�
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