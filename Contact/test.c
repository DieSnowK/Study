#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//ͨѶ¼ - ��̬�汾
//1.ͨѶ¼���ܹ����1000���˵���Ϣ
//ÿ���˵���Ϣ��
//����+����+�Ա�+�绰+��ַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.�޸�ָ���˵���Ϣ
//5.����ָ���˵���Ϣ
//6.����ͨѶ¼����Ϣ

//�汾2��
//��̬�����İ汾
//1>ͨѶ¼��ʼ�����ܴ��3���˵���Ϣ
//2>�����ǿռ�Ĵ������ʱ����������2����Ϣ
//3+2+2+2+...

//�汾3
//��ͨѶ¼�˳���ʱ�򣬰���Ϣд���ļ�
//��ͨѶ¼��ʼ����ʱ�򣬼����ļ�����Ϣ��ͨѶ¼��

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

int main()
{
	int input = 0;
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	//��data����һ�������Ŀռ��ڶ�����
	//sz = 0
	//capacity ��ʼ��Ϊ��ǰ���������
	InitContact(&con);

	do
	{
		menu();
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			//������
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case EXIT:
			printf("�˳�����\n");
			//������Ϣ���ļ�
			//����ͨѶ¼
			DestroyContact(&con);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	} while (input);
	return 0;
}