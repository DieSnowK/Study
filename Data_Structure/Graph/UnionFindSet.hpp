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
		int root = x;
		while (_ufs[root] >= 0)
		{
			root = _ufs[root];
		}

		// 路径压缩
		while(_ufs[x] >= 0)
		{
			int parent = _ufs[x];
			_ufs[x] = root;
			
			x = parent;
		}

		return root;
	}

	// 合并集合
	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 != root2)
		{
			// 控制数据量小的往大的合并
			if(abs(_ufs[root1] < abs(_ufs[root2])))
			{
				swap(root1, root2);
			}

			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
		}
	}

	// 是否在同一集合
	bool InSameSet(int x1, int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	// 集合数量
	size_t SetSize()
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