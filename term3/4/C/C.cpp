#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
class point{
public:
				int x,y;
}points[100];
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
bool operator>(edge a,edge b){
				return a.cost>b.cost;
}
int find(int);
void unite(int,int);

int fa[100];
int way[100];
int main(){
				int n,k;
				int i,j;
				scanf("%d%d",&n,&k);
				for(i=0;i<n;++i){
								fa[i]=i;
								scanf("%d%d",&points[i].x,&points[i].y);
				}
				priority_queue <edge,vector<edge>,greater<edge> > map;
				for(i=1;i<n;++i){
								map.push(edge(0,i,abs(points[i].y-points[0].y)+abs(points[i].x-points[0].x)));
				}
				for(i=0;i<n-1;++i){
								edge temp;
								do{
												temp=map.top();
												map.pop();
								}while(find(temp.from)==find(temp.to));
								way[i]=temp.cost;
								unite(temp.from,temp.to);
								for(j=0;j<n;++j){
												if(find(temp.to)!=find(j)){
																map.push(edge(temp.to,j,abs(points[j].y-points[temp.to].y)+abs(points[j].x-points[temp.to].x)));
												}
								}
				}
				sort(way,way+n-1);
				printf("%d\n",way[n-1-k]);
				return 0;
}
int find(int a){
				if(fa[a]==fa[fa[a]]){
								return fa[a];
				}else{
								return fa[a]=find(fa[a]);
				}
}
void unite(int x,int y){
				fa[find(x)]=find(y);
}
