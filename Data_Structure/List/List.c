#include "List.h"

LTNode* CreListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)  //检查是否开辟成功
	{
		perror("malloc:");
		exit(1);
	}

	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

LTNode* ListInit()
{
	LTNode* phead = CreListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	//不能单纯循环
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = CreListNode(x);
	LTNode* tail = phead->prev;  //找尾
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;  //确定实质的尾
	phead->prev = newnode;

	//ListInsert(phead, x);  //以上代码可以用这个封装替换
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = CreListNode(x);
	LTNode* next = phead->next; 

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;

	//ListInsert(phead->next, x);  //以上代码可以用这个封装替换
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);  //确保不只有一个头节点  --  还有的删

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	free(tail);

	tailPrev->next = phead;
	phead->prev = tailPrev;

	//ListErase(phead->prev);  //以上代码可以用这个封装替换
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* first = phead->next;
	LTNode* next = first->next;

	free(first);

	phead->next = next;
	next->prev = phead;

	//ListErase(phead->next);  //以上代码可以用这个封装替换
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = CreListNode(x);
	LTNode* prev = pos->prev;
	
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;

	free(pos);

	prev->next = next;
	next->prev = prev;
}

int ListSize(LTNode* phead)
{
	assert(phead);
	int size = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

bool isListEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}