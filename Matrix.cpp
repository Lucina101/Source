#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,Lucina=100;
int a[105],n,k,s,t;
inline int add(int a, int b) {
  a+=b;return a>=mod?a-mod:a;
}

inline int sub(int a, int b) {
  a -= b;return a<0?a+mod:a;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a,int b) {
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
struct matrix{
    int m[5][5];
    matrix (){
        memset(m,0,sizeof(m));
    }
    void print(){
        for(int i=0;i<=Lucina;i++)
            for(int j=0;j<=Lucina;j++)
            printf("%d%c",m[i][j],j==Lucina?'\n':' ');
    }
    int* operator [] (int r) {
        return m[r];
    }

    matrix I(){
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
            tmp[i][i]=1;
        return tmp;
    }
    friend matrix operator +( matrix x, matrix y){
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
            for(int j=0;j<=Lucina;j++)
            tmp[i][j]=add(x[i][j],y[i][j]);
        return tmp;
    }
    friend matrix operator *( matrix x, matrix y){
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
        for(int j=0;j<=Lucina;j++){
            for(int r=0;r<=Lucina;r++){
                tmp[i][j]=add(tmp[i][j],mul(x[i][r],y[r][j]));
            }
        }
        return tmp;
    }
    matrix power(matrix x,long long b){
        matrix tmp=I();
        while(b>0){
            if(b&1){
            tmp=(tmp*x);
            }
        x=(x*x);
        b>>=1;
        }
        return tmp;
    }

};
int main(){


}
