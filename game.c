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
       //��ӡһ������
       // printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
       //�Ż���
       int j;
       for(j = 0; j < col;  j++)
       {
           printf(" %c ",board[i][j]);
           if(j < col - 1)
            printf("|");
   }
   printf("\n");
       //��ӡ�ָ���
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
       printf("�����\n");
       //�ж�����Ϸ���
        while(1)
        {
           printf("������Ҫ�µ����꣺");
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
                printf("�������ѱ�ռ��\n");
                }
        }
        else
        {
            printf("����Ƿ������������룡\n");
        }
        }
}

void ComputerMove (char board[LINE][COL],int line,int col)
{
        int x = 0;
        int y = 0;
        printf("������\n");
        while(1)
        {
            x = rand() % line;   //��rand()���ɵ������%�У��õ�0-2��Χ����ֵ
            y= rand() % col;
            if (board[x][y] == ' ')
             {
                board[x][y] = '#';
                break;
             }
        }
}

//����1����ʾ��������
//����0����ʾ����û��
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
                 return 0;            //û��
             }
         }
     }
     return 1;           //����
}

char IsWin(char board[LINE][COL],int line,int col)
{
    int i = 0;
    //�����У��ж�ÿ�е������ո��Ƿ���ͬ���Ƿ������һ����
    for(i = 0; i< line; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
        //�����У��ж�ÿ�е������ո��Ƿ���ͬ���Ƿ������һ����
    for(i = 0; i< col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
         //l�����Խ���
         if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
            return board[1][1];
         if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] !=' ')
            return board[1][1];
         //�ж��Ƿ�ƽ��
         if (1 ==IsFull (board,LINE,COL))
         {
             return 'Q';
         }
         return 'C';
    }
