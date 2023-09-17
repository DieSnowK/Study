#pragma once
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace CloseHash
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<> // 特化
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			size_t val = 0;
			for (auto& ch : key)
			{
				val *= 131; // BKDR
				val += ch;
			}

			return val;
		}
	};

	template<class K, class V, class Hash = HashFunc<K>> // Hash允许用户自己提供HashFunc
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first)) // 元素已存在则不插入
			{
				return false;
			}

			// 负载因子到了就扩容
			if (_tables.size() == 0 || 10 * _size / _tables.size() >= 7) // 将载荷因子α定为 0.7
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newHT; //构建一个新的HashTable对象，来进行映射逻辑
				newHT._tables.resize(newsize);

				//旧表的数据映射到新表
				for (auto& e : _tables)
				{
					if (e._state == EXIST) // 状态为存在则进行映射
					{
						newHT.Insert(e._kv);
					}
				}

				_tables.swap(newHT._tables);
			}

			// 线性探测
			Hash hash;
			size_t hashi = hash(kv.first) % _tables.size(); // 哈希地址计算
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size(); // 防止已经遍历完vector，若遍历完，则回头
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;

			// 二次探测
			//Hash hash;
			//size_t start = hash(kv.first) % _tables.size();
			//size_t i = 0;
			//size_t hashi = start;

			//while (_tables[hashi]._state == EXIST)
			//{
			//	++i;
			//	hashi = start + i * i; // 二次探测的哈希地址跳跃
			//	hashi %= _tables.size(); // 防止已经遍历完vector，若遍历完，则回头
			//}

			//_tables[hashi]._kv = kv;
			//_tables[hashi]._state = EXIST;
			//++_size;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				++hashi;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE; // 标记删除即可
				--_size;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _size = 0; // 存储有效数据的个数
	};
}

namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* next;

		HashNode(const pair<K,V>& kv)
			: _kv(kv)
			, next(nullptr)
		{}
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	private:
		vector<Node*> _tables;
		size_t _size = 0; // 存储有效数据个数
	};
}