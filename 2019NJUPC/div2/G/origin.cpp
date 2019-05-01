//G. NJU Emulator
#include <stdio.h>
#include <stdint.h>
#include <iostream>
using namespace std;
int main(){
    int i;
    uint64_t n,mask=-1;
    cin>>n;
    puts("p1");
    for(i=1;i<64;++i){
	    puts("dup");
	    puts("add 1");
    }
    puts("p1");
    puts("sub 64");
    while(n!=0){
	    if(n&1){
	        printf("add %d\n",i);
	    }
	    n>>=1;
	    --i;
    }
    puts("end");
    return 0;
}

