#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
typedef unsigned long long ull;
const ull INF=-1;
using namespace std;
ull dis[200001];
int main(){
    int i,j,k,n,m;
    ull l;
    scanf("%d%d",&n,&m);
		pair<ull,int> temp;
    vector< vector<pair<ull,int> > >path(n+2);
    rep(i,0,m){
                    scanf("%d%d%lld",&j,&k,&l);
										temp.first=l<<1;
										temp.second=k-1;
                    path[j-1].push_back(temp);
										temp.second=j-1;
                    path[k-1].push_back(temp);
    }
    rep(i,0,n){
                    scanf("%lld",&l);
										temp.first=l;
										++temp.second;
                    path[n+1].push_back(temp);
                    dis[i]=INF;
    }
    dis[n]=1;
    priority_queue<pair<ull,int> >q;
    q.push({0,n+1});
    while(!q.empty()){
                    ull cost=q.top().first;
                                        int dest=q.top().second;
                    q.pop();
                    if(cost>dis[dest]){
                                    continue;
                    }
                    rep(i,0,path[dest].size()){
																		ull newcost=path[dest][i].first+dis[dest];
																		int newdest=path[dest][i].second;
                                    if(newcost<dis[newdest]){
																						temp.first=newcost;
																						temp.second=newdest;
                                            q.push({newcost,newdest});
                                    }
                    }
    }
    rep(i,0,n){
        printf("%llu",dis[i]);
        if(i!=n){putchar(' ');}
    }
    return 0;
}
