//I use i[0] as 'i', i[1] as 'j', i[2] as 'k' ... to make it clearer.
#include <stdio.h>
//#include <windows.h>
#define MAX 32769
bool is_prime[MAX]={};
int main(){
	int i[5],in,count=0;
	for(i[0]=2;i[0]<MAX;++i[0]){
		is_prime[i[0]]=1;
	}
	for(i[0]=2;i[0]*i[0]<MAX;++i[0]){
		for(i[1]=i[0];i[1]*i[0]<MAX;++i[1]){
			is_prime[i[0]*i[1]]=0;
		}
	}
	while(scanf("%d",&in)){
		if(!in){
			break;
		}
		if(in==4){
			printf("1\n");
			continue;
		}
		count=0;
		for(i[0]=2;2*i[0]<=in;++i[0]){
			if(is_prime[i[0]]&&is_prime[in-i[0]]){
				count++;
			}
		}
		printf("%d\n",count);
	}
}
