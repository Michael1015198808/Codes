#include <stdio.h>
#include <algorithm>
using std::sort;
#define num 100000
int fa[num+10];
bool solved[num+10];
class edge{
public:
	int from,to,cost;
};
bool operator<(edge a,edge b){
	return a.cost<b.cost;
}

edge edges[250000];
void solve(void);
int find(int);
void unite(int,int);
int main(){
		solve();
	return 0;
}
void solve(void){
	int n,K,m,i,j,k,l;
	char c;
	unsigned long long sum=0;
	scanf("%d%d%d",&n,&K,&m);
	for(i=0;i<n;++i){
		fa[i]=i;
		solved[i]=false;
	}
	for(i=0;i<K;++i){
		scanf("%d%d",&j,&k);
		unite(j,k);
	}
	for(i=0;i<m;++i){
		scanf("%d%d%d",&edges[i].from,&edges[i].to,&edges[i].cost);
		if(find(edges[i].from)==find(edges[i].to)){
			--m;
			--i;
		}
	}
	sort(edges,edges+m);
	for(i=l=0;i<m;++i){
		if(find(edges[i].from)!=find(edges[i].to)){
			sum+=edges[i].cost;
			++l;
			unite(edges[i].from,edges[i].to);
		}
	}
	printf("%d %ld\n",l+1,sum);
}
int find(int i){
	if(fa[i]==fa[fa[i]]){
		return fa[i];
	}else{
		return fa[i]=find(fa[i]);
	}
}
void unite(int a,int b){
	fa[find(a)]=find(b);
	return;
}

