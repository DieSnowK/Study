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

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("\n------扫雷游戏------\n");

	int i = 0;
	int j = 0;
	
	//打印列号
	for (j = 0; j <= row; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	//9x9棋盘
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);             //打印行号

		for (j = 1; j <= col; j++)
		{

			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------扫雷游戏------\n\n");
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = BOMB;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		//判断数据是否合法
		if (board[x][y] == '0')              //x > 0 && x <= row && y > 0 && y <= col 这种做法不好 只能判断是否合法  但是不能判断是否被布过雷了
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//static
//1. 修饰局部变量
//2. 修饰全局变量
//3. 修饰函数  ---- 使得这个函数只能在本源文件内使用，不能在其他源文件内使用


//统计九宫格内雷数
static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//此算法简单暴力      但有待优化########
	//数组内存放了'0' 和'1'   -‘0’即为数字0  1
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

//排雷
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.输入排查的坐标
	//2.检查坐标处是不是雷
	  //(1) 是雷 - 死亡
	  //(2) 不是雷 - 统计坐标九宫格内有几个雷 - 存储排查雷的信息到show数组，游戏继续
	int x = 0;
	int y = 0;
	int win = ROW * COL - BOMB;

	while (win)
	{
		
		printf("\n请输入想要排雷的坐标:>");
		//一次排雷过程
		scanf("%d %d", &x, &y);

		//检查数据是否合法
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("\n很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷的情况下，统计x,y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';    //ANSI码表    数字和字符  差48   对应查表即可理解
				//显示排查出的信息
				DisplayBoard(show, ROW, COL);
				win--;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	
	//胜利宣言:D
	if (win == 0)
	{
		printf("恭喜你，排雷成功\n");
		
		//将雷盘换成show盘展示的样子  雷用#代替    无雷用_代替
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