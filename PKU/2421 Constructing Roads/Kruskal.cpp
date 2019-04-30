#include <stdio.h>
#include <algorithm>
using std::sort;
class edge{
public:
	int from,to,cost;
	bool operator<(const edge another)const{
		return cost<another.cost;
	}
}a[4950];
int father[101];
void join(int,int);
int find(int);
int main(){
	int i,j,k,e=0,n,q,temp;
	int ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		father[i]=i;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=i;++j){
			scanf("%d",&temp);
		}
		for(j=i+1;j<=n;++j){
			scanf("%d",&temp);
			a[e].from=i;
			a[e].to=j;
			a[e].cost=temp;
			++e;
		}
	}
	sort(a,a+e);
	scanf("%d",&q);
	for(i=0;i<q;++i){
		scanf("%d%d",&j,&k);
		join(j,k);
	}
	for(i=0;i<e;++i){
		if(find(a[i].from)!=find(a[i].to)){
			ans+=a[i].cost;
			join(a[i].from,a[i].to);
		}
	}
	printf("%d",ans);
	return 0;
}
int find(int a){
	int b=father[a];
	if(b!=father[b]){
		father[a]=find(b);
	}
	return father[a];
}
void join(int a,int b){
	father[find(a)]=find(b);
}
