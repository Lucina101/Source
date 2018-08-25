#include<stdio.h>
int n;
void convert(int x){

    if(x==0)
    return;
    convert(x/2);
    printf("%d",x%2);
}

int main(){
    scanf("%d",&n);
    if(n!=0)
    convert(n);
    else
    printf("%d\n",0);
}
