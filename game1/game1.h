#pragma once

//����ͷ�ļ�
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//���ŵĶ���
#define ROW  3
#define COL  3

//��ӡ�˵�
void menu();

//��ʼ������
void InitBoard(char board[ROW][COL], int row,int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ϸ״̬
char IsWin(char board[ROW][COL], int row, int col);
