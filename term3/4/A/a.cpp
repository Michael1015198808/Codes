#include <stdio.h>
#include <algorithm>
using namespace std;
class edge{
public:
				int from,to,cost;
				edge(int i,int j,int k){
								from=i;to=j;cost=k;
				}
				edge(void){
								from=to=cost=0;
				}
};
bool operator<(edge a,edge b){
				return a.cost<b.cost;
}
void unite(int,int);
int find(int);
int fa[101];
int main(){
				edge map[10000];
				int n=0,i=0,j=0,k=0,cost=0;
				long long sum=0;
				scanf("%d",&n);
				for(i=1;i<=n;++i){
								fa[i]=i;
								for(j=1;j<=n;++j){
												scanf("%d",&cost);
												map[k].from=i;
												map[k].to=j;
												map[k].cost=cost;
												++k;
								}
				}
				sort(map,map+k);
				for(i=0;i<k;++i){
								if(find(map[i].from)!=find(map[i].to)){
												unite(map[i].from,map[i].to);
												sum+=map[i].cost;
								}
				}
				cout<<sum;
				return 0;
}
void unite(int a,int b){
				fa[find(a)]=find(b);
}
int find(int i){
				if(fa[i]==fa[fa[i]]){
								return fa[i];
				}
				find(fa[i]);
				return fa[i]=fa[fa[i]];
}
