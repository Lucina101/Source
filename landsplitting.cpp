#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,a[30],q[25],c[30],ans=1e9,max1,min1;
void split(int m,int k){
    if(m==1){
            max1=0,min1=1e9;
           c[k+1]=n;
        for(int i=1;i<=k+1;i++){
            max1=max(max1,q[c[i]]-q[c[i-1]]);
            min1=min(min1,q[c[i]]-q[c[i-1]]);
        }
        ans=mini(ans,(max1-min1));
        return ;
    }
for(int i=c[k]+1;i<=n;i++){
    c[k+1]=i;
    split(m-1,k+1);
}
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        q[i]=q[i-1]+a[i];
    }
    split(m,0);
    printf("%d",ans);
}

