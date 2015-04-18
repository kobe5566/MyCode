#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#define SIZE 9
using namespace std;




//空白格的資訊: 1.其座標(i,j) 2.排除num[1~9]不可能的數字
typedef struct block
{
    int i;
    int j;
    int num[9];
} Block;

class Sudoku
{
public:
    void  ReadIn();
    int check_repeat_num(int i,int j);
    void save_block(int i,int j);
    void  Solve();
    void SolveIt();
    Sudoku();

    void print(int m[SIZE][SIZE]);
    void GiveQuestion();


private:
    int  map[SIZE][SIZE];
    Block block[144];//空白格
    int block_num;//空白格計數器
    int pointer;//填答案指標
    int sol;//答案數量
    int ans[SIZE][SIZE];

};
