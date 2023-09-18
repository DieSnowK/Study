#pragma once
#include "HashTable.h"

namespace SnowK
{
	template<class K, class Hash = Bucket::HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOtT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename Bucket::HashTable<K, K, Hash, SetKeyOtT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		Bucket::HashTable<K, K, Hash, SetKeyOtT> _ht;
	};
}