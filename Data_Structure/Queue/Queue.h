#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
//每个队列节点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;
//用于维护每个队列
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool isQueueEmpty(Queue* pq);
int Queuesize(Queue* pq);