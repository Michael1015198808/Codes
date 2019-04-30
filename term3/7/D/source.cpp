//My programming style is becoming worse and worse. orz
#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x30000000
using namespace std;
unsigned int dis[125][125];
unsigned int trans[125];
unsigned int dijk_dis[125];
int main(){
	int i,j,k,l;
	int n,m,w;
	scanf("%d%d%d",&n,&m,&w);
#define temp pair<int,int>
	vector<vector<temp> >path(n+1);
	priority_queue<temp,vector<temp>,greater<temp> >q;
#undef temp
	rep(i,1,n+1){
					rep(j,1,n+1){
									dis[i][j]=INF;
					}
					dis[i][i]=0;
	}
	rep(i,0,m){
					int a,b,c;
					scanf("%d%d%d",&a,&b,&c);
					path[a].push_back({c,b});
					dis[a][b]=c;
	}
	rep(k,1,n+1){
					rep(i,1,n+1){
									rep(j,1,n+1){
													update(dis[i][j],dis[i][k]+dis[k][j]);
									}
					}
	}
	rep(l,0,w){
					unsigned int ans=INF;
					rep(i,1,n+1){
									scanf("%d",&trans[i]);
					}
					rep(i,1,n+1){
									if(trans[i]==i){
													ans=0;
													break;
									}else if(trans[i]>n||trans[trans[i]]>n){
													continue;
									}
									rep(j,1,m+1){
													dijk_dis[j]=INF;
									}
									q.push({dijk_dis[i]=0,i});
									while(!q.empty()){
													unsigned int a=q.top().first,b=q.top().second;
													q.pop();
													if(a>dijk_dis[b]){
																	continue;
													}
													rep(k,0,path[b].size()){
																	if(path[b].at(k).first+a<dijk_dis[path[b].at(k).second]){
																					if(path[b].at(k).second!=trans[i]){
																									q.push({(dijk_dis[path[b][k].second]=path[b][k].first+a),path[b][k].second});
																					}
																	}
													}
									}
									update(ans,dijk_dis[trans[trans[i]]]+dis[trans[trans[i]]][trans[i]]+dis[trans[i]][trans[trans[i]]]);
					}
					if(ans==INF){
									puts("bug");
					}else{
									printf("%d\n",ans);
					}
	}
	return 0;
}

