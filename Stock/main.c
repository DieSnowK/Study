#include "stock.h"

int main()
{
	char chChoice = 0;
	stock strTemp;  //������һ��stock����  --  ��Ʊ����
	system("cls");
	printf("\n\n\t\t***************��Ʊ����ƽ̨***************\n\n");
	printf("\n\n\n\t\t��Ҫ���¹�Ʊ��Ϣ��(y|Y--Yes  n|N--No  d|D--Delete)");
	scanf("%c", &chChoice);

	//�ж��Ƿ���Ҫ���¹�Ʊ��Ϣ
	if (chChoice == 'y' || chChoice == 'Y')
	{
		Input_Stock();  //�����Ʊ��Ϣ
	}
	else if (chChoice == 'D' || chChoice == 'd')
	{

		Delete_Stock();
		
	}

	Interface_StockExchange(&strTemp);  //��Ʊ����ƽ̨
	return 0;
}
