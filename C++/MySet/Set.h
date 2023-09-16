#pragma once
#include "RBTree.h"

namespace SnowK
{
	template<class K>
	class set
	{
		struct SetKeyOfT // 仿函数 --> 用于获取data的键值
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> Insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}