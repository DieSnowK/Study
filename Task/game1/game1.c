#define _CRT_SECURE_NO_WARNINGS
#include "game1.h"

//打印菜单
void menu()
{
	printf("*****************************\n");
	printf("********   1.Play   *********\n");
	printf("********   0.Quit   *********\n");
	printf("*****************************\n");
}

//初始化棋盘 
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//一行
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//为数组填入空值
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	printf("\n");

	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//每数据行打印内容
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印每行数据行下的分割线
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

//玩家落子
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家落子>\n");
	while (1)
	{
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= row)  //检验数据是否合法
		{
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}

//电脑落子
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑落子>\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		//判断占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断游戏状态
//玩家赢  ‘*’
//电脑赢   '#'
//平局     'Q'
//继续游戏‘C'

int IsFull(char board[ROW][COL], int row, int col)
{
	//规定 1为满  0为未满
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

char IsWin(char board[ROW][COL], int row, int col) //这里采取暴力判断，其他方法读者们可以评论区讨论
{
	int i = 0;

	//判断赢    三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')  //赢得依据
		{
			return board[i][0];
		}
	}

	//判断赢    三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//判断赢   斜对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断是否平局   平局-->   棋盘满了仍未出现赢家
	//规定 1为满  0为未满

	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//继续游戏
	return 'C';
}