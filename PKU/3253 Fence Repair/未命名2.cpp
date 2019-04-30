#include <cstdio>
#include <queue>
using namespace std;
int main(){
	int n,i,mid1,mid2;
	long long money=0;
	priority_queue<int,vector<int>,greater<int> >pque;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&mid1);
		pque.push(mid1);
	}
	while(--n>0){
		mid1=pque.top();
		pque.pop();
		mid2=pque.top();
		pque.pop();
		pque.push(mid1+mid2);
		money+=mid1+mid2;
	}
	printf("%lld",money);
	return 0;
}
