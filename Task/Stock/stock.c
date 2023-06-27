#include "stock.h"

//�����Ʊ��Ϣ
void Input_Stock()
{
	FILE* fpData;
	int nNUM;  
	stock straSto[MAX];
	printf("\n\t\t�����Ʊ������:");
	scanf("%d", &NUM);

	if ((fpData = fopen("Stock_File.dat", "wb")) == NULL)
	{
		printf("FILE ERROR\n");
		exit(0);
	}

	fwrite(&NUM, sizeof(NUM), 1, fpData);

	for (nNUM = 0; nNUM < NUM; nNUM++)
	{
		Input_NewStock(&straSto[nNUM]);  //�����Ʊ����
		fwrite(&straSto[nNUM], sizeof(straSto[nNUM]), 1, fpData);
	}

	fclose(fpData);
	fpData = NULL;
}

//�����Ʊ����
void Input_NewStock(stock* a)
{
	system("cls");
	getchar();

	printf("\n\t\t�������Ʊ����(�ַ�����<=6:)");
	gets(a->StockCode);

	printf("\n\t\t�������Ʊ����:");
	gets(a->StockName);

	printf("\n\t\t�������ܹ���:");
	scanf("%ld", &a->Stockvol);

	a->StockAva = a->Stockvol;

	a->StockNum++;
}

