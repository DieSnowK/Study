#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//�˵�
void menu()
{
	printf("***********************************\n");
	printf("*****   1.add      2.del      *****\n");
	printf("*****   3.search   4.modify   *****\n");
	printf("*****   5.sort     6.print    *****\n");
	printf("*****   0.exit                *****\n");
	printf("***********************************\n");
}

//��ʼ��ͨѶ¼ - ��̬�汾
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//	//pc->data = {0};   //�������У�data���ʻ������飬�����ʼ��������ֱ������
//	                   //���forѭ�������أ�  --  ̫������
//}

//��ʼ��ͨѶ¼ - ��̬�汾
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	//��̬�ڴ���ܿ���ʧ�ܣ�����Ҫ�ж��Ƿ񿪱ٳɹ������Ƿ�Ϊ��ָ��
	if (pc->data == NULL)
	{
		perror("InitContact");
		//�ڴ濪��ʧ�����������
		return;
	}
	
	pc->sz = 0; //��ʼ����Ĭ����0
	pc->capacity = DEFAULT_SZ;
	//memset(pc->data, 0, DEFAULT_SZ * sizeof(PeoInfo));
}

//����ͨѶ¼
DestroyContact(Contact* pc)
{
	//���տռ�
	free(pc->data);
	//�Լ����ְ�data��ΪNULL,��ֹdata��ΪҰָ��
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//�����ļ�

//�����ļ�

//������ϵ�� - ��̬�汾
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷����");
//		return;
//	}
//	//����һ���˵���Ϣ
//	printf("����������:>\n");
//	scanf("%s", pc->data[pc->sz].name);//name�����������飬������������Ԫ�ص�ַ
//	printf("����������:>\n");
//	scanf("%d", &(pc->data[pc->sz].age)); //������һ������������Ҫ&(pc->data[pc->sz].age)
//	printf("�������Ա�:>\n");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("������绰:>\n");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ:>\n");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("���ӳɹ�\n");
//}

//�����Ƿ�����
void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		//�����Ƿ�Ϊ��ָ�� --  �����Ƿ����ݳɹ�
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			//����ʧ�����
			perror("AddContact");
			printf("������ϵ��ʧ��");
			return;
		}
	}
}

//������ϵ�� - ��̬�汾
void AddContact(Contact* pc)
{
	//��������
	CheckCapacity(pc);
	//����һ���˵���Ϣ
	printf("����������:>\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>\n");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>\n");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("���ӳɹ�\n");
}

//��ӡͨѶ¼
void PrintContact(Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
	//��ӡ����
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

//ͨ�����ֲ�����
static int FindByName(Contact* pc, char name[])   //static���κ�������֤�ú���ֻ���ڴ�Դ�ļ��ڷ��ʣ������ʲ���
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{	
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}

	return -1;//�Ҳ���
}

//ɾ����ϵ��
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };

	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>\n");
	scanf("%s", name);

	//1.����Ҫɾ������
	//��/û��
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2.ɾ��
	//�����ﵽɾ����Ч����
	//�ú�����ڴ�ǵ�Ҫɾ�����ڴ棬������Ϊɾ��
	//������/���ʲ��� ������Ϊɾ��
	int i = 0;
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;

	printf("ɾ���ɹ�\n");
}

//������ϵ��
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("��ˡ��Ҫ�����˵�����:>\n");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//��ӡ����
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].tele,
			pc->data[ret].addr);
	}
}

//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>\n");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("����������:>\n");
		scanf("%s", pc->data[ret].name);
		printf("����������:>\n");
		scanf("%d", &(pc->data[ret].age)); 
		printf("�������Ա�:>\n");
		scanf("%s", pc->data[ret].sex);
		printf("������绰:>\n");
		scanf("%s", pc->data[ret].tele);
		printf("�������ַ:>\n");
		scanf("%s", pc->data[ret].addr);
	}
}

