#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100],n,ans;
void partition(int x,int k){
if(x==0){
    for(int i=1;i<=k;i++){
    printf("%d ",a[i]);
    }
    ans++;
    printf("\n");
}
return;
}
if(k==0) a[0]=x;
for(int j=min(a[k],x);j>=1;j--){
        a[k+1]=j;
        genpartition(x-j,k+1);
}
}
int main(){
scanf("%d",&n);
partition(n,0);
printf("%d",ans);
}
