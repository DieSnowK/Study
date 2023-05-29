#pragma once
//ͷ�ļ���Ӧ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�궨��
#define MAX_NAME 20
#define MAX_SEX 12
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000    //ͨѶ¼����

//��̬�汾�궨��
#define DEFAULT_SZ 3 //һ��ʼͨѶ¼�Ĵ�С
#define INC_SZ 2     //ÿ�ζ�̬�ڴ����ӵĴ�С

//���͵Ķ���
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼ - ��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX]; //�����ӽ������˵���Ϣ
//	int sz; //��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���   ����data�е��±�
//}Contact;

typedef struct Contact
{
	PeoInfo* data; //ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int sz;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������   //��������̬�����ڴ�Ĵ�С
}Contact;

//����������
//�˵�
void menu();
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//������ϵ��
void AddContact(Contact* pc);
//��ӡͨѶ¼
void PrintContact(Contact* pc);
//ɾ����ϵ��
void DelContact(Contact* pc);
//������ϵ��
void SearchContact(Contact* pc);
//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc);
//������Ϣ���ļ�
//����ͨѶ¼
DestroyContact(Contact* pc);
