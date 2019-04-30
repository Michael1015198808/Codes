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
	int i,j,k,e=0,n,temp;
	int ans=0;
	while(scanf("%d",&n)==1){
		ans=0;
		if(n==0){
			return 0;
		}
		for(i=1;i<=n;++i){
			father[i]=i;
		}
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				scanf("%d",&(distance[i][j]));
			}
		}
		priority_queue<edge,vector<edge>,greater<edge> > heap;
		for(i=2;i<=n;++i){
			heap.push(edge(1,i,distance[1][i]));
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
		printf("%d\n",ans);
	}
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
