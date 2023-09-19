#pragma once
#include <vector>
#include <iostream>
using namespace std;

namespace SnowK
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 8 + 1);
		}

		void Set(size_t x) // 置1
		{
			size_t i = x / 8; // 在第几个字节
			size_t j = x % 8; // 在第几个bit

			_bits[i] |= (1 << j);
		}

		void Reset(size_t x) // 置0
		{
			size_t i = x / 8;
			size_t j = x % 8;

			_bits[i] &= ~(1 << j); // 先取反，再与等
		}

		bool Test(size_t x) // 检测是否为1
		{
			size_t i = x / 8;
			size_t j = x % 8;

			return _bits[i] & (1 << j);
		}
	private:
		vector<char> _bits;
	};

	template<size_t N>
	class twobitset // 用两个bitset来表示一个数的至多4种状态
	{
	public:
		void Set(size_t x)
		{
			bool inset1 = _bs1.Test(x);
			bool inset2 = _bs2.Test(x);

			// 00
			if (inset1 == false && inset2 == false)
			{
				// --> 01
				_bs1.Set(x);
			}
			else if (inset1 == true && inset2 == false)
			{
				// --> 10
				_bs1.Reset(x);
				_bs2.Set(x);
			}
			else if (inset1 == false && inset2 == true)
			{
				// --> 11
				_bs1.Set(x);
			}
		}

		void print_once_num()
		{
			for (size_t i = 0; i < N; ++i)
			{
				if (_bs1.Test(i) == true && _bs2.Test(i) == false)
				{
					cout << i << endl;
				}
			}
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}
