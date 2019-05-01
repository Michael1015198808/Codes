//B. Coffee or Chicken
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <algorithm>
using std::cin;
using std::min;
uint64_t a[505];
int fib(int n,int64_t pos,int len){
    if(len<=0)return len;
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
    int n,i;
    int64_t k;
    a[1]=6;
    a[2]=7;
    for(i=3;;++i){
        a[i]=a[i-1]+a[i-2];
        if(a[i]>1100000000000)break;
    }
    int T;
    cin>>T;
    while(T-->0){
        cin>>n>>k;
        n=min(n,i);
        fib(n,k-1,10);
        puts("");
    }
    return 0;
}
