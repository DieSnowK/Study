#pragma once

//引用头文件
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//符号的定义
#define ROW  3
#define COL  3

//打印菜单
void menu();

//初始化棋盘
void InitBoard(char board[ROW][COL], int row,int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家落子
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑落子
void ComputerMove(char board[ROW][COL], int row, int col);

//判断游戏状态
char IsWin(char board[ROW][COL], int row, int col);
