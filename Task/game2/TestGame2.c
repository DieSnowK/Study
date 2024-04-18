#include "game2.h"

void game()
{
	//规定1为雷   0为无雷

	char mine[ROWS][COLS];  //存放布置好雷的信息
	char show[ROWS][COLS];  //存放排查出雷的信息

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印一下棋盘
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	
	////模式选择                   可做待做  
	////思路：将FineMine()中while去掉  套在模式选择处
	// 
	//int choice = 0;
	//printf("请选择要排雷[1]还是标记[2]>");
	//scanf("%d", &choice);
	//switch (choice)
	//{
	//	case 1:
	//		//排雷
	//		break;
	//	case 2:
	//		//标记
	//		break
	//}

	//排雷
	FineMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		//打印菜单
		menu();
		printf("\n请选择:>");

		scanf("%d", &input);

		switch (input)
		{
			case 1:
				game();
				break;

			case 0:
				printf("退出游戏\n");
				break;

			default:
				printf("输入错误，请重新输入\n");
				break;
		}

	} while (input);

	return 0;
}