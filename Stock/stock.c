#include "stock.h"

//输入股票信息
void Input_Stock()
{
	FILE* fpData;
	int nNUM;  
	stock straSto[MAX];
	printf("\n\t\t输入股票种类数:");
	scanf("%d", &NUM);

	if ((fpData = fopen("Stock_File.dat", "wb")) == NULL)
	{
		printf("FILE ERROR\n");
		exit(0);
	}

	fwrite(&NUM, sizeof(NUM), 1, fpData);

	for (nNUM = 0; nNUM < NUM; nNUM++)
	{
		Input_NewStock(&straSto[nNUM]);  //输入股票数据
		fwrite(&straSto[nNUM], sizeof(straSto[nNUM]), 1, fpData);
	}

	fclose(fpData);
	fpData = NULL;
}

//输入股票数据
void Input_NewStock(stock* a)
{
	system("cls");
	getchar();

	printf("\n\t\t请输入股票代码(字符个数<=6:)");
	gets(a->StockCode);

	printf("\n\t\t请输入股票名称:");
	gets(a->StockName);

	printf("\n\t\t请输入总股数:");
	scanf("%ld", &a->Stockvol);

	a->StockAva = a->Stockvol;

	a->StockNum++;
}

//删除股票信息
void Delete_Stock()
{
	system("cls");
	char Code[6];
	int nNum;  //控制下标变量
	stock straSto[MAX];
	FILE* fpData;

	//检验是否有股票数据
	if ((fpData = fopen("Stock_File.dat", "rb+")) == NULL)
	{
		printf("无股票数据\n");
		exit(0);
	}

	fread(&NUM, sizeof(NUM), 1, fpData);
	//printf("%d", NUM);
	
	//检验是否还剩股票数据
	if (!NUM)
	{
		printf("无股票数据\n");
	}
	else  //还有股票数据存在，则执行删除代码
	{
		getchar();
		//取出数据文件中的数据，存入数组
		for (nNum = 0; nNum < NUM; nNum++)
		{
			fread(&straSto[nNum], sizeof(straSto[nNum]), 1, fpData);
		}

		//显示股票信息
		printf("\n\n\n\t*************************股票信息*************************\n\n\n");
		printf("\t\t股票名称     股票代码   总股数   可交易的股数\n\n");
		for (nNum = 0; nNum < NUM; nNum++)
		{
			Display_StockMarket(&straSto[nNum]);  
		}
		
		printf("请输入要删除的股票代码:>");
		gets(Code);

		//比对Code,看是否能找到
		for (nNum = 0; nNum < NUM; nNum++)
		{
			//找到了，执行删除
			if (strcmp(Code, straSto[nNum].StockCode) == 0)  //Code == straSto[nNum].StockCode
			{
				//挪动数据
				for (int begin = nNum; begin < NUM; begin++)
				{
					straSto[begin] = straSto[begin + 1];
				}
				NUM--;

				//显示删除后股票信息
				//system("cls");
				int Coded = 0;
				sscanf(Code, "%d", &Coded);
				printf("\n删除股票代码为[%d]的股票后:>", Coded);
				printf("\n\n\n\t*************************股票信息*************************\n\n\n");
				printf("\t\t股票名称     股票代码   总股数   可交易的股数\n\n");
				for (int i = 0; i < NUM; i++)
				{
					Display_StockMarket(&straSto[i]);
				}

				break;
			}
		}//end of for

		//没找到的情况
		if (nNum == NUM)
		{
			printf("该股票代码对应的股票不存在\n");
		}

		//重新写回数据
		rewind(fpData);  //让fpData回到起始位置
		fwrite(&NUM, sizeof(NUM), 1, fpData);
		for (nNum = 0; nNum < NUM; nNum++)
		{
			fwrite(&straSto[nNum], sizeof(straSto[nNum]), 1, fpData);
		}
		fclose(fpData);
		fpData = NULL;
	}//end of if (!NUM)

	getchar();
}

//股票交易平台主界面
void Interface_StockExchange(stock* a)  //股票交易平台
{
	system("cls");

	printf("\n\n\n\t\t***************欢迎进入股票交易平台***************\n\n");
	printf("\t\t\t显示股票情况         [v]\n");
	printf("\t\t\t老用户登录           [l]\n");
	printf("\t\t\t新用户注册           [r]\n");
	printf("\t\t\t退出交易系统         [q]\n");
	printf("\n\n\t\t\t请选择:");
	scanf(" %c", &a->chChoice);  //思考这里为什么需要格式化一个空格出来？

	if (a->chChoice != 'q'
		&& a->chChoice != 'v'
		&& a->chChoice != 'l'
		&& a->chChoice != 'r')
	{
		system("cls");
		Interface_StockExchange(a);  //股票交易平台
	}
	else
	{
		Menu_Choice(a);  //执行相关选择
	}
}

