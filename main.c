# include "game.h"
void menu()
{
    printf ("****************************\n");
    printf ("*****1.����Ϸ 0.�˳�********\n");
    printf ("****************************\n");
}

void game()
{
    //�����׵�����
    char mine[LINES][COLS] = {0};
    //�Ų��׵�����
    char show[LINES][COLS] = {0};
    //��ʼ������
    InitBoard(mine, LINES, COLS, '0');
     InitBoard(show, LINES, COLS, '*');
     //��ӡ����
    // DisplayBoard(mine, LINE, COL);
   //  printf("\n");
     DisplayBoard(show, LINE, COL);
     //����
     SetMine(mine, LINE, COL);
     //DisplayBoard(mine, LINE, COL);
     //ɨ��
     FindMine(mine, show, LINE, COL);

}

void test()
{
    int intput;
    srand((unsigned int)time(NULL)); //ʱ����������ֵ��ǿ��ת��Ϊ�޷�������
    do
    {
     menu();
    printf("��ѡ��");
    scanf("%d",&intput);
    switch(intput)
    {
    case 1:
     game();
    break;
    case 0:
    printf("�˳���Ϸ��\n");
    break;
    default:
    printf("������ѡ��!\n");
    break;
    }
    }while(intput);
}



int main()
{
    test();
    return 0;
}
