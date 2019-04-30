#include <stdio.h>
#include <iostream>
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)>(b)?(b):(a)
#define TYPE unsigned long long
//I love using #define!
unsigned long long dp[2][31]={};
unsigned min[31];
unsigned max[31];
int main(){
	int n,m,mini;
	int i,j,k;
	char c;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i){
		max[i]=n;
		min[i]=0;
	}
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			tag:;
			c=getchar();
			switch(c){
				case '.':
					break;
				case 'B':
					min[j]=max(min[j],i+1);
					break;
				case 'R':
					max[j]=min(max[j],i);
					break;
				default:
					goto tag;
			}
		}
	}
	unsigned long long *pre=dp[0],*next=dp[1],temp_max=n;
	pre[n]=1;
	for(i=0;i<m;++i){

		for(j=0;j<min[i];++j){
			next[j]=0;
		}
		for(j=min[i];j<=max[i];++j){
			next[j]=0;
			for(k=temp_max;k>=j;--k){
				next[j]+=pre[k];
			}
		}
		temp_max=min(temp_max,max[i]);
		unsigned long long *temp=pre;
		pre=next;
		next=temp;
	}
	unsigned long long ans=0;
	for(i=0;i<=temp_max;++i){
		ans+=pre[i];
	}
	std::cout<<ans;
	return 0;
}

