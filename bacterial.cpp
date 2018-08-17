#include<stdio.h>
int board[1002][1002],m,n,t,counttime[1002][1002];

void printsol(){
    printf("\n");
 for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",board[i][j]);
            printf("\n");
    }
    printf("\n");
}

void regen(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
    if(board[i][j]==1)
        counttime[i][j]++;
    }
}
}

void spread(int i,int j){
    if(board[i][j]==1&&counttime[i][j]>=1){
        board[i-1][j-1]=1;
        board[i-1][j]=1;
        board[i-1][j+1]=1;
        board[i][j-1]=1;
        board[i][j+1]=1;
        board[i+1][j-1]=1;
        board[i+1][j]=1;
        board[i+1][j+1]=1;
    }
    else return;
}

int main(){
    scanf("%d%d%d",&m,&n,&t);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&board[i][j]);
            if(board[i][j]==1) counttime[i][j]++;
    }
    }
    for(int i=1;i<=t;i++){
        for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            spread(i,j);
    }
    regen();
    }
    printsol();
}
