#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;
int num=-1;
int dfn[5001],low[5001],head[5001],belong[5001];
bool vis[5001];
int stack[5001];
int old_path[5001][5001];
int new_path[5001][5001],degree[5001];
int n,m;
int tarjan(int x){
				static int cnt=-1,index=-1;
				int i,j,k;
				dfn[x]=low[x]=++cnt;
				vis[x]=1;
				stack[++index]=x;
				rep(i,1,n+1){
								if(old_path[x][i]){
								if(!dfn[i]){
												old_path[i][x]=0;
												if(tarjan(i)<low[x]){
																low[x]=low[i];
												}
												old_path[i][x]=1;
								}else if(vis[i]){
												update(low[x],dfn[i]);
								}
								}
				}
				if(low[x]==dfn[x]){
								++num;
								degree[num]=0;
								do{
												printf("%d:%d\n",stack[index],num);
												belong[stack[index]]=num;
												vis[stack[index]]=0;
												--index;
								}while(x!=stack[index+1]);
				}
				return low[x];
}
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1){
					head[i]=-1;
					dfn[i]=0;
					vis[i]=0;
	}
	rep(i,0,m){
					scanf("%d%d",&j,&k);
					old_path[j][k]=1;
					old_path[k][j]=1;
	}
	rep(i,1,n+1){
					if(dfn[i]){
									continue;
					}
					tarjan(i);
	}
	rep(i,1,n+1){
					rep(j,1,n+1){
									if(old_path[i][j]){
									if(new_path[belong[j]][belong[i]]++){
													continue;
									}
									degree[belong[j]]++;
									}
					}
	}
	rep(i,1,num+1){
					printf("%d:%d\n",i,degree[i]);
	}
	int ans=0;
	rep(i,0,num+1){
					if(degree[i]==1){
									printf("%d\n",i);
									++ans;
					}
	}
	printf("%d\n",(ans+1)>>1);
	return 0;
}