void Menu_Choice(stock* a)
{
	int nNum;
	FILE* fpCust;
	FILE* fpData;
	stock strTemp;
	stock straCust[MAX];
	customer strCust;
	char CustomerName[20];
	char PassWord[6];

	switch (a->chChoice)
	{
	case 'v':  //显示股票情况
		system("cls");
		printf("\n\n\n\t*************************股票信息*************************\n\n\n");
		printf("\t\t股票名称     股票代码   总股数   可交易的股数\n\n");

		if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //打开股票库
		{
			printf("FILE ERROR!\n");
			exit(0);
		}

		fread(&NUM, sizeof(NUM), 1, fpData);
		for (nNum = 0; nNum < NUM; nNum++)
		{
			fread(&straCust[nNum], sizeof(straCust[nNum]), 1, fpData);
		}
		fclose(fpData);
		fpData = NULL;

		for (nNum = 0; nNum < NUM; nNum++)
		{
			Display_StockMarket(&straCust[nNum]);  //显示股票信息
		}

		fflush(stdin);
	/*	getchar();  
		getchar();  */
		system("pause");

		Interface_StockExchange(&strTemp);  //返回股票交易平台

	case 'l':
		system("cls");
		printf("\n\n\n\t\t***************用户登录***************\n\n");
		printf("\t\t\t用户名:");
		scanf("%s", CustomerName);
		printf("\n\t\t\t密码:");
		scanf("%s", PassWord);

		getchar();

		Login(CustomerName, PassWord, &strCust);  //用户登录
		Interface_StockExchange(&strTemp);  //返回股票交易平台

	case'r':  //新用户注册
		system("cls");
		printf("\n\n\n\t\t***************用户注册***************\n\n");
		Register(&strCust);  //新用户注册

		if ((fpCust = fopen("customer.dat", "ab")) == NULL)
		{
			printf("FILE ERROR!\n");
			exit(0);
		}
		fwrite(&strCust, sizeof(strCust), 1, fpCust);
		fclose(fpCust);
		fpCust = NULL;
		InitCustData(&strCust);  //初始化新注册用户库
		Interface_StockExchange(&strTemp);  //返回股票交易系统

	case'q':  //退出系统
		system("cls");
		printf("\n\n\n\n\n\t\t谢谢使用股票交易平台\n\n");
		printf("\t\t再      见\n\n");
		getchar();
		getchar();
		exit(0);
	}
}

//显示股票信息
void Display_StockMarket(stock* a)  //显示股票信息
{
	printf("\n\t\t%-12s%-10s%-10ld%-10ld\n",
		a->StockName, a->StockCode, a->Stockvol, a->StockAva);
}

//用户登录
void Login(char* name, char* password, customer* a)  //用户登录
{
	FILE* fp;
	int Flag;

	if ((fp = fopen("customer.dat", "rb")) == NULL)
	{
		printf("Read File error!\n");
		exit(1);
	}

	//查看用户库中的信息
	while (!feof(fp))  //feof用于 当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束
	{
		Flag = fread(a, sizeof(customer), 1, fp);
		if (Flag != 1)
		{
			printf("\n\n\t\t该用户还未注册!\n");
			printf("\n\n\t\t按任意键返回\n");
			getchar();
			break;
		}

		if (strcmp(name, a->CustomerName) == 0 && strcmp(password, a->PassWord) == 0)
		{
			Interface_CustOperation(a);  //登录成功进入用户操作平台
			break;
		}
	}

	fclose(fp);
	fp = NULL;
}

//用户操作平台界面
void Interface_CustOperation(customer* a)  //用户操作平台,完成股票交易
{
	char choice;
	stock strTemp;

	do
	{
		system("cls");
		printf("\n\n\t********************欢迎进入用户操作平台********************\n\n");
		printf("\n\n\t\t\t  [b]-----买股票\n");
		printf("\t\t\t  [s]-----卖股票\n");
		printf("\t\t\t  [v]-----显示用户股票\n");
		printf("\t\t\t  [q]-----退出交易\n");
		printf("\n\t\t请选择:");
		scanf("%c", &choice);

		if (choice != 'b' && choice != 's' && choice != 'v' && choice != 'q')
		{
			break;
		}
		else
		{
			switch (choice)
			{
			case'b':
				Buy(a);  //买股票
				break;
			case's':
				Sell(a);  //卖股票
				break;
			case'v':
				View(a);  //显示用户股票信息
				break;
			case'q':
				Interface_StockExchange(&strTemp);  //返回交易平台
			}
		}
	} while (1);
}

