#include<stdio.h>
int sudokuboard[100][100],n,m,ans;
int f(int p){
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
        for(int k=f(x);k<=f(x)+2;k++){
            for(int l=f(y);l<=f(y)+2;l++){
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
