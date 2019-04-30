#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stdint.h>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
const uint64_t INF=0x3f3f3f3f3f3f3f3f;
struct edge{
                int to,confine;
                uint64_t cost;
};
bool operator< (edge a,edge b){
                return a.cost<b.cost;
}
using namespace std;
uint64_t dis[50001];
inline void solve(void){
                int i,j,k,h,m,n;
                uint64_t l;
                scanf("%d%d",&n,&m);
                vector< vector<edge> >path(n+1);
                priority_queue<edge> q;
                for(i=1;i<=n;++i){
                                dis[i]=INF;
                }
                for(i=0;i<m;++i){
                                scanf("%d%d%llu%d",&j,&k,&l,&h);
                                //from,to,delta_level,min_cost
                                path[j].push_back({k,h,l});
                }
                q.push({1,0,1});
                while(!q.empty()){
                                int a=q.top().to;
                                uint64_t b=q.top().cost;
                                int c=q.top().confine;
                                q.pop();
                                if(b>dis[a]){
                                                continue;
                                }
                                dis[a]=b;
																for(i=0;i<path[a].size();++i){
                                				if(1LL<=(((dis[a]+path[a][i].cost)/dis[a])>>path[a][i].confine)){
                                                if((path[a][i].cost+dis[a])<dis[path[a][i].to]){
																								dis[path[a][i].to]=path[a][i].cost;
																								dis[path[a][i].to]+=dis[a];
                                                            q.push({
																														path[a][i].to,
                                                            path[a][i].confine,
                                                            dis[path[a][i].to]});
																								}
																				}
                                }
                }
                if(dis[n]==INF){
                                puts("-1");
                }else{
                                for(i=0;dis[n]!=0;++i){
																				dis[n]>>=1;
                                }
                                printf("%d\n",i-1);
                                return;
                }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
                    solve();
    }
    return 0;
}
