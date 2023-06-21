#pragma once
#define _CRT_SECURE_NO_WARNINGS

//ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <assert.h>

//�궨��
#define MAX 100

//��������/����
int NUM;  //��Ʊ�������

//���Ͷ���
typedef struct custstock  //�洢�û��˺�����
{
	char StockCode[6];  //��Ʊ����
	char StockName[30];  //��Ʊ����
	long StockVal;  //���еĹ�Ʊ��
}custstock;

typedef struct custom  //��ע���û�����
{
	char CustomerName[20];  //�û���
	char PassWord[6];  //����
}customer;

typedef struct stock  //��Ʊ����
{
	char StockCode[6];  //��Ʊ����
	char StockName[30];  //��Ʊ����
	long Stockvol;  //�洢��Ʊ���ܹ���
	long StockAva;  //�洢��Ʊ�ɽ��׵Ĺ���
	long StockNum;  //ͳ��һ���ж���ֻ��Ʊ
	char chChoice;  //��Ʊ����ѡ��
}stock;

//��������
void Login(char*, char*, customer*);
void Register(customer*);
void Interface_CustOperation(customer*);
//��Ʊ����ƽ̨
void Interface_StockExchange(stock*);
void Display_StockMarket(stock*);
void Menu_Choice(stock*);
void InitCustData(customer*);
void Buy(customer*);
void Sell(customer*);
void View(customer*);
//�����Ʊ��Ϣ
void Input_Stock();
void Input_NewStock(stock*);
//ɾ����Ʊ��Ϣ
void Delete_Stock();