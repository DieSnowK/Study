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
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K,V>& kv)
			: _kv(kv)
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

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
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

		bool Insert(const pair<K, V>& kv)
		{
			// ȥ��
			if (Find(kv.first))
			{
				return false;
			}

			Hash hash;
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

						size_t hashi = hash(cur->_kv.first) % newTables.size();
						cur->_next = newTables[hashi]; // ͷ���߼�
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			// ͷ��
			size_t hashi = hash(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_size;

			return true;
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			if (_tables.size() == 0)
			{
				return true;
			}

			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (cur->_kv.first == key)
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