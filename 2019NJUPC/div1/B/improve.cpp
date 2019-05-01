//B. Coffee or Chicken
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <algorithm>
using std::cin;
using std::min;
uint64_t a[505]={0,6,7};
const char *s[]={"","COFFEE","CHICKEN"};
int fib(int n,int64_t pos,int len){
    if(len<=0)return 0;
    if(n<3){
        return printf("%.*s",len,s[n]+pos);
    }else{
        if(pos>a[n-2]){
            return fib(n-1,pos-a[n-2],len);
        }else{
            int ret=fib(n-2,pos,len);
            ret+=fib(n-1,0,len-ret);
            return ret;
        }
    }
}
int main(){
    int n,i;
    int64_t k;
    for(i=3;a[i-1]<1100000000000;++i){
        a[i]=a[i-1]+a[i-2];
    }
    int T;
    cin>>T;
    while(T-->0){
        cin>>n>>k;
        fib(min(n,i),k-1,10);
        puts("");
    }
    return 0;
}
