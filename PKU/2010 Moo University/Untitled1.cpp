#include <stdio.h>
#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class cow{
public:
	long long score;
	int aid;
	bool operator<(const cow another)const{
		return score<another.score;
	}
};
cow a[100000]={};
long long leftcost[100000]={};
long long rightcost[100000]={};
int main(){
	int i,n,c;
	long long sum=0,f;
	cin>>n>>c>>f;
	for(i=0;i<c;++i){
		cin>>a[i].score>>a[i].aid;
	}
	sort(a,a+c);
	priority_queue <int> p;
	int l=n>>1,r=c-(n>>1);
	for(i=0,sum=0;i<l;++i){
		sum+=a[i].aid;
		p.push(a[i].aid);
	}
	for(i=l;i<r;++i){
		leftcost[i]=sum;
		sum+=a[i].aid;
		p.push(a[i].aid);
		sum-=p.top();
		p.pop();
	}
	while(!p.empty()){
		p.pop();
	}
	for(i=c-1,sum=0;i>=r;--i){
		sum+=a[i].aid;
		p.push(a[i].aid);
	}
	for(i=r-1;i>=l;--i){
		rightcost[i]=sum;
		sum+=a[i].aid;
		p.push(a[i].aid);
		sum-=p.top();
		p.pop();
	}
	for(i=r-1;i>=l;--i){
//		printf("i%dl%d\n",i,l);
		if(rightcost[i]+leftcost[i]+a[i].aid<=f){
			printf("%ld",a[i].score);
			break;
		}
	}
	if(i<l){
		printf("-1");
	}
	return 0;
}
