#include"sudoku.h"
Sudoku::Sudoku()
{
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            map[i][j]=0;
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            ans[i][j]=0;
    block_num=0;
    pointer=0;
    sol=0;

}

void Sudoku::print(int m[][SIZE])
{

    int i,j;
    for(i=0; i<SIZE; i++)
    {

        for(j=0; j<SIZE; j++)
        {

            printf("%4d",m[i][j]);
        }
        printf("\n");
    }


}

void Sudoku::ReadIn()
{
    //讀檔
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
        {
          scanf("%d",&map[i][j]);

        }
    //存空格資訊
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
        {
            if(map[i][j]==0)
                save_block(i,j);
        }
//
    /*if(block_num>64)
    {
        printf("2");
        exit(1);
    }*/


    /*for(int i = 0 ;i<block_num ;i++)
         for(int j= 0;j<9 ;j++)
             if(block[i].num[j]!=0)
             printf("第%d格可能 = %d\n",i,j+1);*/


}
//存空白格的資訊: 1.其座標(i,j) 2.排除num[1~9]不可能的數字
void Sudoku::save_block(int i,int j)
{

    for(int x=0; x<9; x++)
        block[block_num].num[x]=1; //num[1~9]先設定全部都可能 == 1
    //存空白位置
    block[block_num].i=i;
    block[block_num].j=j;

    //-----col------

    int x,y;

    x=i;
    for(y=0; y<SIZE; y++)
        if(map[x][y]!=0&&map[x][y]!=-1)
            block[block_num].num[map[x][y]-1]=0;
    //------raw------
    y=j;
    for(x=0; x<SIZE; x++)
        if(map[x][y]!=0&&map[x][y]!=-1)
            block[block_num].num[map[x][y]-1]=0;
    //-----square-----

    int x1=i-i%3;
    int y1=j-j%3;
    for(x=0; x<3; x++)
        for(y=0; y<3; y++)
            if(map[x+x1][y+y1]!=0&&map[x+x1][y+y1]!=-1)
                block[block_num].num[map[x+x1][y+y1]-1]=0;

    block_num++;

}

//檢查ROW COL SQUARE 是否有重複 1.有return 0; 2.沒有return 1;
int Sudoku::check_repeat_num(int i,int j)
{


    int num[9]= {0};
    //-----col------

    int x,y;

    x=i;
    for(y=0; y<SIZE; y++)
        if(map[x][y]!=0&&map[x][y]!=-1)
            num[map[x][y]-1]++;


    for(int a=0; a<9; a++)
        if(num[a]>1)return 0;

    for(int a=0; a<9; a++)
        num[a]=0;
    //------raw------
    y=j;
    for(x=0; x<SIZE; x++)
        if(map[x][y]!=0&&map[x][y]!=-1)
            num[map[x][y]-1]++;

    for(int a=0; a<9; a++)
        if(num[a]>1)return 0;

    for(int a=0; a<9; a++)
        num[a]=0;

    //-----square-----

    int x1=i-i%3;
    int y1=j-j%3;
    for(x=0; x<3; x++)
        for(y=0; y<3; y++)
            if(map[x+x1][y+y1]!=0&&map[x+x1][y+y1]!=-1)
                num[map[x+x1][y+y1]-1]++;

    for(int a=0; a<9; a++)
        if(num[a]>1)return 0;



    //--都沒重複回傳1-----
    return 1;


}



void Sudoku::SolveIt()
{

    if(pointer==block_num)
    {

        sol++;
        if(sol==1)
        {
            for(int i=0; i<SIZE; i++)
                for(int j=0; j<SIZE; j++)
                    ans[i][j]=map[i][j];

        }
        return ;

    }

    for(int i=0; i<9; i++)
    {

        if(block[pointer].num[i]!=0)
        {
            map[block[pointer].i][block[pointer].j]= i+1;
           // printf("--------------------------------------------\n");
            //print(map);
            if(check_repeat_num(block[pointer].i,block[pointer].j)==1)
            {
                pointer++;//合格進入下一層
                SolveIt();
                pointer--;//恢復
                map[block[pointer].i][block[pointer].j]= 0 ;//恢復一切
            }
            else map[block[pointer].i][block[pointer].j]= 0 ;//檢查不合格 恢復一切
        }

    }
    /*for(int i=8; i>=0; i--)
    {

        if(block[pointer].num[i]!=0)
        {
            map[block[pointer].i][block[pointer].j]= i+1;
            //printf("--------------------------------------------\n");
            //print(map);
            if(check_repeat_num(block[pointer].i,block[pointer].j)==1)
            {
                pointer++;//合格進入下一層
                SolveIt();
                pointer--;//恢復
                map[block[pointer].i][block[pointer].j]= 0 ;//恢復一切
            }
            else map[block[pointer].i][block[pointer].j]= 0 ;//檢查不合格 恢復一切
        }

    }*/



}
void Sudoku::Solve()
{

    SolveIt();
    if(sol==1)
    {
        printf("1\n");

        print(ans);
    }
    if(sol==0)
        printf("2");


}

void Sudoku::GiveQuestion()
{

    srand(time(NULL));
    int n;
    n = rand()%10;
    switch(n)
    {
    case 0 :
        printf("8 0 0 0 0 0 0 0 0\n\
0 0 3 6 0 0 0 0 0\n\
0 7 0 0 9 0 2 0 0\n\
0 5 0 0 0 7 0 0 0\n\
4 0 0 0 4 5 7 0 0\n\
0 0 0 1 0 0 0 3 0\n\
0 0 1 0 0 0 0 6 8\n\
0 0 8 5 0 0 0 1 0\n\
0 9 0 0 0 0 4 0 0\n");
        break;

    case 1 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;
    case 2 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;

    case 3 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;
    case 4 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;

    case 5 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;

    case 6 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;

    case 7 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;
    case 8 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;

    case 9 :
        printf("0 1 0 2 0 0 0 0 0\n\
0 0 3 0 0 0 6 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 3 0 0 0 1 0\n\
4 0 0 0 0 6 0 0 0\n\
0 2 0 0 0 0 0 5 0\n\
8 0 0 0 0 0 3 0 5\n\
0 0 0 0 2 0 8 0 0\n\
0 0 0 7 1 0 0 0 0\n");
        break;
    }

}
