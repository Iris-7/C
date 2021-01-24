# include "game.h"
void InitBoard(char board[LINE][COL],int line,int col)
{
  int i,j;
 for(i=0;i<line;i++)
 {
    for(j=0;j<col;j++)
 {
     board[i][j] = ' ';
 }
}
}

void DisplayBoard(char board[LINE][COL],int line,int col)
{
   int i = 0;
   for(i = 0; i<line; i++)
   {
       //打印一行数据
       // printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
       //优化：
       int j;
       for(j = 0; j < col;  j++)
       {
           printf(" %c ",board[i][j]);
           if(j < col - 1)
            printf("|");
   }
   printf("\n");
       //打印分割行
        if(i < line-1)
          {
              for (j =0; j < col; j++)
              {
                  printf("---");
                  if(j<col-1)
                    printf("|");
              }
                 printf("\n");
          }
   }
   printf("\n");
}

void PlayerMove (char board[LINE][COL],int line,int col)
{
       int x = 0;
       int y = 0;
       printf("玩家走\n");
       //判断坐标合法性
        while(1)
        {
           printf("请输入要下的坐标：");
        scanf("%d,%d",&x,&y);
        if (x>= 1 && x<=line && y>=1 && y<=col)
        {
            if (board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }
            else
                {
                printf("该坐标已被占用\n");
                }
        }
        else
        {
            printf("坐标非法，请重新输入！\n");
        }
        }
}

void ComputerMove (char board[LINE][COL],int line,int col)
{
        int x = 0;
        int y = 0;
        printf("电脑走\n");
        while(1)
        {
            x = rand() % line;   //用rand()生成的随机数%行，得到0-2范围的数值
            y= rand() % col;
            if (board[x][y] == ' ')
             {
                board[x][y] = '#';
                break;
             }
        }
}

//返回1：表示棋盘满了
//返回0，表示棋盘没满
int IsFull(char board[LINE][COL], int line, int col)
{
    int i = 0;
     int j = 0;
     for (i=0; i<line; i++)
     {
         for(j=0; j<=col; j++)
         {
             if (board[i][j] == ' ')
             {
                 return 0;            //没满
             }
         }
     }
     return 1;           //满了
}

char IsWin(char board[LINE][COL],int line,int col)
{
    int i = 0;
    //横三行：判断每行的三个空格是否相同，是否可连成一根线
    for(i = 0; i< line; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
        //竖三行：判断每列的三个空格是否相同，是否可连成一根线
    for(i = 0; i< col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
         //l两个对角线
         if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
            return board[1][1];
         if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] !=' ')
            return board[1][1];
         //判断是否平局
         if (1 ==IsFull (board,LINE,COL))
         {
             return 'Q';
         }
         return 'C';
    }
