#include "BinarySearchTree.h"

int main()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	Key::BSTree<int> t;

	for (auto& e : a)
	{
		t.InsertR(e);
	}
	t.InOrder();

	t.Erase(8);
	t.InOrder();

	std::cout << t.FindR(3) << std::endl;
	std::cout << t.FindR(8) << std::endl;

	for (auto& e : a)
	{
		t.EraseR(e);
		t.InOrder();
	}

	return 0;
}