#include<stdio.h>
void hanoi(int n,int beg,int tar,int res){
    if(n==0) return;
    hanoi(n-1,beg,res,tar);
    printf("Move plate #%d from %d to %d\n",n,beg,tar);
    hanoi(n-1,res,tar,beg);
}
int main(){
int n;
scanf("%d",&n);
hanoi(n,1,3,2);
}
