#include "SList.h"

void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* CreSListNode(SLDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode);//检查是否开辟成功
	newnode->next = NULL;
	newnode->data = x;

	return newnode;
}

void SListPushBack(SLNode** pphead, SLDataType x)
{
	assert(pphead);

	SLNode* newnode = CreSListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;  //用二级指针的原因所在
	}
	else
	{
		//找尾节点
		SLNode* tail = *pphead;
		while (tail->next != NULL)  //tail->next == NULL 即tail为尾节点
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SListPushFront(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	
	SLNode* newnode = CreSListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;  //用二级指针原因所在

}

void SListPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	//1.只有一个节点
	//2.多个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//方法一
	//SLNode* tail = *pphead;
	//SLNode* pretail = tail;

	//while (tail->next != NULL)
	//{
	//	pretail = tail;
	//	tail = tail->next;
	//}

	//free(tail);
	//pretail->next = NULL;

	//方法二
		SLNode* tail = *pphead;
		while (tail->next->next != NULL)  //tail表示倒数第二个
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);  //防止传入空指针

	SLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLNode* SListFind(SLNode* phead, SLDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	
	return NULL;
}

void SListInsertAfter(SLNode* pos, SLDataType x)
{
	assert(pos);

	SLNode* newnode = CreSListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SLNode* pos)
{
	assert(pos);

	if (pos->next == NULL)  //pos是最后一个，则不删除
	{
		return;
	}

	SLNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

void SListInsert(SLNode** pphead, SLNode* pos, SLDataType x)
{
	assert(pos);
	assert(pphead);

	//头插
	if (*pphead == pos)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		//插中间
		SLNode* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}

		SLNode* newnode = CreSListNode(x);
		newnode->next = pos;
		pre->next = newnode;
	}
}

void SListErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLNode* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}

		pre->next = pos->next;
		free(pos);
		pos = NULL;
	}
}