#include "RBTree.h"

//void Test1()
//{
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 0,5,30,25,20,4,13,30,28,27 };
//	RBTree<int, int> t1;
//	for (auto e : a)
//	{
//		t1.Insert(make_pair(e, e));
//	}
//
//	t1.InOrder();
//	//cout << "IsBalance:" << t1.IsBalance() << endl;
//}

void Test2()
{
	size_t N = 1000;
	srand(time(0));
	RBTree<int, int> t1;
	for (size_t i = 0; i < N; ++i)
	{
		int x = rand();
		cout << "Insert:" << x << ":" << i << endl;
		t1.Insert(make_pair(x, i));
	}
	cout << "IsBalance:" << t1.IsBalance() << endl;
}

int main()
{
	Test2();
	return 0;
}