#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;//�����������������Ժ�ά���滻�������

typedef struct SeqList
{
	SLDataType* arr;//ָ��̬����ָ��
	int size;//��Ч���ݸ���
	int capacity;//���� - �ռ��С
}SL;

//˳����ʼ��
void SLInit(SL* ps);
//����˳���
void SLDestroy(SL* ps);
//��ӡ˳���
void SLPrint(SL* ps);

//�������
void SLCheckCapacity();

//��ɾ���
//β��/βɾ - O(1)
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//ͷ��/ͷɾ - O(N)
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//������λ�ò���/ɾ��
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//���Һ��޸�
int SLSearch(SL* ps, SLDataType x);
void SLModify(SL* ps, int pos, SLDataType x);
