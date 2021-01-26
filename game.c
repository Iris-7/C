# include "game.h"

//��ʼ������
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

//��ӡ����
void DisplayBoard (char board[LINES][COLS],int line, int col)
{
    int i;
    int j;
//��ӡ���̵��к�
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

//����
void SetMine(char mine[LINES][COLS], int line, int col)
{
    int count = COUNT;
     while(count)
     {
       int x =rand()%line+1;  //�޶����ֵ�ķ�Χ��0~line-1 (0~8) ,+1�� ��Χ���1~9
       int y =rand()%col+1;   //��Ϊmine[LINES][COLS], ����ӡ������֪ʶ[LINE][COL]
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
                 mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1] - 8*'0';  //�ַ�������-�ַ���'0' ����������
}
//ɨ��
void FindMine (char mine[LINES][COLS], char show[LINES][COLS], int line, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while(win<line*col-COUNT)    //����ѭ�����׵Ĵ������������׵ĸ���
    {
        printf("�������Ų��׵����꣺");
         scanf("%d,%d",&x,&y);
    //�ж�����Ϸ���
    if(x>=1 && x<=line && y>=1 && y<=col)
    {
        //1.�ȵ���
        if(mine[x][y] == '1')
        {
            printf("���ź����㱻ը���ˣ�\n\n");
            DisplayBoard (mine, LINE, COL);
            break;
        }
       //2.û�ȵ��ף���ʾ����Ź������׵�����
       else
       {
           int count = get_mine_count(mine, x, y);
           show[x][y] = count+'0';  //��������+�ַ�0 �� �ַ�������
           DisplayBoard(show, line, col);
           win++;
       }
    }
    else    //���겻�Ϸ�
    {
         printf("���겻�Ϸ�������������!\n");
    }
    }
    if (win == line*col - COUNT)
    {
        printf("��ϲ�㣬���׳ɹ���\n");
    }
}
