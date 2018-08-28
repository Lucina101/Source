#include<stdio.h>
struct l_l{
    int val;
    l_l *ptr;
};
struct l_list{
 l_l man;
 l_l *en;
}l;
void create(int a){
    l.man.val=a;
    l.man.ptr=NULL;
    l.en=&l.man;
}
void query(){
    l_l *q=&l.man;
    do{
        printf("%d ",q->val);
        q=q->ptr;
    }while(q!=NULL);
}
int main(){
    int x;
    char c[4];
    scanf("%d",&x);
    create(x);
    do{
        scanf("%s %d",c,&x);
        if(c[0]=='i'||c[0]=='I') query();
    }while(c[0]!='S');
}


