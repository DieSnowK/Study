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

	template<> // �ػ�
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

	template<class K, class V, class Hash = HashFunc<K>> // Hash�����û��Լ��ṩHashFunc
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first)) // Ԫ���Ѵ����򲻲���
			{
				return false;
			}

			// �������ӵ��˾�����
			if (_tables.size() == 0 || 10 * _size / _tables.size() >= 7) // ���غ����Ӧ���Ϊ 0.7
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newHT; //����һ���µ�HashTable����������ӳ���߼�
				newHT._tables.resize(newsize);

				//�ɱ������ӳ�䵽�±�
				for (auto& e : _tables)
				{
					if (e._state == EXIST) // ״̬Ϊ���������ӳ��
					{
						newHT.Insert(e._kv);
					}
				}

				_tables.swap(newHT._tables);
			}

			// ����̽��
			Hash hash;
			size_t hashi = hash(kv.first) % _tables.size(); // ��ϣ��ַ����
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size(); // ��ֹ�Ѿ�������vector���������꣬���ͷ
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;

			// ����̽��
			//Hash hash;
			//size_t start = hash(kv.first) % _tables.size();
			//size_t i = 0;
			//size_t hashi = start;

			//while (_tables[hashi]._state == EXIST)
			//{
			//	++i;
			//	hashi = start + i * i; // ����̽��Ĺ�ϣ��ַ��Ծ
			//	hashi %= _tables.size(); // ��ֹ�Ѿ�������vector���������꣬���ͷ
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
				ret->_state = DELETE; // ���ɾ������
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
		size_t _size = 0; // �洢��Ч���ݵĸ���
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

	template<> // �ػ�
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

	// ǰ������������__Hash_Iterator�޷��ҵ�HashTable
	// ������ֻ�������ң�������Ҫǰ������
	template<class K, class T, class Hash, class KeyOfT>
	class HashTable;

	template<class K, class T, class Hash, class KeyOfT>
	struct __Hash_Iterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, Hash, KeyOfT> HT;
		typedef __Hash_Iterator<K, T, Hash, KeyOfT> Self;

		Node* _node;
		HT* _pht; // �����������ڵ�HashTable

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
				// ��ǰͰ�е���
				_node = _node->_next;
			}
			else
			{
				// ����һ��Ͱ
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

				// ˵������û�������ݵ�Ͱ��
				if (hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}

			return *this;
		}
	};

	template<class K, class T, class Hash, class KeyOfT> // HashFunc�����ϲ��װ
	class HashTable
	{
		typedef HashNode<T> Node;

		// ģ����Ԫ����Ҫ����ģ�����
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

			// vector������Ҫ�ֶ�����������������ȥ�Զ��������г�Ա��������������
		}

		inline size_t __stl_next_prime(size_t n) // STL�������ռ��Ż�
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

			// ȥ��
			iterator ret = Find(kot(data));
			if (ret != end())
			{
				return make_pair(ret, false);
			}

			// �������ӵ�1������
			if (_size == _tables.size())
			{
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				//newTables.resize(newsize, nullptr);
				newTables.resize(__stl_next_prime(_tables.size()), nullptr);

				// �ɱ��нڵ��ƶ�ӳ�䵽�±�
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hash(kot(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi]; // ͷ���߼�
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			// ͷ��
			size_t hashi = hash(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_size;

			return make_pair(iterator(newnode, this), true); // thisָ�뼴ָ���HashTable
		}

		iterator Find(const K& key) // ���������Ϊ��map��װ�У���ȻҪ��һ������K����Ȼû�취
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
					return iterator(cur, this); // thisָ�뼴ָ���HashTable
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
					// 1.ͷɾ
					// 2.�м�ɾ
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

		// ��ĳ���
		size_t TablesSize()
		{
			return _tables.size();
		}

		// Ͱ�ĸ���
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
		size_t _size = 0; // �洢��Ч���ݸ���
	};
}