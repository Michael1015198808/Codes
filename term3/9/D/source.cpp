#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;
unsigned int cost[16][16];
unsigned int dp[1<<16];
int degree[16];
int n,m;
int solve(int);
int main(){
	int i,j,k,l;
	int ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1){
					rep(j,1,n+1){
									cost[i][j]=0x3fffffff;
					}
					cost[i][i]=0;
					degree[i]=0;
	}
	rep(i,0,m){
					scanf("%d%d%d",&j,&k,&l);
					ans+=l;
					degree[j]++;
					degree[k]++;
					update(cost[j][k],l);
					update(cost[k][j],l);
	}
	rep(k,1,n+1){
					rep(i,1,n+1){
									rep(j,1,n+1){
													update(cost[i][j],cost[i][k]+cost[j][k]);
									}
					}
	}
	int mark=0;
	rep(i,1,n+1){
					mark|=(degree[i]&1)<<i;
	}
	printf("%d\n",ans+solve(mark));
	return 0;
}

int solve(int mark){
				//printf("solve(%d)",mark);
				int i,j;
				if(dp[mark]!=0){
								return dp[mark];
				}
				if(mark==0){
								return 0;
				}
				dp[mark]=-1;
				rep(i,1,n+1){
								if(mark&(1<<i)){
												rep(j,i+1,n+1){
																if(mark&(1<<j)){
																				//printf("%d %d %d",mark,i,j);
																				update(dp[mark],cost[i][j]+solve(mark^(1<<i)^(1<<j)));
																}
												}
								}
				}
				return dp[mark];
}
