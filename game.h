#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define LINE 3
#define COL 3

# include <stdio.h>
#include <stdlib.h>
# include <time.h>
void InitBoard (char board[LINE][COL],int line,int col);
void DisplayBoard (char board[LINE][COL],int line,int col);
void PlayerMove (char board[LINE][COL],int line,int col);
void ComputerMove (char board[LINE][COL],int line,int col);

//����������Ϸ״̬
//���Ӯ ���� ��*��
//����Ӯ ���� ��#��
//ƽ��    ���� ��Q��
//����    ���� ��C��
char IsWin(char board[LINE][COL],int line,int col);
#endif // GAME_H_INCLUDED
