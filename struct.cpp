#include<stdio.h>

struct student{
    char c[100];
    int a;
    int b;
    bool operator < (const student s)const
    {
        if(a!=s.a) return a<s.a;
        else return b<s.b;
    }
}s[100];

int main(){
s[0]=(student){"somkit",999,5};
s[1]=(student){"sirirat",48,6};
student fuck={"prayut",44,112},*ss;
ss=s[0]<s[1]?&s[1]:&s[0];
printf("%s %d %d :%d",ss->c,ss->a,ss->b,s[1].a);
}
