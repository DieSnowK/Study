#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//�����ʶ������   ϰ���϶��ô�д
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define BOMB 80

//��ӡ�˵�
void menu();

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols);

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//������
void SetMine(char board[ROWS][COLS], int row, int col); //����9x9

//����
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);