#pragma once
#include <vector>
using namespace std;

class UnionFindSet
{
public:
	UnionFindSet(int size)
		: _ufs(size, -1)
	{}

	size_t FindRoot(int x)
	{
		while (_ufs[x] >= 0)
		{
			x = _ufs[x];
		}

		return x;
	}

	// 合并集合
	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 != root2)
		{
			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
		}
	}

	// 集合数量
	size_t SetCount()
	{
		size_t count = 0;
		for (size_t i = 0; i < _ufs.size(); i++)
		{
			if (_ufs[i] < 0)
			{
				count++;
			}
		}

		return count;
	}
private:
	vector<int> _ufs;
};