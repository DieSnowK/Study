#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//无头+单向+非循环链表增删查改实现
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

//打印链表
void SListPrint(SLNode* phead);

//新建节点
SLNode* CreSListNode(SLDataType x);

//增删查改
void SListPushBack(SLNode** pphead, SLDataType x);
void SListPushFront(SLNode** pphead, SLDataType x);
void SListPopBack(SLNode** pphead);
void SListPopFront(SLNode** pphead);
//查找  --  附带作用有修改
SLNode* SListFind(SLNode* phead, SLDataType x);

//在pos位置之后插入  --  O(1)
void SListInsertAfter(SLNode* pos, SLDataType x);
//删除pos位置之后的值  --  O(1)
void SListEraseAfter(SLNode* pos);

//在pos位置之前插入  --  这样不好  --  思考为什么？ --  O(N)
void SListInsert(SLNode** pphead, SLNode* pos, SLDataType x);
//删除pos位置的值  --  这样不好  --  思考为什么？ --  O(N)
void SListErase(SLNode** pphead, SLNode* pos);





