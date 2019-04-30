#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
short b[2001],m,n;
long long a[2001];
void inline ini(void){for(int i=1;i<n;++i)a[i]=10000;}
void add(void);
int main(){
	int time,i,j,k,l,temp=0;
	scanf("%d",&time);
	while(time--){
		scanf("%d%d",&m,&n);
		ini();
		a[0]=0;
		for(i=0;i<m;++i){
			add();
		}
		for(i=0;i<n;++i){
			printf("%lld%c",a[i],i==n-1?'\n':' ');
		}
	}
	return 0;
}
void add(void){
	int i,j;
	for(i=0;i<n;++i){
		scanf("%d",&(b[i]));
	}
	sort(b,b+n);
	priority_queue<long long, vector<long long>, less<long long> > q;
	for(i=0;i<n;++i){
		q.push(a[i]+b[0]);
//		printf("%d ",a[i]+b[0]);
	}
	for(j=1;j<n;++j){
		for(i=0;i<n;++i){
			if(a[i]+b[j]<q.top()){
				q.pop();
				q.push(a[i]+b[j]);
//				printf("a[%d]+b[%d]=%d ",i,j,a[i]+b[j]);
			}else{
				break;
			}
		}
	}
	for(i=n-1;i>=0;--i){
		a[i]=q.top();
//		printf("%d ",a[i]);
		q.pop();
	}
}

