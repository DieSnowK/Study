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
	assert(newnode);//����Ƿ񿪱ٳɹ�
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
		*pphead = newnode;  //�ö���ָ���ԭ������
	}
	else
	{
		//��β�ڵ�
		SLNode* tail = *pphead;
		while (tail->next != NULL)  //tail->next == NULL ��tailΪβ�ڵ�
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
	*pphead = newnode;  //�ö���ָ��ԭ������

}

void SListPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	//1.ֻ��һ���ڵ�
	//2.����ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//����һ
	//SLNode* tail = *pphead;
	//SLNode* pretail = tail;

	//while (tail->next != NULL)
	//{
	//	pretail = tail;
	//	tail = tail->next;
	//}

	//free(tail);
	//pretail->next = NULL;

	//������
		SLNode* tail = *pphead;
		while (tail->next->next != NULL)  //tail��ʾ�����ڶ���
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
	assert(*pphead);  //��ֹ�����ָ��

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

	if (pos->next == NULL)  //pos�����һ������ɾ��
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

	//ͷ��
	if (*pphead == pos)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		//���м�
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