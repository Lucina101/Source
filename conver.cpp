#include<stdio.h>
//to convert decimal to binary 
int n;
void convert(int x){
    if(x==0){
        printf("%d",0);
        return;
    }
    if(x==1){
        return;
    }
    convert(x/2);
    printf("%d",x%2);
}
int main(){
    scanf("%d",&n);
    convert(n);
}
