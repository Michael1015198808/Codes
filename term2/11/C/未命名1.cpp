#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[3000];
int dp[1000];
int n,m;
void sum(int*,int*);
int main(){
	int i;
	while(scanf("%d",&n)==1){
		scanf("%d",&m);
		for(i=0;i<n;++i){
			scanf("%d",a+i);
		}
		sort(a,a+n);
		memset(dp,0,sizeof(int)*m);
		if(n>m){
			sum(a+n-m,a+n);
		}else{
			sum(a,a+n);
		}
		for(i=0;i<m;++i){
			printf("%d",dp[i]);
			if(i==m-1){
				putchar('\n');
			}else{
				putchar(' ');
			}
		}
	}
	return 0;
}
void sum(int* begin,int* end){
	int *i,*j,k,l,s;
	for(i=begin;i!=end;++i){
		for(j=i+1;j!=end;++j){
			s=*i+*j;
			for(k=0;k<m;++k){
				if(s>dp[k]){
					break;
				}
			}
			for(l=m;l>k;--l){
				dp[l]=dp[l-1];
			}
			dp[k]=s;
		}
	}
}

