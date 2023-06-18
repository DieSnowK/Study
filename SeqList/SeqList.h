#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;//类型重命名，方便以后维护替换别的类型

typedef struct SeqList
{
	SLDataType* arr;//指向动态数组指针
	int size;//有效数据个数
	int capacity;//容量 - 空间大小
}SL;

//顺序表初始化
void SLInit(SL* ps);
//销毁顺序表
void SLDestroy(SL* ps);
//打印顺序表
void SLPrint(SL* ps);

//检测增容
void SLCheckCapacity();

//增删查改
//尾插/尾删 - O(1)
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//头插/头删 - O(N)
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//从任意位置插入/删除
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//查找和修改
int SLSearch(SL* ps, SLDataType x);
void SLModify(SL* ps, int pos, SLDataType x);
