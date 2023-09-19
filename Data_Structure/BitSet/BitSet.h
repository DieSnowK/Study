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

		void Set(size_t x) // ��1
		{
			size_t i = x / 8; // �ڵڼ����ֽ�
			size_t j = x % 8; // �ڵڼ���bit

			_bits[i] |= (1 << j);
		}

		void Reset(size_t x) // ��0
		{
			size_t i = x / 8;
			size_t j = x % 8;

			_bits[i] &= ~(1 << j); // ��ȡ���������
		}

		bool Test(size_t x) // ����Ƿ�Ϊ1
		{
			size_t i = x / 8;
			size_t j = x % 8;

			return _bits[i] & (1 << j);
		}
	private:
		vector<char> _bits;
	};

	template<size_t N>
	class twobitset // ������bitset����ʾһ����������4��״̬
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
