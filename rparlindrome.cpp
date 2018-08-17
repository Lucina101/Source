#include<stdio.h>
#include<string.h>
char p[1000],low[1000],high[1000],same[1000];
int i,g;
char mirror(char *x){
     g=strlen(x);
    for(i=0;i<g/2;i++)
        x[g-1-i]=x[i];
return *x;
}
int lowhighorsame(char *a){
    g=strlen(a);
    char t[g];
    for(i=0;i<g;i++){
        t[i]=a[i];
    }
    mirror(a);
    for(i=g/2;i<g;i++){
        if(a[i]>t[i])
            return 1;
        else if(a[i]<t[i])
            return -1;
    }
    return 0;
}
char down(char *x){
    g=strlen(x);
    bool t=true;
    for(i=g/2-1+(g%2);t&&i>=0;i--){
        if(x[i]!='0') {
            if(!(i==0&&x[i]=='1')){
        x[i]=x[i]-1;
        t=false;
            }
        }
        else if(x[i]='0'){
            x[i]='9';
        }
         if(i==0&&x[i]=='1'){
            x[0]='9';
            x[g-1]='\0';
        }
    }
    char v=mirror(x);
return v;
}
char up(char *x){
g=strlen(x);
    bool t=true;
    for(i=g/2-1+(g%2);t&&i>=0;i--){
        if(x[i]!='9') {
            if(!(i==0&&x[i]=='9')){
        x[i]=x[i]+1;
        t=false;
            }
        }
        else if(x[i]='9'&&i!=0){
            x[i]='0';
        }
         if(i==0&&x[i]=='9'){
            char t[g+1];
            t[0]='1';
            for(int k=1;k<g+1;k++)
                t[k]='0';
            return *t;
        }
    }
    char v=mirror(x);
return v;
}
int main(){
    scanf("%s",p);
        int d=strlen(p);
    for(int ll=0;ll<d;ll++){
        low[ll]=p[ll];
        high[ll]=p[ll];
        same[ll]=p[ll];
    }
    low[d]='\0';high[d]='\0';same[d]='\0';
    int t=lowhighorsame(p);
    // special case that I'm so tried to make it perfect, so I give up
    bool x=true;
    bool y=true;
    if(d==1&&p[0]=='1'){
        printf("0 2");
        x=false;
    }
    for(int u=0;u<d;u++){
        if(p[u]!='9')
            y=false;
    }
    if(y){
            down(low);
        printf("%s ",low);
        printf("%d",1);
        for(int last=1;last<d;last++)
            printf("%d",0);
        printf("%d",1);
        x=false;
    }
    if(x){
    if(t==0){
            down(low);
            up(high);
        printf("%s ",low);
        printf("%s ",high);
    }
    else if(t==1){
            down(low);
            printf("%s ",low);
            printf("%s ",p);
    }
    else if(t==-1){
        up(high);
        printf("%s ",p);
        printf("%s ",high);
}
}
}
