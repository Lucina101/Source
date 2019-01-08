#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long n,k,u,v,dp[maxn],l,x[maxn],c[maxn];
pair<long long,long long>b[maxn];
deque<int> a;
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&u,&v);
        b[i]={u,v};
    }
    sort(b+1,b+n+1);
    /*
    deque
    dp[j-1]+x[j]+c[j]
    */
    for(int i=1;i<=n;i++)
        x[i]=b[i].first,c[i]=b[i].second;
    for(int i=1;i<=n;i++){
        while(!a.empty()&&x[a.front()]+k<x[i])
            a.pop_front();
        if(a.empty())
            l=-1e15;
        else
            l=x[a.front()]+c[a.front()]+dp[a.front()-1];
        dp[i]=max(dp[i-1],c[i]+l-x[i]);
        while(!a.empty()&&(x[a.back()]+c[a.back()]+dp[a.back()-1]<=x[i]+c[i]+dp[i-1]))
            a.pop_back();
        a.push_back(i);
    }
    printf("%lld\n",dp[n]);
}
//dp[i-l]+cl+xl-xi;
