#include "Map.h"
#include <string>

void Test1()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

	SnowK::map<string, int> countMap;
	for (auto& str : arr)
	{
		// 1��str����countMap�У�����pair(str, int()),Ȼ���ڶԷ��ش���++
		// 2��str��countMap�У�����value(����)�����ã�����++;
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