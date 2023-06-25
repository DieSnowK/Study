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

//在pos位置之前插入x
void ListInsert(LTNode* pos, LTDataType x);
//删除pos位置的节点
void ListErase(LTNode* pos);

//可选接口
//链表大小 -- 但效率不高O(N)
int ListSize(LTNode* phead);
//判断链表是否为空
bool isListEmpty(LTNode* phead);