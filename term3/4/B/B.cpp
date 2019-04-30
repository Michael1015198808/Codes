#include <stdio.h>
#include <iostream>
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
void solve(void);
void unite(int,int);
int find(int);
int cal(int,int,int);

bool choosen[200];
edge map[200];
int fa[21];
int dp[21][21];
int n;
int main(){
				int t=0;
				scanf("%d",&t);
				while(t--){
								solve();
				}
				return 0;
}
void solve(void){
				int i=0,j=0,m=0,cost=0;
				long long sum=0;
				scanf("%d%d",&n,&m);
				for(i=1;i<=n;++i){
								fa[i]=i;
								for(j=1;j<=n;++j){
												dp[i][j]=-1;
								}
				}
				for(i=0;i<m;++i){
								scanf("%d%d%d",&map[i].from,&map[i].to,&map[i].cost);
								choosen[i]=false;
				}
				sort(map,map+m);
				for(i=0;i<m;++i){
								if(find(map[i].from)!=find(map[i].to)){
												unite(map[i].from,map[i].to);
												sum+=map[i].cost;
												dp[map[i].from][map[i].to]=map[i].cost;
												dp[map[i].to][map[i].from]=map[i].cost;
												choosen[i]=true;
								}
				}
				for(i=0;i<m;++i){
								if(choosen[i]==true){
												continue;
								}
								if(map[i].cost<=cal(map[i].from,map[i].to,0)){
												cout<<"Peter can find other ways"<<endl;
												return;
								}
				}
				cout<<sum<<endl;
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
int cal(int a,int b,int c){
				int num=0;
				if(dp[a][b]==-1){
								int i;
								for(i=1;i<=n;++i){
												if(dp[a][i]!=-1&&i!=c){
																int temp=cal(i,b,a);
																if(temp!=0){
																				num=max(dp[a][i],temp);
																}
												}
								}
				}else{
								num=dp[a][b];
				}
				return num;
}
