# include <stdio.h>
# define LINE       9         //��ӡ��������������
# define COL        9
# define LINES   LINE+2     //����ʵ������    (�ɱ��ڼ���߽��׵�����)
# define COLS    COL+2
# define COUNT 10  //�����׵�����

void InitBoard (char board[LINES][COLS], int line, int col, char sett);
void DisplayBoard (char board[LINES][COLS],int line, int col);
void SetMine (char mine[LINES][COLS], int line, int col);
void FindMine (char mine[LINES][COLS], char show[LINES][COLS], int line, int col);
