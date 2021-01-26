# include "game.h"

//初始化棋盘
void InitBoard(char board[LINES][COLS], int line, int col, char sett)
{
    int i;
    int j;
    for(i=0; i<line; i++)
    {
        for(j=0; j<col; j++)
        {
              board[i][j] = sett;
        }
    }
}

//打印棋盘
void DisplayBoard (char board[LINES][COLS],int line, int col)
{
    int i;
    int j;
//打印棋盘的列号
for(i=0; i<=col; i++)
{
    printf("%d ",i);
}
printf("\n");

    for (i=1; i<=line; i++)
    {
        printf("%d ",i);
        for (j=1; j<=col; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

//布雷
void SetMine(char mine[LINES][COLS], int line, int col)
{
    int count = COUNT;
     while(count)
     {
       int x =rand()%line+1;  //限定随机值的范围是0~line-1 (0~8) ,+1后 范围变成1~9
       int y =rand()%col+1;   //因为mine[LINES][COLS], 但打印出来的知识[LINE][COL]
       if(mine[x][y] == '0')
      {
        mine[x][y]='1';
        count --;
      }
     }
}

int get_mine_count(char mine[LINES][COLS], int x, int y)
{
     return mine[x-1][y-1]+mine[x-1][y]+mine[x-1][x+1] +
                 mine[x][y-1]+mine[x][y+1]+
                 mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1] - 8*'0';  //字符型数据-字符型'0' 得整型数据
}
//扫雷
void FindMine (char mine[LINES][COLS], char show[LINES][COLS], int line, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while(win<line*col-COUNT)    //可以循环排雷的次数，即不是雷的个数
    {
        printf("请输入排查雷的坐标：");
         scanf("%d,%d",&x,&y);
    //判断坐标合法性
    if(x>=1 && x<=line && y>=1 && y<=col)
    {
        //1.踩到雷
        if(mine[x][y] == '1')
        {
            printf("很遗憾，你被炸死了！\n\n");
            DisplayBoard (mine, LINE, COL);
            break;
        }
       //2.没踩到雷，显示坐标九宫格内雷的数量
       else
       {
           int count = get_mine_count(mine, x, y);
           show[x][y] = count+'0';  //整型数据+字符0 得 字符型数据
           DisplayBoard(show, line, col);
           win++;
       }
    }
    else    //坐标不合法
    {
         printf("坐标不合法，请重新输入!\n");
    }
    }
    if (win == line*col - COUNT)
    {
        printf("恭喜你，排雷成功！\n");
    }
}
