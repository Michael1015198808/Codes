//B. Coffee or Chicken
#include <stdio.h>
#include <string.h>
int a[31]={0,6,7};
const char *s[]={"","COFFEE","CHICKEN"};
int fib(int n,int pos,size_t len){
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
    int n,k,i;
    for(i=3;i<=30;++i){
        a[i]=a[i-1]+a[i-2];
    }
    scanf("%d%d",&n,&k);
    fib(n,k-1,10);
    puts("");
    return 0;
}
