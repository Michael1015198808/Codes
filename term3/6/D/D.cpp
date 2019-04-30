#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF (1e9-1)
unsigned int dis[1001];
int main(){
				int n,m,i,j,k,s,t,cost,no;
				scanf("%d%d",&n,&m);
				vector< vector<pair<int,int> > >edge(n+1);
				priority_queue<pair<int,int> >p;
				for(i=0;i<m;++i){
								scanf("%d%d%d",&j,&k,&s);
								edge[j].push_back(make_pair(s,k));
								//first:=cost
								//second:=destination
				}
				for(i=1;i<=n;++i){
								dis[i]=INF;
				}
				scanf("%d%d",&s,&t);
				p.push(make_pair(0,s));
				while(!p.empty()){
									no=p.top().second;
									cost=-p.top().first;
									p.pop();
									if(cost>dis[no]){
													continue;
									}
								dis[no]=cost;
								for(i=0;i<edge[no].size();++i){
												if(dis[no]+edge[no][i].first<dis[edge[no][i].second]){
													p.push(make_pair(-dis[no]-edge[no][i].first,edge[no][i].second));
													dis[edge[no][i].second]=dis[no]+edge[no][i].first;
												}
												//printf("%d %d\n",dis[no]+edge[no][i].first,edge[no][i].second);
								}
				}
				if(dis[t]==INF){
								puts("-1");
				}else{
								printf("%d\n",dis[t]);
								for(i=1;i<=n;++i){
												for(j=1;j<=n;putchar(' '),++j){
																printf("%d",(int)(dis[j]-dis[i]));
												}
												putchar('\n');
								}
				}
				return 0;
}

