
///segment tree to find kth number on path on tree ; sample implementation
struct node{
    int l , r , sum; // left id , right id , real sum
    node(): l(0), r(0), sum(){} 
}f[nax * 2 * Log]; 
 
void build(int x, int l, int r){
    f[x].sum = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    f[x].l = ++cnt; build(f[x].l, l, mid);
    f[x].r = ++cnt; build(f[x].r, mid + 1, r);
}
 
void update(int &x, int l, int r, int k){
    f[++ cnt] = f[x]; ///cnt is global id start with 0
    ++f[cnt].sum ; x = cnt;
    if(l == r) return ;
    int mid = l + r >> 1 ;
    if(k <= mid) update(f[x].l, l, mid, k);
    else update(f[x].r, mid + 1, r , k);
}
 
int kth(int x, int y, int v, int l,int r, int k){
    if(l == r) return l;
    int res = f[f[x].l].sum + f[f[y].l].sum - 2 * f[f[v].l].sum;
    int mid = l + r >> 1;
    if(res >= k) return kth(f[x].l, f[y].l, f[v].l, l, mid, k);
    else return kth(f[x].r, f[y].r , f[v].r, mid + 1 , r, k - res);
}

void dfs(int nod, int pa, int cost){
    if(pa > 0){
        update(root[nod] = root[pa], 1, 100000, cost);
    }
    for(int i: a[nod]){
        if(i.first == pa) continue;
        dfs(i.first, nod, i.second);
    }
}
