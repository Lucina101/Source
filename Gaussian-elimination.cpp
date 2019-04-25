/*
Gaussian-elimination code
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7, N=100;
int a[N][N],ans[N],n,ma,tmp;
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

int power(int a,long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
		scanf("%d),&a[i][j]);
   for(int i=1;i<=n;i++){
	if(!a[i][i]){
		//if the number in diagonal=0
		//find another row to swap with it
		ma=0;
		for(int j=i+1;j<=n&&!ma;j++)
			if(a[j][i]) ma=j;
			if(!ma) continue;
			swap(a[ma],a[i]);
		}
	for(int j=i+1;j<=n;j++){
		tmp=a[j][i];
		if(!tmp) continue;
		for(int k=i;k<=n+1;k++)
                a[j][k]=sub(mul(a[j][k],a[i][i]),mul(a[i][k],tmp));
		//subtraction with other rows
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++)
            a[i][n+1]=sub(a[i][n+1],mul(ans[j],a[i][j]));
		ans[i]=(mul(a[i][n+1],power(a[i][i],mod-2)));//multiply inverse at the end.
	}	
	//ans[i] is the number of i-th variable.
}