//买股票操作
void Buy(customer* a)  //买股票
{
	FILE* fpData;
	FILE* fpCust;
	stock straShare[MAX];
	custstock straCuSto[MAX];
	customer straCust[MAX];
	int nNum;
	char szShareCode[6];
	long nVolume;

	system("cls");

	printf("\n\n\n\t*************************股票信息*************************\n\n\n");
	printf("\t\t股票名称     股票代码   总股数   可交易的股数\n\n");

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //打开股票库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	fread(&NUM, sizeof(NUM), 1, fpData);
	for (nNum = 0; nNum < NUM; nNum++)
	{
		fread(&straShare[nNum], sizeof(straShare[nNum]), 1, fpData);
	}

	if ((fpCust = fopen(a->CustomerName, "rb")) == NULL)  //打开用户股票账户库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	for (nNum = 0; nNum < NUM; nNum++)
	{
		fread(&straCuSto[nNum], sizeof(straCuSto[nNum]), 1, fpCust);
	}

	fclose(fpData);
	fpData = NULL;
	fclose(fpCust);
	fpCust = NULL;

	for (nNum = 0; nNum < NUM; nNum++)
	{
		Display_StockMarket(&straShare[nNum]);  //显示股票信息
	}

	getchar();

	printf("\n\t\t请输入要买入的股票代码:");
	gets(szShareCode);
	printf("\n\t\t请输入股数:");
	scanf("%ld", &nVolume);

	getchar();

	nNum = 0;

	while ((strcmp(straShare[nNum].StockCode, szShareCode) == 0) || nNum < NUM)
	{
		if (strcmp(straShare[nNum].StockCode, szShareCode) == 0)
		{
			if (straShare[nNum].StockAva > nVolume)  //符合购买条件
			{
				straCuSto[nNum].StockVal = straCuSto[nNum].StockVal + nVolume;
				strcpy(straCuSto[nNum].StockName, straShare[nNum].StockName);
				strcpy(straCuSto[nNum].StockCode, straShare[nNum].StockCode);
				straShare[nNum].StockAva = straShare[nNum].StockAva - nVolume;

				if ((fpCust = fopen(a->CustomerName, "wb")) == NULL)
				{
					printf("FILE ERROR!\n");
					exit(0);
				}

				for (nNum = 0; nNum < NUM; nNum++)
				{
					fwrite(&straCuSto[nNum], sizeof(straCuSto[nNum]), 1, fpCust);
				}

				if ((fpData = fopen("Stock_File.dat", "wb")) == NULL)
				{
					printf("FILE ERROR!\n");
					exit(0);
				}
				fwrite(&NUM, sizeof(NUM), 1, fpData);

				for (nNum = 0; nNum < NUM; nNum++)
				{
					fwrite(&straShare[nNum], sizeof(straShare[nNum]), 1, fpData);
				}

				fclose(fpData);
				fpData = NULL;
				fclose(fpCust);
				fpCust = NULL;
				break;
			}
			else
			{
				printf("\n\n\t\t该股票可交易份额不足，不能完成本次交易\n");
				printf("\n\t\t\t退出本次交易\n");
				getchar();
				break;
			}//end of if(straShare[nNum].StockAva>nVolume)  //符合购买条件
		}
		else
		{
			nNum++;
			if (nNum == NUM)
			{
				printf("\n\n\t\t输入的股票代码有误.....\n");
				printf("\n\t\t\t退出本次交易\n");
				getchar();
				break;
			}
		}//end of if(strcmp(straShare[nNum].StockCode,szShareCode) == 0)
	}
}

