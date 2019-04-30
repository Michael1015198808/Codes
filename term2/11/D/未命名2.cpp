#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
	int temp,i,j,k,line,P=0,t=0;
	scanf("%d",&t);
	for(i=1;i<=t;++i){
		priority_queue<long,vector<long>,greater<long> > q;
		priority_queue<long,vector<long>,less<long> > p;
		scanf("%d",&P);
		scanf("%d",&P);
		scanf("%d",&temp);
		line=1;
		P>>=1;
		printf("%d %d\n%d ",i,P+1,temp);
		for(j=0;j<P;++j){
			scanf("%d",&k);
			if(k<temp){
				p.push(k);
			}else{
				q.push(k);
			}
			scanf("%d",&k);
			if(k<temp){
				p.push(k);
			}else{
				q.push(k);
			}
			if(q.size()>p.size()){
				p.push(temp);
				temp=q.top();
				q.pop();
			}else if(p.size()>q.size()){
				q.push(temp);
				temp=p.top();
				p.pop();
			}
			printf("%d",temp);
			if(++line==10){
				line=0;
				putchar('\n');
			}else{
				putchar(' ');
			}
		}
		putchar('\n');
	}
	return 0;
}

