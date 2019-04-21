/*
Problem statement: You are given the map n of city
all cities are connected. There are m roads connected cities.
In each cities, you can fill up petrol with money c_i per little.
You are given two integers s and d mean started city and destination.
Find the minimum cost to go from city s to city d;
no grader. may have mistake.
*/
/*
Dynamic programming
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,c[maxn],u,v,w,s,d,ma;
long long dp[maxn][maxn];
vector<pair<int,int>> a[maxn];
bool vis[maxn][maxn];
struct pa{
    long long val;
    int nod;
    int lf;
    bool operator<(const pa z)const{
        return val>z.val;
    }
}p;/*store state of each node with minimum cost*/

int main(){
    scanf("%d%d%d",&n,&m,&ma);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    scanf("%d%d",&s,&d);
    priority_queue<pa> q;
    for(int i=0;i<maxn;i++)
    for(int j=0;j<maxn;j++){
        dp[i][j]=1e18;
    }
    dp[s][0]=0;
    q.push({0,s,0});
    vis[s][0]=true;
    while(!q.empty()){
        while(!q.empty()&&vis[q.top().nod][q.top().lf])
            q.pop();
        p=q.top();
        for(int i=p.lf+1;i<=ma;i++){
            if(!vis[p.nod][i])
            if(dp[p.nod][p.lf]+c[p.nod]*(i-p.lf)<dp[p.nod][i]){
                dp[p.nod][i]=dp[p.nod][p.lf]+c[p.nod]*(i-p.lf);
                q.push({dp[p.nod][i],p.nod,i});
            }
        }
        for(auto i:a[p.nod]){
            if(p.lf>=i.second){
                if(!vis[i.first][p.lf-i.second]){
                    if(dp[p.nod][p.lf]<dp[i.first][p.lf-i.second]){
                        dp[i.first][p.lf-i.second]=dp[p.nod][p.lf];
                        q.push({dp[i.first][p.lf-i.second],i.first,p.lf-i.second});
                    }
                }
            }
        }
        vis[p.nod][p.lf]=true;
        q.pop();
    }
    long long ans=1e18;
    for(int i=0;i<=ma;i++){
        ans=min(ans,dp[d][i]);
    }
    printf("%lld\n",ans);
}
