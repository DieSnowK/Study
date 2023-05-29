#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//菜单
void menu()
{
	printf("***********************************\n");
	printf("*****   1.add      2.del      *****\n");
	printf("*****   3.search   4.modify   *****\n");
	printf("*****   5.sort     6.print    *****\n");
	printf("*****   0.exit                *****\n");
	printf("***********************************\n");
}

//初始化通讯录 - 静态版本
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//	//pc->data = {0};   //这样不行，data本质还是数组，数组初始化不可以直接这样
//	                   //如果for循环遍历呢？  --  太过繁杂
//}

//初始化通讯录 - 动态版本
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	//动态内存可能开辟失败，所以要判断是否开辟成功，即是否为空指针
	if (pc->data == NULL)
	{
		perror("InitContact");
		//内存开辟失败则结束函数
		return;
	}
	
	pc->sz = 0; //初始化后默认是0
	pc->capacity = DEFAULT_SZ;
	//memset(pc->data, 0, DEFAULT_SZ * sizeof(PeoInfo));
}

//销毁通讯录
DestroyContact(Contact* pc)
{
	//回收空间
	free(pc->data);
	//自己动手把data置为NULL,防止data成为野指针
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//保存文件

//加载文件

//增加联系人 - 静态版本
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满，无法添加");
//		return;
//	}
//	//增加一个人的信息
//	printf("请输入名字:>\n");
//	scanf("%s", pc->data[pc->sz].name);//name本来就是数组，数组名就是首元素地址
//	printf("请输入年龄:>\n");
//	scanf("%d", &(pc->data[pc->sz].age)); //年龄是一个整数，所以要&(pc->data[pc->sz].age)
//	printf("请输入性别:>\n");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入电话:>\n");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址:>\n");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("增加成功\n");
//}

//检验是否增容
void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		//检验是否为空指针 --  检验是否扩容成功
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			//增容失败情况
			perror("AddContact");
			printf("增加联系人失败");
			return;
		}
	}
}

//增加联系人 - 动态版本
void AddContact(Contact* pc)
{
	//考虑增容
	CheckCapacity(pc);
	//增加一个人的信息
	printf("请输入名字:>\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>\n");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>\n");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加成功\n");
}

//打印通讯录
void PrintContact(Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
	//打印数据
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

//通过名字查找人
static int FindByName(Contact* pc, char name[])   //static修饰函数，保证该函数只能在此源文件内访问，外界访问不到
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{	
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}

	return -1;//找不到
}

//删除联系人
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };

	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除人的名字:>\n");
	scanf("%s", name);

	//1.查找要删除的人
	//有/没有
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除
	//怎样达到删除的效果？
	//让后面的内存盖掉要删除的内存，即可视为删除
	//看不见/访问不到 即可视为删除
	int i = 0;
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;

	printf("删除成功\n");
}

//查找联系人
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请恕人要查找人的名字:>\n");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//打印数据
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].tele,
			pc->data[ret].addr);
	}
}

//修改联系人
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>\n");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字:>\n");
		scanf("%s", pc->data[ret].name);
		printf("请输入年龄:>\n");
		scanf("%d", &(pc->data[ret].age)); 
		printf("请输入性别:>\n");
		scanf("%s", pc->data[ret].sex);
		printf("请输入电话:>\n");
		scanf("%s", pc->data[ret].tele);
		printf("请输入地址:>\n");
		scanf("%s", pc->data[ret].addr);
	}
}

