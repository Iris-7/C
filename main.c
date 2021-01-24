# include <stdio.h>
# include "game.h"
/*��Ϸ��ʾ*/
void menu()
{
    printf("****************************************\n");
     printf("********1.����Ϸ  0.�˳� ***************\n");
     printf("****************************************\n");
}

void game()
{
    char ret ;
    char board[LINE][COL] = {0};
    //��ʼ������
    InitBoard(board, LINE, COL);
    //��ӡ����
    DisplayBoard(board,LINE,COL);
    //����
    while(1)
    {
        //�������
        PlayerMove(board,LINE,COL);
        DisplayBoard(board,LINE,COL);
        //�ж�����Ƿ�Ӯ
         ret = IsWin(board, LINE, COL);
         if (ret != 'C')
         {
             break;
         }
        //��������
        ComputerMove(board,LINE,COL);
        DisplayBoard(board,LINE,COL);
         //�ж�����Ƿ�Ӯ
        ret = IsWin(board, LINE, COL);
         if (ret != 'C')
         {
             break;
         }
    }
         if (ret == '*')
         {
             printf("���Ӯ!\n\n");
         }
        if (ret == '#')
         {
             printf("����Ӯ!\n\n");
         }
        if (ret == 'Q')
         {
             printf("ƽ��!\n\n");
         }
}

void test()
{
    srand((unsigned int)time(NULL)); //�������ͽ���ǿ��ת��
     int input;
     /*��Ϸѭ��*/
      do
     {
         menu();
         printf("��ѡ��:");
     scanf("%d",&input);
     printf("\n");
        switch(input)
        {
       case 1:
           game();
    break;
       case 0:
    printf("�˳���Ϸ!\n");
    break;
       default:
    printf("ѡ������\n");
    break;
        }
     }while(input);
}

int main()
{
   test();
    return 0;
}

