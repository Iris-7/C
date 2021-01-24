# include <stdio.h>
# include "game.h"
/*游戏提示*/
void menu()
{
    printf("****************************************\n");
     printf("********1.玩游戏  0.退出 ***************\n");
     printf("****************************************\n");
}

void game()
{
    char ret ;
    char board[LINE][COL] = {0};
    //初始化棋盘
    InitBoard(board, LINE, COL);
    //打印棋盘
    DisplayBoard(board,LINE,COL);
    //下棋
    while(1)
    {
        //玩家下棋
        PlayerMove(board,LINE,COL);
        DisplayBoard(board,LINE,COL);
        //判断玩家是否赢
         ret = IsWin(board, LINE, COL);
         if (ret != 'C')
         {
             break;
         }
        //电脑下棋
        ComputerMove(board,LINE,COL);
        DisplayBoard(board,LINE,COL);
         //判断玩家是否赢
        ret = IsWin(board, LINE, COL);
         if (ret != 'C')
         {
             break;
         }
    }
         if (ret == '*')
         {
             printf("玩家赢!\n\n");
         }
        if (ret == '#')
         {
             printf("电脑赢!\n\n");
         }
        if (ret == 'Q')
         {
             printf("平局!\n\n");
         }
}

void test()
{
    srand((unsigned int)time(NULL)); //数据类型进行强制转换
     int input;
     /*游戏循环*/
      do
     {
         menu();
         printf("请选择:");
     scanf("%d",&input);
     printf("\n");
        switch(input)
        {
       case 1:
           game();
    break;
       case 0:
    printf("退出游戏!\n");
    break;
       default:
    printf("选择有误\n");
    break;
        }
     }while(input);
}

int main()
{
   test();
    return 0;
}

