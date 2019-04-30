#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long gcd(unsigned long long,unsigned long long);
int main(){
    unsigned long long i,num,j,k;
    for(i=0;i<32;++i){
        num=(1<<i)-1;
        unsigned long long temp=0;
        for(j=1;j<num;++j){
            temp=max(temp,gcd(num-j,j));
        }
        printf("llx,",temp);
    }
    return 0;
}
unsigned long long gcd(unsigned long long a,unsigned long long b){
    if(b==0)return a;
    if(a>=b){
        return gcd(b,a%b);
    }else{
        return gcd(a,b%a);
    }
}

