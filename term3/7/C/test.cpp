#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
typedef unsigned long long ull;
typedef std::pair<ull,int> pui;
const ull INF=-1;
using namespace std;
ull dis[200001];
int main(){
    int i,j,k,n,m;
        ull l;
    scanf("%d%d",&n,&m);
    vector< vector<pair<ull,int> > >path(n+2);
    rep(i,0,m){
                    scanf("%d%d%lld",&j,&k,&l);
                    path[j-1].push_back({l<<1,k-1});
                    path[k-1].push_back({l<<1,j-1});
    }
    rep(i,0,n){
                    scanf("%lld",&l);
                    path[n+1].push_back({l,i});
                    dis[i]=INF;
    }
    dis[n]=1;
    priority_queue<pui,vector<pui>,greater<pui> >q;
    q.push({0,n+1});
    while(!q.empty()){
                    ull cost=q.top().first;
										printf("%lld\n",cost);
                                        int dest=q.top().second;
                    q.pop();
                    if(cost>dis[dest]){
                                    continue;
                    }
                    dis[dest]=cost;
                    rep(i,0,path[dest].size()){
                                    if(path[dest][i].first+dis[dest]<dis[path[dest][i].second]){
                                                    q.push({dis[path[dest][i].second]=path[dest][i].first+dis[dest],path[dest][i].second});
                                    }
                    }
    }
    rep(i,0,n){
        printf("%llu",dis[i]);
        if(i!=n){putchar(' ');}
    }
    return 0;
}
