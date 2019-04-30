#include <stdio.h>
#include <queue>
using std::priority_queue;
using std::vector;
using std::greater;
using std::less;
class edge{
public:
	int from,to,cost;
	bool operator>(const edge another)const{
		return cost>another.cost;
	}
	edge(int a,int b,int c){
		from=a;
		to=b;
		cost=c;
	}
};
int distance[101][101];
int father[101];
void join(int,int);
bool add[101]={};
int find(int);
int main(){
	int i,j,k,e=0,n,q,temp;
	int ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		father[i]=i;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			scanf("%d",&(distance[i][j]));
		}
	}
	scanf("%d",&q);
	priority_queue<edge,vector<edge>,greater<edge> > heap;
	for(i=0;i<q;++i){
		scanf("%d%d",&j,&k);
		join(j,k);
		if(!add[j]){
			add[j]=1;
			for(int i=1;i<=n;++i){
				if(find(j)!=find(i)){
					heap.push(edge(j,i,distance[j][i]));
				}
			}
		}
		if(!add[k]){
			add[k]=1;
			for(int i=1;i<=n;++i){
				if(find(k)!=find(i)){
					heap.push(edge(k,i,distance[k][i]));
				}
			}
		}
	}
	if(q==0){
		for(i=2;i<=n;++i){
			heap.push(edge(1,i,distance[1][i]));
		}
	}
	while(!heap.empty()){
		edge build(0,0,0);
		build=heap.top();
		heap.pop();
		if(find(build.from)!=find(build.to)){
			ans+=build.cost;
			join(build.from,build.to);
			for(i=1;i<=n;++i){
				if(find(i)!=find(build.to)){
					heap.push(edge(build.to,i,distance[build.to][i]));
				}
			}
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
