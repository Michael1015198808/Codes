#include <stdio.h>
#include <iostream>

long a[1000000]={};
long b[4294967297]={};
int main(){
	long i,j,k,total=0,now,p,min=1000000;
	scanf("%ld",&p);
	for(i=0;i<p;++i){
		scanf("%ld",a+i);
		if(b[a[i]]==0){
			++b[a[i]];
			++total;
		}
	}
	memset(b,0,p*sizeof(int));
	i=j=now=0;
	while(j<p){
		while(j<p&&now<total){
			if(b[a[j]]++==0){
				++now;
			}
			++j;
		}
		while(i<p&&now==total){
			if(--b[a[i]]==0){
				--now;
			}
			++i;
		}
		if(j-i<min){
			min=j-i;
		}
	}
	printf("%ld",min+1);
	return 0;
}

