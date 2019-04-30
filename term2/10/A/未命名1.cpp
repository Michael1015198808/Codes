#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main(){
	int i,a,b,n,temp;
	long long ans=0;
	priority_queue<long long, vector<long long>, greater<long long> > blank;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&temp);
		blank.push(temp);
	}
	while(blank.size()>1){
		a=blank.top();
		blank.pop();
		b=blank.top();
		blank.pop();
		temp=a+b;
		ans+=temp;
		blank.push(temp);
	}
	printf("%lld",ans);
	return 0;
}
