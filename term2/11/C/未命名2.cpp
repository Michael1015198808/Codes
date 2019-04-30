#include <stdio.h>
#include <queue>
#include <algorithm>
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
		sum(a,a+n);
		for(i=m-1;;--i){
			printf("%d",dp[i]);
			if(i==0){
				putchar('\n');
				break;
			}else{
				putchar(' ');
			}
		}
	}
	return 0;
}
void sum(int* begin,int* end){
	int *i,*j,cnt=0;
	priority_queue <int,vector<int>,greater<int> >q;
	for(i=end-1;i>=begin;--i){
		for(j=i-1;j>=begin;--j){
			q.push(*i+*j);
			if(++cnt==m){
				goto tag;
			}
		}
	}
	for(;i>=begin;--i){
		for(j=i-1;j>=begin;--j){
			if(*i+*j<q.top()){
				break;
			}else{
				q.pop();
				q.push(*i+*j);
			}
			tag:;
		}
	}
	for(int i=0;i<m;++i){
		dp[i]=q.top();
		q.pop();
	}
}

