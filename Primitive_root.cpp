#include<bits/stdc++.h>
using namespace std;
map<int,int> vals;
const int g=(int) sqrt (mod + .0) + 1;
//solve a^x=b(mod P)
void pp(){
    for (int p = g; p >= 1; --p)
        vals[power(5,mul(p, g))] = p;
    return;
}
int solve(int a, int b) {
    for (int q = 0;q<=g;++q) {
        int cur = mul(power(5, q), b);
        if (vals.count(cur)) {
            int ans = sub(mul(vals[cur],g), q);
            return ans;
        }
    }
    return -1;
}
//primitive root generator
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    //calculate phi(p) if p is not prime
    
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
//end here
// note that when you calculate recurrence over power of some prime
// you need to calculate it modulo(p-1)!
int main(){
    pp();

}
