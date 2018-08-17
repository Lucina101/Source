#include<stdio.h>
#include<string>
int n,k,a[1000],b[1000];

void permu(int x,int t){
if(x==n-t){
    for(int i=1;i<=t;i++)
    printf("%d",a[i]);
    printf("\n");
    return;
}
for(int j=1;j<=n;j++){
    if(b[j]==0){
    b[j]=1;
    a[n-x+1]=j;
    permu(x-1,t);
    b[j]=0;
    }
}
}
int main(){
scanf("%d",&n);
 permu(n,3);

}


