#include "Map.h"
#include <string>

void Test1()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

	SnowK::map<string, int> countMap;
	for (auto& str : arr)
	{
		// 1、str不在countMap中，插入pair(str, int()),然后在对返回次数++
		// 2、str在countMap中，返回value(次数)的引用，次数++;
		countMap[str]++;
	}

	SnowK::map<string, int>::iterator it = countMap.begin();
	while (it != countMap.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

int main()
{
	Test1();
	return 0;
}