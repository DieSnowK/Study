#pragma once
#define _CRT_SECURE_NO_WARNINGS

//头文件包含
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <assert.h>

//宏定义
#define MAX 100

//变量定义/声明
int NUM;  //股票种类个数

//类型定义
typedef struct custstock  //存储用户账号数据
{
	char StockCode[6];  //股票代码
	char StockName[30];  //股票名称
	long StockVal;  //持有的股票数
}custstock;

typedef struct custom  //已注册用户数据
{
	char CustomerName[20];  //用户名
	char PassWord[6];  //密码
}customer;

typedef struct stock  //股票数据
{
	char StockCode[6];  //股票代码
	char StockName[30];  //股票名称
	long Stockvol;  //存储股票的总股数
	long StockAva;  //存储股票可交易的股数
	long StockNum;  //统计一共有多少只股票
	char chChoice;  //股票操作选择
}stock;

//函数声明
void Login(char*, char*, customer*);
void Register(customer*);
void Interface_CustOperation(customer*);
//股票交易平台
void Interface_StockExchange(stock*);
void Display_StockMarket(stock*);
void Menu_Choice(stock*);
void InitCustData(customer*);
void Buy(customer*);
void Sell(customer*);
void View(customer*);
//输入股票信息
void Input_Stock();
void Input_NewStock(stock*);
//删除股票信息
void Delete_Stock();