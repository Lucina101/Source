#include<bits/stdc++.h>
using namespace std;
int n,b[200][200],ans,x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&x);
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            b[i][j]+=x;
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        for(int k=i;k<=n;k++){
            for(int l=j;l<=n;l++){
                ans=max(ans,b[k][l]-b[i-1][l]-b[k][j-1]+b[i-1][j-1]);
            }
        }
    }
    printf("%d\n",ans);
}
