#include "SeqList.h"

void TestSL1()
{
	SL sl;
	SLInit(&sl);
	//尾插测试
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 6);

	SLPrint(&sl);

	//尾删测试
	//SLPopBack(&sl);

	SLPrint(&sl);

	//头插测试
	SLPushFront(&sl, 9);
	SLPrint(&sl);

	//头删测试
	SLPopFront(&sl);
	SLPrint(&sl);

	//插入测试
	SLInsert(&sl, 4, 66);
	SLPrint(&sl);

	//中间删除测试
	SLErase(&sl, 4);
	SLPrint(&sl);

	//查找测试
	printf("%d\n", SLSearch(&sl, 4));

	//修改测试
	SLModify(&sl, 4, 88);
	SLPrint(&sl);

	SLDestroy(&sl);
}

//一般工程先写函数，测试完接口，最后写菜单
int main()
{
	TestSL1();
	return 0;
}