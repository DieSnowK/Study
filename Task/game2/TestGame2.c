#include "game2.h"

void game()
{
	//�涨1Ϊ��   0Ϊ����

	char mine[ROWS][COLS];  //��Ų��ú��׵���Ϣ
	char show[ROWS][COLS];  //����Ų���׵���Ϣ

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡһ������
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	
	////ģʽѡ��                   ��������  
	////˼·����FineMine()��whileȥ��  ����ģʽѡ��
	// 
	//int choice = 0;
	//printf("��ѡ��Ҫ����[1]���Ǳ��[2]>");
	//scanf("%d", &choice);
	//switch (choice)
	//{
	//	case 1:
	//		//����
	//		break;
	//	case 2:
	//		//���
	//		break
	//}

	//����
	FineMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		//��ӡ�˵�
		menu();
		printf("\n��ѡ��:>");

		scanf("%d", &input);

		switch (input)
		{
			case 1:
				game();
				break;

			case 0:
				printf("�˳���Ϸ\n");
				break;

			default:
				printf("�����������������\n");
				break;
		}

	} while (input);

	return 0;
}