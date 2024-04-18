#define _CRT_SECURE_NO_WARNINGS  
#include "game1.h"

void game()
{
	//存储数据 - 二维数组
	char board[ROW][COL];
	//初始化棋盘 - 初始化空格
	InitBoard(board, ROW, COL);
	//打印棋盘 - 实质就是打印二维数组的内容
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接受游戏状态

	while (1)   //只用来循环一直游戏 即下棋
	{
		//玩家落子
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断游戏状态 - 玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//电脑落子
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断游戏状态 - 电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局 - 无事发生\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do    //先进行游戏，再进行判断
	{	
		//打印菜单
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		//选择游戏模式
		switch (input)
		{
			case 1:
				printf("游戏开始 -- Game Start\n");
				game();
				break;

			case 0:
				printf("退出游戏\n");
				break;

			default:
				printf("选择错误，请重新选择\n");
				break;
		}

	} while (input);

	return 0;
}