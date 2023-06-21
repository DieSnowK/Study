#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��ͷ+����+��ѭ��������ɾ���ʵ��
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

//��ӡ����
void SListPrint(SLNode* phead);

//�½��ڵ�
SLNode* CreSListNode(SLDataType x);

//��ɾ���
void SListPushBack(SLNode** pphead, SLDataType x);
void SListPushFront(SLNode** pphead, SLDataType x);
void SListPopBack(SLNode** pphead);
void SListPopFront(SLNode** pphead);
//����  --  �����������޸�
SLNode* SListFind(SLNode* phead, SLDataType x);

//��posλ��֮�����  --  O(1)
void SListInsertAfter(SLNode* pos, SLDataType x);
//ɾ��posλ��֮���ֵ  --  O(1)
void SListEraseAfter(SLNode* pos);

//��posλ��֮ǰ����  --  ��������  --  ˼��Ϊʲô�� --  O(N)
void SListInsert(SLNode** pphead, SLNode* pos, SLDataType x);
//ɾ��posλ�õ�ֵ  --  ��������  --  ˼��Ϊʲô�� --  O(N)
void SListErase(SLNode** pphead, SLNode* pos);





