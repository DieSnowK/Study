#include "game2.h"

void menu()
{
	printf("*************************\n");
	printf("********  1.Play  *******\n");
	printf("********  0.Quit  *******\n");
	printf("*************************\n");
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("\n------ɨ����Ϸ------\n");

	int i = 0;
	int j = 0;
	
	//��ӡ�к�
	for (j = 0; j <= row; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	//9x9����
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);             //��ӡ�к�

		for (j = 1; j <= col; j++)
		{

			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------ɨ����Ϸ------\n\n");
}

//������
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = BOMB;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		//�ж������Ƿ�Ϸ�
		if (board[x][y] == '0')              //x > 0 && x <= row && y > 0 && y <= col ������������ ֻ���ж��Ƿ�Ϸ�  ���ǲ����ж��Ƿ񱻲�������
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//static
//1. ���ξֲ�����
//2. ����ȫ�ֱ���
//3. ���κ���  ---- ʹ���������ֻ���ڱ�Դ�ļ���ʹ�ã�����������Դ�ļ���ʹ��


//ͳ�ƾŹ���������
static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//���㷨�򵥱���      ���д��Ż�########
	//�����ڴ����'0' ��'1'   -��0����Ϊ����0  1
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

//����
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.�����Ų������
	//2.������괦�ǲ�����
	  //(1) ���� - ����
	  //(2) ������ - ͳ������Ź������м����� - �洢�Ų��׵���Ϣ��show���飬��Ϸ����
	int x = 0;
	int y = 0;
	int win = ROW * COL - BOMB;

	while (win)
	{
		
		printf("\n��������Ҫ���׵�����:>");
		//һ�����׹���
		scanf("%d %d", &x, &y);

		//��������Ƿ�Ϸ�
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("\n���ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//�����׵�����£�ͳ��x,y������Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';    //ANSI���    ���ֺ��ַ�  ��48   ��Ӧ��������
				//��ʾ�Ų������Ϣ
				DisplayBoard(show, ROW, COL);
				win--;
			}
		}
		else
		{
			printf("���겻�Ϸ�������������\n");
		}
	}
	
	//ʤ������:D
	if (win == 0)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		
		//�����̻���show��չʾ������  ����#����    ������_����
		int i = 0;
		int j = 0;
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (mine[i][j] == '1')
				{
					show[i][j] = '#';
				}
				else
				{
					show[i][j] = '_';
				}
			}
		}
		DisplayBoard(show, row, col);
	}

}