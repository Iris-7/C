# include "game.h"
void menu()
{
    printf ("****************************\n");
    printf ("*****1.玩游戏 0.退出********\n");
    printf ("****************************\n");
}

void game()
{
    //布置雷的棋盘
    char mine[LINES][COLS] = {0};
    //排查雷的棋盘
    char show[LINES][COLS] = {0};
    //初始化棋盘
    InitBoard(mine, LINES, COLS, '0');
     InitBoard(show, LINES, COLS, '*');
     //打印棋盘
    // DisplayBoard(mine, LINE, COL);
   //  printf("\n");
     DisplayBoard(show, LINE, COL);
     //布雷
     SetMine(mine, LINE, COL);
     //DisplayBoard(mine, LINE, COL);
     //扫雷
     FindMine(mine, show, LINE, COL);

}

void test()
{
    int intput;
    srand((unsigned int)time(NULL)); //时间戳生成随机值，强制转换为无符号整型
    do
    {
     menu();
    printf("请选择：");
    scanf("%d",&intput);
    switch(intput)
    {
    case 1:
     game();
    break;
    case 0:
    printf("退出游戏！\n");
    break;
    default:
    printf("请重新选择!\n");
    break;
    }
    }while(intput);
}



int main()
{
    test();
    return 0;
}
