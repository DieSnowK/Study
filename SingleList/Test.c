#include "SList.h"

void Test1()
{
	//�����ṹ��ָ��
	SLNode* n1 = (SLNode*)malloc(sizeof(SLNode));
	assert(n1);
	SLNode* n2 = (SLNode*)malloc(sizeof(SLNode));
	assert(n2);
	SLNode* n3 = (SLNode*)malloc(sizeof(SLNode));
	assert(n3);
	SLNode* n4 = (SLNode*)malloc(sizeof(SLNode));
	assert(n4);

	//���Ӹ����ṹ��
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	SLNode* plist = n1;
	SListPrint(plist);

	//����β��
	SListPushBack(&plist, 5);
	SListPrint(plist);

	//����ͷ��
	SListPushFront(&plist, 0);
	SListPrint(plist);

	//����βɾ
	SListPopBack(&plist);
	SListPrint(plist);
}

void Test2()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	//����ɾ������
	SLNode* ret = SListFind(plist, 3);
	//SListInsertAfter(ret, 10);
	//SListEraseAfter(ret);
	//ret->data = 9;
	//SListInsert(&plist, ret, 10);
	SListPrint(plist);

}

int main()
{
	Test2();
	return 0;
}