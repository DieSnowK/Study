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

namespace Bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			: _data(data)
			, _next(nullptr)
		{}
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

	// 前置声明，否则__Hash_Iterator无法找到HashTable
	// 编译器只会网上找，所以需要前置声明
	template<class K, class T, class Hash, class KeyOfT>
	class HashTable;

	template<class K, class T, class Hash, class KeyOfT>
	struct __Hash_Iterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, Hash, KeyOfT> HT;
		typedef __Hash_Iterator<K, T, Hash, KeyOfT> Self;

		Node* _node;
		HT* _pht; // 用于锁定所在的HashTable

		__Hash_Iterator(Node* node, HT* pht)
			: _node(node)
			, _pht(pht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &(operator*());
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				// 当前桶中迭代
				_node = _node->_next;
			}
			else
			{
				// 找下一个桶
				Hash hash;
				KeyOfT kot;

				size_t hashi = hash(kot(_node->_data)) % _pht->_tables.size();
				++hashi;
				for (; hashi < _pht->_tables.size(); ++hashi)
				{
					if (_pht->_tables[hashi])
					{
						_node = _pht->_tables[hashi];
						break;
					}
				}

				// 说明后面没有有数据的桶了
				if (hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}

			return *this;
		}
	};

	template<class K, class T, class Hash, class KeyOfT> // HashFunc交由上层封装
	class HashTable
	{
		typedef HashNode<T> Node;

		// 模板友元声明要带上模板参数
		template<class K, class T, class Hash, class KeyOfT>
		friend struct __Hash_Iterator;

	public:
		typedef __Hash_Iterator<K, T, Hash, KeyOfT> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this);
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}

			// vector本身不需要手动析构，析构函数会去自动调用所有成员变量的析构函数
		}

		inline size_t __stl_next_prime(size_t n) // STL中素数空间优化
		{
			static const size_t __stl_num_primes = 28;
			static const size_t __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			for (size_t i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return -1;
		}

		pair<iterator, bool> Insert(const T& data)
		{
			Hash hash;
			KeyOfT kot;

			// 去重
			iterator ret = Find(kot(data));
			if (ret != end())
			{
				return make_pair(ret, false);
			}

			// 负载因子到1就扩容
			if (_size == _tables.size())
			{
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				//newTables.resize(newsize, nullptr);
				newTables.resize(__stl_next_prime(_tables.size()), nullptr);

				// 旧表中节点移动映射到新表
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hash(kot(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi]; // 头插逻辑
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			// 头插
			size_t hashi = hash(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_size;

			return make_pair(iterator(newnode, this), true); // this指针即指向此HashTable
		}

		iterator Find(const K& key) // 这里解释了为何map封装中，仍然要第一个参数K，不然没办法
		{
			if (_tables.size() == 0)
			{
				return end();
			}

			Hash hash;
			KeyOfT kot;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this); // this指针即指向此HashTable
				}

				cur = cur->_next;
			}

			return end();
		}

		bool Erase(const K& key)
		{
			if (_tables.size() == 0)
			{
				return true;
			}

			Hash hash;
			KeyOfT kot;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					// 1.头删
					// 2.中间删
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_size;

					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

		size_t Size()
		{
			return _size;
		}

		// 表的长度
		size_t TablesSize()
		{
			return _tables.size();
		}

		// 桶的个数
		size_t BucketNum()
		{
			size_t num = 0;
			for (auto& hashNode : _tables)
			{
				if (hashNode)
				{
					++num;
				}
			}

			return num;
		}

		size_t MaxBucketLength()
		{
			size_t maxLen = 0;

			for (auto& hashNode : _tables)
			{
				size_t len = 0;
				Node* cur = hashNode;

				while (cur)
				{
					++len;
					cur = cur->_next;
				}

				if (len > maxLen)
				{
					maxLen = len;
				}
			}

			return maxLen;
		}
	private:
		vector<Node*> _tables;
		size_t _size = 0; // 存储有效数据个数
	};
}