#include<stdio.h>
using namespace std;

int a[1000];
void choose(int n,int k,int u){//choose
if(k==0){   for(int j=u;j>0;j--)
            printf("%d ",a[j]);
        printf("\n");
            return;
         }
    for(int i=a[k+1]+1;i<=n-k+1;i++){
            a[k]=i;//choose l
        choose(n,k-1,u+1);
    }
}
int main()
{   int n,k;
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
    choose(n,k,0);//choosepermu(5,3);
}
/*4
123
124
134
234*/





