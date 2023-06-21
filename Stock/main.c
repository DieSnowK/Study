#include "stock.h"

int main()
{
	char chChoice = 0;
	stock strTemp;  //创建了一个stock变量  --  股票数据
	system("cls");
	printf("\n\n\t\t***************股票交易平台***************\n\n");
	printf("\n\n\n\t\t需要更新股票信息吗？(y|Y--Yes  n|N--No  d|D--Delete)");
	scanf("%c", &chChoice);

	//判断是否需要更新股票信息
	if (chChoice == 'y' || chChoice == 'Y')
	{
		Input_Stock();  //输入股票信息
	}
	else if (chChoice == 'D' || chChoice == 'd')
	{

		Delete_Stock();
		
	}

	Interface_StockExchange(&strTemp);  //股票交易平台
	return 0;
}
