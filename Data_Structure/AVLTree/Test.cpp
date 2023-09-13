#include "AVLTree.h"
#include <time.h>
using namespace std;

void Test1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };  // 测试双旋平衡因子调节
	AVLTree<int, int> t;
	for (auto& e : a)
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();
}

void Test2()
{
	size_t N = 10000;
	srand(time(0));
	AVLTree<int, int> t1;
	for (size_t i = 0; i < N; ++i)
	{
		int x = rand();
		/*if (x == 18467)
		{
			int u = 1;
		}*/
		t1.Insert(make_pair(x, i));
		/*bool ret = t1.IsBalance();
		if (ret == false)
		{
			int u = 1;
		}
		else
		{
			cout << "Insert:" << x << " IsBalance:" <<ret<< endl;
		}*/
	}
	cout << "IsBalance:" << t1.IsBalance() << endl;
}

int main()
{
	Test2();

	return 0;
}
