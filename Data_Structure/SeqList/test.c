#include "SeqList.h"

void TestSL1()
{
	SL sl;
	SLInit(&sl);
	//β�����
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 6);

	SLPrint(&sl);

	//βɾ����
	//SLPopBack(&sl);

	SLPrint(&sl);

	//ͷ�����
	SLPushFront(&sl, 9);
	SLPrint(&sl);

	//ͷɾ����
	SLPopFront(&sl);
	SLPrint(&sl);

	//�������
	SLInsert(&sl, 4, 66);
	SLPrint(&sl);

	//�м�ɾ������
	SLErase(&sl, 4);
	SLPrint(&sl);

	//���Ҳ���
	printf("%d\n", SLSearch(&sl, 4));

	//�޸Ĳ���
	SLModify(&sl, 4, 88);
	SLPrint(&sl);

	SLDestroy(&sl);
}

//һ�㹤����д������������ӿڣ����д�˵�
int main()
{
	TestSL1();
	return 0;
}