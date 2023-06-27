#pragma once
//头文件的应用
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//宏定义
#define MAX_NAME 20
#define MAX_SEX 12
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000    //通讯录容量

//动态版本宏定义
#define DEFAULT_SZ 3 //一开始通讯录的大小
#define INC_SZ 2     //每次动态内存增加的大小

//类型的定义
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录 - 静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX]; //存放添加进来的人的信息
//	int sz; //记录当前通讯录中有效信息的个数   当成data中的下标
//}Contact;

typedef struct Contact
{
	PeoInfo* data; //指向动态申请的空间，用来存放联系人的信息
	int sz;//记录的是当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录的最大容量   //用来管理动态开辟内存的大小
}Contact;

//函数的声明
//菜单
void menu();
//初始化通讯录
void InitContact(Contact* pc);
//增加联系人
void AddContact(Contact* pc);
//打印通讯录
void PrintContact(Contact* pc);
//删除联系人
void DelContact(Contact* pc);
//查找联系人
void SearchContact(Contact* pc);
//修改联系人信息
void ModifyContact(Contact* pc);
//保存信息到文件
//销毁通讯录
DestroyContact(Contact* pc);
