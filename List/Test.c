#include "List.h"

int main()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushFront(plist, 9);
	ListPrint(plist);
	printf("%d\n", ListSize(plist));


	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListDestroy(plist);

	return 0;
}