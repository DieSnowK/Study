#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//定义标识符常量   习惯上都用大写
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define BOMB 80

//打印菜单
void menu();

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col); //布置9x9

//排雷
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);