//ɾ����Ʊ��Ϣ
void Delete_Stock()
{
	system("cls");
	char Code[6];
	int nNum;  //�����±����
	stock straSto[MAX];
	FILE* fpData;

	//�����Ƿ��й�Ʊ����
	if ((fpData = fopen("Stock_File.dat", "rb+")) == NULL)
	{
		printf("�޹�Ʊ����\n");
		exit(0);
	}

	fread(&NUM, sizeof(NUM), 1, fpData);
	//printf("%d", NUM);
	
	//�����Ƿ�ʣ��Ʊ����
	if (!NUM)
	{
		printf("�޹�Ʊ����\n");
	}
	else  //���й�Ʊ���ݴ��ڣ���ִ��ɾ������
	{
		getchar();
		//ȡ�������ļ��е����ݣ���������
		for (nNum = 0; nNum < NUM; nNum++)
		{
			fread(&straSto[nNum], sizeof(straSto[nNum]), 1, fpData);
		}

		//��ʾ��Ʊ��Ϣ
		printf("\n\n\n\t*************************��Ʊ��Ϣ*************************\n\n\n");
		printf("\t\t��Ʊ����     ��Ʊ����   �ܹ���   �ɽ��׵Ĺ���\n\n");
		for (nNum = 0; nNum < NUM; nNum++)
		{
			Display_StockMarket(&straSto[nNum]);  
		}
		
		printf("������Ҫɾ���Ĺ�Ʊ����:>");
		gets(Code);

		//�ȶ�Code,���Ƿ����ҵ�
		for (nNum = 0; nNum < NUM; nNum++)
		{
			//�ҵ��ˣ�ִ��ɾ��
			if (strcmp(Code, straSto[nNum].StockCode) == 0)  //Code == straSto[nNum].StockCode
			{
				//Ų������
				for (int begin = nNum; begin < NUM; begin++)
				{
					straSto[begin] = straSto[begin + 1];
				}
				NUM--;

				//��ʾɾ�����Ʊ��Ϣ
				//system("cls");
				int Coded = 0;
				sscanf(Code, "%d", &Coded);
				printf("\nɾ����Ʊ����Ϊ[%d]�Ĺ�Ʊ��:>", Coded);
				printf("\n\n\n\t*************************��Ʊ��Ϣ*************************\n\n\n");
				printf("\t\t��Ʊ����     ��Ʊ����   �ܹ���   �ɽ��׵Ĺ���\n\n");
				for (int i = 0; i < NUM; i++)
				{
					Display_StockMarket(&straSto[i]);
				}

				break;
			}
		}//end of for

		//û�ҵ������
		if (nNum == NUM)
		{
			printf("�ù�Ʊ�����Ӧ�Ĺ�Ʊ������\n");
		}

		//����д������
		rewind(fpData);  //��fpData�ص���ʼλ��
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

//��Ʊ����ƽ̨������
void Interface_StockExchange(stock* a)  //��Ʊ����ƽ̨
{
	system("cls");

	printf("\n\n\n\t\t***************��ӭ�����Ʊ����ƽ̨***************\n\n");
	printf("\t\t\t��ʾ��Ʊ���         [v]\n");
	printf("\t\t\t���û���¼           [l]\n");
	printf("\t\t\t���û�ע��           [r]\n");
	printf("\t\t\t�˳�����ϵͳ         [q]\n");
	printf("\n\n\t\t\t��ѡ��:");
	scanf(" %c", &a->chChoice);  //˼������Ϊʲô��Ҫ��ʽ��һ���ո������

	if (a->chChoice != 'q'
		&& a->chChoice != 'v'
		&& a->chChoice != 'l'
		&& a->chChoice != 'r')
	{
		system("cls");
		Interface_StockExchange(a);  //��Ʊ����ƽ̨
	}
	else
	{
		Menu_Choice(a);  //ִ�����ѡ��
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
	case 'v':  //��ʾ��Ʊ���
		system("cls");
		printf("\n\n\n\t*************************��Ʊ��Ϣ*************************\n\n\n");
		printf("\t\t��Ʊ����     ��Ʊ����   �ܹ���   �ɽ��׵Ĺ���\n\n");

		if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //�򿪹�Ʊ��
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
			Display_StockMarket(&straCust[nNum]);  //��ʾ��Ʊ��Ϣ
		}

		fflush(stdin);
	/*	getchar();  
		getchar();  */
		system("pause");

		Interface_StockExchange(&strTemp);  //���ع�Ʊ����ƽ̨

	case 'l':
		system("cls");
		printf("\n\n\n\t\t***************�û���¼***************\n\n");
		printf("\t\t\t�û���:");
		scanf("%s", CustomerName);
		printf("\n\t\t\t����:");
		scanf("%s", PassWord);

		getchar();

		Login(CustomerName, PassWord, &strCust);  //�û���¼
		Interface_StockExchange(&strTemp);  //���ع�Ʊ����ƽ̨

	case'r':  //���û�ע��
		system("cls");
		printf("\n\n\n\t\t***************�û�ע��***************\n\n");
		Register(&strCust);  //���û�ע��

		if ((fpCust = fopen("customer.dat", "ab")) == NULL)
		{
			printf("FILE ERROR!\n");
			exit(0);
		}
		fwrite(&strCust, sizeof(strCust), 1, fpCust);
		fclose(fpCust);
		fpCust = NULL;
		InitCustData(&strCust);  //��ʼ����ע���û���
		Interface_StockExchange(&strTemp);  //���ع�Ʊ����ϵͳ

	case'q':  //�˳�ϵͳ
		system("cls");
		printf("\n\n\n\n\n\t\tллʹ�ù�Ʊ����ƽ̨\n\n");
		printf("\t\t��      ��\n\n");
		getchar();
		getchar();
		exit(0);
	}
}

//��ʾ��Ʊ��Ϣ
void Display_StockMarket(stock* a)  //��ʾ��Ʊ��Ϣ
{
	printf("\n\t\t%-12s%-10s%-10ld%-10ld\n",
		a->StockName, a->StockCode, a->Stockvol, a->StockAva);
}

//�û���¼
void Login(char* name, char* password, customer* a)  //�û���¼
{
	FILE* fp;
	int Flag;

	if ((fp = fopen("customer.dat", "rb")) == NULL)
	{
		printf("Read File error!\n");
		exit(1);
	}

	//�鿴�û����е���Ϣ
	while (!feof(fp))  //feof���� ���ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܽ��������������ļ�β����
	{
		Flag = fread(a, sizeof(customer), 1, fp);
		if (Flag != 1)
		{
			printf("\n\n\t\t���û���δע��!\n");
			printf("\n\n\t\t�����������\n");
			getchar();
			break;
		}

		if (strcmp(name, a->CustomerName) == 0 && strcmp(password, a->PassWord) == 0)
		{
			Interface_CustOperation(a);  //��¼�ɹ������û�����ƽ̨
			break;
		}
	}

	fclose(fp);
	fp = NULL;
}

//�û�����ƽ̨����
void Interface_CustOperation(customer* a)  //�û�����ƽ̨,��ɹ�Ʊ����
{
	char choice;
	stock strTemp;

	do
	{
		system("cls");
		printf("\n\n\t********************��ӭ�����û�����ƽ̨********************\n\n");
		printf("\n\n\t\t\t  [b]-----���Ʊ\n");
		printf("\t\t\t  [s]-----����Ʊ\n");
		printf("\t\t\t  [v]-----��ʾ�û���Ʊ\n");
		printf("\t\t\t  [q]-----�˳�����\n");
		printf("\n\t\t��ѡ��:");
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
				Buy(a);  //���Ʊ
				break;
			case's':
				Sell(a);  //����Ʊ
				break;
			case'v':
				View(a);  //��ʾ�û���Ʊ��Ϣ
				break;
			case'q':
				Interface_StockExchange(&strTemp);  //���ؽ���ƽ̨
			}
		}
	} while (1);
}

