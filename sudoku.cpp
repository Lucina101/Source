#include<stdio.h>
int sudokuboard[100][100],n,m,ans;
int fuck(int p){
    while(p%3!=1)
        p--;
    return p;
}
int canplace(int x,int y,int z){
        for(int i=1;i<=9;i++){ //check row
            if(sudokuboard[x][i]==z)
                return 0;
                       }
        for(int j=1;j<=9;j++){
            if(sudokuboard[j][y]==z)
                return 0;//check column
        }
        for(int k=fuck(x);k<=fuck(x)+2;k++){
            for(int l=fuck(y);l<=fuck(y)+2;l++){
                if(sudokuboard[k][l]==z)
                return 0;
        }
        }
        return 1;
}
void printsol(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            printf("%d ",sudokuboard[i][j]);
        }
        printf("\n");
    }
}
void solvesudokuboard(int a, int b){
    if(b==10){
    ans++;
     printsol();
     return;
    }

    if(a==10)
        solvesudokuboard(1,b+1);
    if(sudokuboard[a][b]!=0)
        solvesudokuboard(a+1,b);
    if(sudokuboard[a][b]==0){
        for(int i=1;i<=9;i++){
            if(canplace(a,b,i)==1){
                sudokuboard[a][b]=i;
                solvesudokuboard(a+1,b);
                sudokuboard[a][b]=0;
            }
        }
    }
}
int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++)
            scanf("%d",&sudokuboard[i][j]);
    }
    solvesudokuboard(1,1);
}
/*
00000000000000
11111111111111
22222222222222
33333333333333
44444444444444
55555555555555

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/
/*
  (2,2)-->(1,1)
  (3,3)-->(1,1)
  (6,6)-->(4,4)
  (5)-->4
  (4)-->4 ()
  (6)-->4
*/
