#include <cstdio>
#include <queue>
using namespace std;
int main(){
	int l,p,n,i=0,c=0,a[10000]={0},b[10000]={0};
	priority_queue<int>pque;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	scanf("%d%d",&l,&p);
	l-=p;
	while(l>0){
		for(i=0;i<n;i++){
			if(l<=a[i]){
				pque.push(b[i]);
				a[i]=0;
			}
		}
		if(pque.empty()){
			printf("-1");
			return 0;
		}
		p=pque.top();
		pque.pop();
		c++;
		l-=p;
	}
	printf("%d",c);
	return 0;
}
