# include <stdio.h>
# define LINE       9         //打印出来的棋盘行数
# define COL        9
# define LINES   LINE+2     //棋盘实际行数    (可便于计算边界雷的数量)
# define COLS    COL+2
# define COUNT 10  //布的雷的数量

void InitBoard (char board[LINES][COLS], int line, int col, char sett);
void DisplayBoard (char board[LINES][COLS],int line, int col);
void SetMine (char mine[LINES][COLS], int line, int col);
void FindMine (char mine[LINES][COLS], char show[LINES][COLS], int line, int col);
