#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;
struct{
				int v,next;
}edge[50000];
int num=-1;
int dfn[10001],low[10001],head[10001],belong[10001];
bool vis[10001];
int stack[10001];
int size[10001],degree[10001];
void add(int p,int q){
				static int cnt_edge=-1;
				edge[++cnt_edge].next=head[p];
				edge[cnt_edge].v=q;
				head[p]=cnt_edge;
				return;
}
int tarjan(int x){
				//printf("%d to %d\n",x);
				static int cnt=-1,index=-1;
				int i,j,k;
				dfn[x]=low[x]=++cnt;
				vis[x]=1;
				stack[++index]=x;
				for(i=head[x];i!=-1;i=edge[i].next){
								int v=edge[i].v;
								if(!dfn[v]){
												if(tarjan(v)<low[x]){
																low[x]=low[v];
												}
								}else if(vis[v]){
												update(low[x],dfn[v]);
								}
				}
				if(low[x]==dfn[x]){
								++num;
								size[num]=0;
								degree[num]=0;
								do{
												//printf("%d:%d\n",stack[index],num);
												belong[stack[index]]=num;
												++size[num];
												vis[stack[index]]=0;
												--index;
								}while(x!=stack[index+1]);
				}
				return low[x];
}
int main(){
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1){
					head[i]=-1;
					dfn[i]=0;
					vis[i]=0;
	}
	rep(i,0,m){
					scanf("%d%d",&j,&k);
					add(j,k);
	}
	rep(i,1,n+1){
					if(dfn[i]){
									continue;
					}
					tarjan(i);
	}
	rep(i,1,n+1){
					for(j=head[i];j!=-1;j=edge[j].next){
									if(belong[edge[j].v]!=belong[i])
									degree[belong[i]]=1;
					}
	}
	int ans=0;
	rep(i,0,num+1){
					//printf("%ddegree:%d\n",i,degree[i]);
					if(degree[i]==0){
									//printf("%d\n",i);
									if(ans==0){
													ans+=size[i];
									}else{
													putchar('0');
													return 0;
									}
					}
	}
	printf("%d",ans);
	return 0;
}