//���Ʊ����
void Buy(customer* a)  //���Ʊ
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

	printf("\n\n\n\t*************************��Ʊ��Ϣ*************************\n\n\n");
	printf("\t\t��Ʊ����     ��Ʊ����   �ܹ���   �ɽ��׵Ĺ���\n\n");

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //�򿪹�Ʊ��
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	fread(&NUM, sizeof(NUM), 1, fpData);
	for (nNum = 0; nNum < NUM; nNum++)
	{
		fread(&straShare[nNum], sizeof(straShare[nNum]), 1, fpData);
	}

	if ((fpCust = fopen(a->CustomerName, "rb")) == NULL)  //���û���Ʊ�˻���
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
		Display_StockMarket(&straShare[nNum]);  //��ʾ��Ʊ��Ϣ
	}

	getchar();

	printf("\n\t\t������Ҫ����Ĺ�Ʊ����:");
	gets(szShareCode);
	printf("\n\t\t���������:");
	scanf("%ld", &nVolume);

	getchar();

	nNum = 0;

	while ((strcmp(straShare[nNum].StockCode, szShareCode) == 0) || nNum < NUM)
	{
		if (strcmp(straShare[nNum].StockCode, szShareCode) == 0)
		{
			if (straShare[nNum].StockAva > nVolume)  //���Ϲ�������
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
				printf("\n\n\t\t�ù�Ʊ�ɽ��׷ݶ�㣬������ɱ��ν���\n");
				printf("\n\t\t\t�˳����ν���\n");
				getchar();
				break;
			}//end of if(straShare[nNum].StockAva>nVolume)  //���Ϲ�������
		}
		else
		{
			nNum++;
			if (nNum == NUM)
			{
				printf("\n\n\t\t����Ĺ�Ʊ��������.....\n");
				printf("\n\t\t\t�˳����ν���\n");
				getchar();
				break;
			}
		}//end of if(strcmp(straShare[nNum].StockCode,szShareCode) == 0)
	}
}

//����Ʊ����
void Sell(customer* a)  //����Ʊ
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

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //�򿪹�Ʊ��
	{
		printf("FILE ERROR!\n");
		exit(0);
	}

	fread(&NUM, sizeof(NUM), 1, fpData);
	for (nNum = 0; nNum < NUM; nNum++)
	{
		fread(&straShare[nNum], sizeof(straShare[nNum]), 1, fpData);
	}

	if ((fpCust = fopen(a->CustomerName, "rb")) == NULL)  //���û���Ʊ�˻���
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

	printf("\n\n\n\t*************************�û���Ʊ��Ϣ*************************\n\n\n");
	printf("\t\t��Ʊ����     ��Ʊ����   �ֹ���\n\n");

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

	printf("\n\t����Ҫ���Ĺ�Ʊ����:");
	scanf("%s", szShareCode);
	printf("\n\t����Ҫ���Ĺ���:");
	scanf("%ld", &nVolume);

	getchar();

	nNum = 0;

	while ((strcmp(straShare[nNum].StockCode, szShareCode) == 0) || nNum < NUM)
	{
		if (strcmp(straShare[nNum].StockCode, szShareCode) == 0)
		{
			if (straCuSto[nNum].StockVal > nVolume)  //��������Ʊ����
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
				printf("\n\n\t\t��ɽ��׹�Ʊ�ݶ�㣬������ɱ��ν���\n");
				printf("\n\t\t\t�˳����ν���\n");
				getchar();
				break;
			}//end of if (straCuSto[nNum].StockVal > nVolume)  //��������Ʊ����
		}
		else
		{
			nNum++;
			if (nNum == NUM)
			{
				printf("\n\n\t\t����Ĺ�Ʊ��������.....\n");
				printf("\n\t\t\t�˳����ν���\n");
				getchar();
				break;
			}
		}//end of if (strcmp(straShare[nNum].StockCode, szShareCode) == 0)
	}
}

//��ʾ�û���Ʊ��Ϣ
void View(customer* a)  //��ʾ�û���Ʊ
{
	FILE* fpCust;
	FILE* fpData;
	custstock straCuSto[MAX];
	int nNum;
	int flag = 1;
	system("cls");

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //�򿪹�Ʊ��
	{
		printf("FILE ERROR!\n");
		exit(0);
	}
	fread(&NUM, sizeof(NUM), 1, fpData);

	if ((fpCust = fopen(a->CustomerName, "rb")) == NULL)  //���û���Ʊ�˻���
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

	printf("\n\n\n\t*************************�û���Ʊ��Ϣ*************************\n\n\n");
	printf("\t\t��Ʊ����     ��Ʊ����   �ֹ���\n\n");

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
		printf("\n\t\t���޿���ʾ�Ĺ�Ʊ��Ϣ");
	}

	fflush(stdin);
	getchar();
	getchar();

}

//���û�ע��
void Register(customer* a)
{
	system("cls");
	getchar();

	printf("\n\n\t********************�û�ע��********************\n\n");
	printf("\n\t\t\t�����û���:");
	scanf("%s", a->CustomerName);
	printf("\n\t\t\t��������:");
	scanf("%s", a->PassWord);

	system("cls");

	printf("\n\n���ѳɹ�ע��\n");
	fflush(stdin);
	getchar();
}

void InitCustData(customer* a)  //��ʼ����ע���û���
{
	int nNum;
	FILE* fpCust;
	FILE* fpData;
	custstock straCuSto[MAX];

	if ((fpData = fopen("Stock_File.dat", "rb")) == NULL)  //�򿪹�Ʊ��
	{
		printf("FILE ERROR!\n");
		exit(0);
	}
	fread(&NUM, sizeof(NUM), 1, fpData);

	if ((fpCust = fopen(a->CustomerName, "wb")) == NULL)  //���û���Ʊ�˻���
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