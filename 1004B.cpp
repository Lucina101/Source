#include<stdio.h>

int main(){
int n,m,l,r;
scanf("%d%d",&n,&m);
for (int i = 0; i < m; i++)
scanf("%d%d", &l, &r); // not used
for (int i = 0; i < n; i++)
printf("%d", i%2);
}


