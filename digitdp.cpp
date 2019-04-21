/*
No grader just practice.
Detail: given two integer a and b
a<=b we want to find number of integers in [a,b]
such that has digit d occurs exactly k times
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int d,k,dp[30][30][2],ma,u;
long long a,b;
vector<int>s ;

int solve(int pos,int cnt,bool f){
    if(cnt>k){
        return 0;
    }
    if(pos==s.size()){
        if(cnt==k)return 1;
        else return 0;
    }
    if(dp[pos][cnt][f]!=-1){
        return dp[pos][cnt][f];
    }
    ma=f?9:s[pos];
    int res=0;
    for(int i=0;i<=ma;i++){
        u=cnt;
        if(i==d) u++;
        if(f){
            res+=(solve(pos+1,u,f));
        }
        else{
            if(i!=ma)
                res+=(solve(pos+1,u,1));
            else
                res+=(solve(pos+1,u,0));
        }
    }
    return dp[pos][cnt][f]=res;
}

int gg(long long x){
    s.clear();
    while(x){
        s.push_back(x%10);
        x/=10;
    }
    for(int i=0;i<30;i++)
        for(int j=0;j<30;j++)
        dp[i][j][0]=-1,dp[i][j][1]=-1;
    return solve(0,0,0);
}

int main(){
    scanf("%lld%lld",&a,&b);
    scanf("%d%d",&d,&k);
    for(int i=0;i<30;i++)
        for(int j=0;j<30;j++)
        dp[i][j][0]=-1,dp[i][j][1]=-1;
    printf("%d\n",gg(a)-gg(b));

}
