#include "list.h"
using namespace std;

int main()
{
	SnowK::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	SnowK::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		std::cout << *it << " ";
		it++;
	}
	cout << endl;

	auto it1 = lt.begin();
	while (it1 != lt.end())
	{
		std::cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	
	for (auto e : lt)
	{
		std::cout << e << " ";
	}


	return 0;
}