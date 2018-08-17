#include<stdio.h>
int chessboard[100][100],n,k,l,ans;

void printsol(int chessboard[100][100]){
    for(k=1;k<=n;k++){
        for(l=1;l<=n;l++)
            printf("%d ",chessboard[k][l]);
            printf("\n");
    }
    printf("\n");
}
int attacked(int i,int j){
    for(k=1;k<=n;k++){//check for row and column
       if(chessboard[i][k]==1||chessboard[k][j]==1){
        return 1;
       }
    }
    for(k=1;k<=n;k++){ //check diagonal
        for(l=1;l<=n;l++){
        if(((k+l)==(i+j))||((k-l)==(i-j))){
            if(chessboard[k][l]==1)
                return 1;
        }
        }
    }
    return 0;//no attack
    }

void solveNqueen(int column){
if(column==n+1){
    //printsol(chessboard);
    ans++;
}
for(int i=1;i<=n;i++){
        if(attacked(i,column)==0){
            chessboard[i][column]=1;
            solveNqueen(column+1);
            chessboard[i][column]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    printf("\n");
    solveNqueen(1);
    printf("%d\n",ans);
}


/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
/*(3,5) is attacked diagonally by
(1,3),(2,4),(4,6),.....() from (1,j-i)-->(n-j+i,n)
(1,7),(2,6),(3,5),(4,4),->>(7,1)
*/

