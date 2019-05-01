#include <stdio.h>
int a[31];
int fib(int n,int pos,int len){
    if(n<3){
    if(n==1){
        int cnt=0;
        for(int i=pos;i<6&&i<len;++i){
        putchar("COFFEE"[i]);
        ++cnt;
        }
        return cnt;
    }else{
        int cnt=0;
        for(int i=pos;i<7&&i<len;++i){
        putchar("CHICKEN"[i]);
        ++cnt;
        }
        return cnt;
    }
    }else{
        if(pos>a[n-2]){
        return fib(n-1,pos-a[n-2],len);
        }else{
        int temp=fib(n-2,pos,len);
        temp+=fib(n-1,0,len-temp);
        return temp;
        }
    }
}
int main(){
    int n,k,i;
    a[1]=6;
    a[2]=7;
    for(i=3;i<=30;++i){
    a[i]=a[i-1]+a[i-2];
    }
    scanf("%d%d",&n,&k);
    fib(n,k-1,10);
    puts("");
    return 0;
}
