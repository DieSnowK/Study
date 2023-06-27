#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* CreListNode(LTDataType x);
LTNode* ListInit();
void ListDestroy(LTNode* phead);
void ListPrint(LTNode* phead);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);

//��posλ��֮ǰ����x
void ListInsert(LTNode* pos, LTDataType x);
//ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos);

//��ѡ�ӿ�
//�����С -- ��Ч�ʲ���O(N)
int ListSize(LTNode* phead);
//�ж������Ƿ�Ϊ��
bool isListEmpty(LTNode* phead);