//卖股票操作
void Sell(customer* a)  //卖股票
{
	FILE* fpData;
	FILE* fpCust;
	stock straShare[MAX];
	custstock straCuSto[MAX];
	customer straCust[MAX];
	int nNum;
	char szShareCode[6];
	long nVolume;

	system("cls");

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //打开股票库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	fread(&NUM, sizeof(NUM), 1, fpData);
	for (nNum = 0; nNum < NUM; nNum++)
	{
		fread(&straShare[nNum], sizeof(straShare[nNum]), 1, fpData);
	}

	if ((fpCust = fopen(a->CustomerName, "rb")) == NULL)  //打开用户股票账户库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	for (nNum = 0; nNum < NUM; nNum++)
	{
		fread(&straCuSto[nNum], sizeof(straCuSto[nNum]), 1, fpCust);
	}

	fclose(fpData);
	fpData = NULL;
	fclose(fpCust);
	fpCust = NULL;

	printf("\n\n\n\t*************************用户股票信息*************************\n\n\n");
	printf("\t\t股票名称     股票代码   持股数\n\n");

	for (nNum = 0; nNum < NUM; nNum++)
	{
		if (straCuSto[nNum].StockVal != 0)
		{
			printf("\t\t%s\t\t%s\t%ld\n",
				straCuSto[nNum].StockName,
				straCuSto[nNum].StockCode,
				straCuSto[nNum].StockVal);
		}
	}

	getchar();

	printf("\n\t输入要卖的股票代码:");
	scanf("%s", szShareCode);
	printf("\n\t输入要卖的股数:");
	scanf("%ld", &nVolume);

	getchar();

	nNum = 0;

	while ((strcmp(straShare[nNum].StockCode, szShareCode) == 0) || nNum < NUM)
	{
		if (strcmp(straShare[nNum].StockCode, szShareCode) == 0)
		{
			if (straCuSto[nNum].StockVal > nVolume)  //符合卖股票条件
			{
				straCuSto[nNum].StockVal = straCuSto[nNum].StockVal - nVolume;
				straShare[nNum].StockAva = straShare[nNum].StockAva + nVolume;

				if ((fpCust = fopen(a->CustomerName, "wb")) == NULL)
				{
					printf("FILE ERROR!\n");
					exit(0);
				}

				for (nNum = 0; nNum < NUM; nNum++)
				{
					fwrite(&straCuSto[nNum], sizeof(straCuSto[nNum]), 1, fpCust);
				}

				if ((fpData = fopen("Stock_File.dat", "wb")) == NULL)
				{
					printf("FILE ERROR!\n");
					exit(0);
				}
				fwrite(&NUM, sizeof(NUM), 1, fpData);

				for (nNum = 0; nNum < NUM; nNum++)
				{
					fwrite(&straShare[nNum], sizeof(straShare[nNum]), 1, fpData);
				}

				fclose(fpData);
				fpData = NULL;
				fclose(fpCust);
				fpCust = NULL;
				break;
			}
			else
			{
				printf("\n\n\t\t你可交易股票份额不足，不能完成本次交易\n");
				printf("\n\t\t\t退出本次交易\n");
				getchar();
				break;
			}//end of if (straCuSto[nNum].StockVal > nVolume)  //符合卖股票条件
		}
		else
		{
			nNum++;
			if (nNum == NUM)
			{
				printf("\n\n\t\t输入的股票代码有误.....\n");
				printf("\n\t\t\t退出本次交易\n");
				getchar();
				break;
			}
		}//end of if (strcmp(straShare[nNum].StockCode, szShareCode) == 0)
	}
}

//显示用户股票信息
void View(customer* a)  //显示用户股票
{
	FILE* fpCust;
	FILE* fpData;
	custstock straCuSto[MAX];
	int nNum;
	int flag = 1;
	system("cls");

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //打开股票库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}
	fread(&NUM, sizeof(NUM), 1, fpData);

	if ((fpCust = fopen(a->CustomerName, "rb")) == NULL)  //打开用户股票账户库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	for (nNum = 0; nNum < NUM; nNum++)
	{
		fread(&straCuSto[nNum], sizeof(straCuSto[nNum]), 1, fpCust);
	}

	fclose(fpCust);
	fpCust = NULL;
	fclose(fpData);
	fpData = NULL;

	printf("\n\n\n\t*************************用户股票信息*************************\n\n\n");
	printf("\t\t股票名称     股票代码   持股数\n\n");

	for (nNum = 0; nNum < NUM; nNum++)
	{
		if (straCuSto[nNum].StockVal != 0)
		{
			printf("\t\t%s\t\t%s\t%ld\n",
				straCuSto[nNum].StockName,
				straCuSto[nNum].StockCode,
				straCuSto[nNum].StockVal);

			flag = 0;
		}
	}

	if (flag)
	{
		printf("\n\t\t暂无可显示的股票信息");
	}

	fflush(stdin);
	getchar();
	getchar();

}

//新用户注册
void Register(customer* a)
{
	system("cls");
	getchar();

	printf("\n\n\t********************用户注册********************\n\n");
	printf("\n\t\t\t输入用户名:");
	scanf("%s", a->CustomerName);
	printf("\n\t\t\t输入密码:");
	scanf("%s", a->PassWord);

	system("cls");

	printf("\n\n您已成功注册\n");
	fflush(stdin);
	getchar();
}

void InitCustData(customer* a)  //初始化新注册用户库
{
	int nNum;
	FILE* fpCust;
	FILE* fpData;
	custstock straCuSto[MAX];

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //打开股票库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}
	fread(&NUM, sizeof(NUM), 1, fpData);

	if ((fpCust = fopen(a->CustomerName, "wb")) == NULL)  //打开用户股票账户库
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	for (nNum = 0; nNum < NUM; nNum++)
	{
		strcpy(straCuSto[nNum].StockCode, "");
		strcpy(straCuSto[nNum].StockName, "");
		straCuSto[nNum].StockVal = 0;
		fwrite(&straCuSto[nNum], sizeof(straCuSto[nNum]), 1, fpCust);
	}

	fclose(fpCust);
	fpCust = NULL;
	fclose(fpData);
	fpData = NULL;
}