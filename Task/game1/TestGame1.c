#define _CRT_SECURE_NO_WARNINGS  
#include "game1.h"

void game()
{
	//�洢���� - ��ά����
	char board[ROW][COL];
	//��ʼ������ - ��ʼ���ո�
	InitBoard(board, ROW, COL);
	//��ӡ���� - ʵ�ʾ��Ǵ�ӡ��ά���������
	DisplayBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬

	while (1)   //ֻ����ѭ��һֱ��Ϸ ������
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ϸ״̬ - ����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ϸ״̬ - �����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ�� - ���·���\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do    //�Ƚ�����Ϸ���ٽ����ж�
	{	
		//��ӡ�˵�
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);

		//ѡ����Ϸģʽ
		switch (input)
		{
			case 1:
				printf("��Ϸ��ʼ -- Game Start\n");
				game();
				break;

			case 0:
				printf("�˳���Ϸ\n");
				break;

			default:
				printf("ѡ�����������ѡ��\n");
				break;
		}

	} while (input);

	return 0;
}