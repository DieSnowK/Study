#pragma once
#include <string>
#include <bitset>
using namespace std;

namespace SnowK
{
	struct HashBKDR
	{
		// BKDR
		size_t operator()(const string& key)
		{
			size_t val = 0;
			for (auto ch : key)
			{
				val *= 131;
				val += ch;
			}

			return val;
		}
	};

	struct HashAP
	{
		// BKDR
		size_t operator()(const string& key)
		{
			size_t hash = 0;
			for (size_t i = 0; i < key.size(); i++)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ key[i] ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ key[i] ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};

	struct HashDJB
	{
		// BKDR
		size_t operator()(const string& key)
		{
			size_t hash = 5381;
			for (auto ch : key)
			{
				hash += (hash << 5) + ch;
			}

			return hash;
		}
	};


	// N表示准备要映射N个值
	template<size_t N, class K = string,
		class Hash1 = HashBKDR, class Hash2 = HashAP, class Hash3 = HashDJB>
	class BloomFilter
	{
	public:
		void Set(const K& key)
		{
			size_t hash1 = Hash1()(key) % (_ratio * N); // 匿名结构体调用仿函数
			_bits->set(hash1);

			size_t hash2 = Hash2()(key) % (_ratio * N);
			_bits->set(hash2);

			size_t hash3 = Hash3()(key) % (_ratio * N);
			_bits->set(hash3);
		}

		bool Test(const K& key)
		{
			size_t hash1 = Hash1()(key) % (_ratio * N);
			if (!_bits->test(hash1))
			{
				return false; // 准确
			}

			size_t hash2 = Hash2()(key) % (_ratio * N);
			if (!_bits->test(hash2))
			{
				return false; // 准确
			}

			size_t hash3 = Hash3()(key) % (_ratio * N);
			if (!_bits->test(hash3))
			{
				return false;  // 准确
			}

			return true; // 可能存在误判
		}

		//void Reset(const K& key); // 不支持删除
	private:
		const static size_t _ratio = 5;
		std::bitset<_ratio* N>* _bits = new std::bitset<_ratio * N>;
	};
}