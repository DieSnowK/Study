#define _CRT_SECURE_NO_WARNINGS
#include "game1.h"

//��ӡ�˵�
void menu()
{
	printf("*****************************\n");
	printf("********   1.Play   *********\n");
	printf("********   0.Quit   *********\n");
	printf("*****************************\n");
}

//��ʼ������ 
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//һ��
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//Ϊ���������ֵ
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	printf("\n");

	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//ÿ�����д�ӡ����
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡÿ���������µķָ���
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}

	}
	printf("\n");
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("�������>\n");
	while (1)
	{
		printf("���������������:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= row)  //���������Ƿ�Ϸ�
		{
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������>\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		//�ж�ռ��
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж���Ϸ״̬
//���Ӯ  ��*��
//����Ӯ   '#'
//ƽ��     'Q'
//������Ϸ��C'

int IsFull(char board[ROW][COL], int row, int col)
{
	//�涨 1Ϊ��  0Ϊδ��
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//�ж�Ӯ    ����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')  //Ӯ������
		{
			return board[i][0];
		}
	}

	//�ж�Ӯ    ����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//�ж�Ӯ   б�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//�ж��Ƿ�ƽ��   ƽ��-->   ����������δ����Ӯ��
	//�涨 1Ϊ��  0Ϊδ��

	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//������Ϸ
	return 'C';
}