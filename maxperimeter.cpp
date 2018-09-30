#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
int a[maxn],n,ans=0,b[5];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        if(a[i]+a[i+1]>a[i+2]){
            ans=max(ans,a[i]+a[i+1]+a[i+2]);
            b[0]=a[i],b[1]=a[i+1],b[2]=a[i+2];
            }
    }
    printf("%d\n%d %d %d",ans,b[0],b[1],b[2]);
}

