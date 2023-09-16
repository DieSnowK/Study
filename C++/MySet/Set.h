#pragma once
#include "RBTree.h"

namespace SnowK
{
	template<class K>
	class set
	{
		struct SetKeyOfT // �º��� --> ���ڻ�ȡdata�ļ�ֵ
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