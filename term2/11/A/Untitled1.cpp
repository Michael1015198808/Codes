#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
long ans=0;
int main(){
	int n1,n2,n,i;
	long temp;
	while(3==scanf("%d%d%d",&n1,&n2,&n)){
		if(n==0){
			break;
		}
		priority_queue<long,vector<long>,less<long> > q;
		priority_queue<long,vector<long>,greater<long> > p;
		ans=0;
		i=0;
		while(i<min(n1,n2)){
			scanf("%ld",&temp);ans+=temp;
			q.push(temp);
			p.push(temp);
			++i;
		}
		if(n1>n2){
			while(i<max(n1,n2)){
				scanf("%ld",&temp);ans+=temp;
				if(temp<q.top()){
					q.pop();
					q.push(temp);
				}
				p.push(temp);
				++i;
			}
		}else{
			while(i<max(n1,n2)){
				scanf("%ld",&temp);ans+=temp;
				q.push(temp);
				if(temp>p.top()){
					p.pop();
					p.push(temp);
				}
				++i;
			}
		}
		while(i<n){
			scanf("%ld",&temp);ans+=temp;
			if(temp<q.top()){
				q.pop();
				q.push(temp);
			}
			if(temp>p.top()){
				p.pop();
				p.push(temp);
			}
			++i;
		}
		while(!p.empty()){
			ans-=p.top();
			p.pop();
		}
		while(!q.empty()){
			ans-=q.top();
			q.pop();
		}
		printf("%.6lf\n",((double)ans)/(n-n1-n2));
	}
	return 0;
}

