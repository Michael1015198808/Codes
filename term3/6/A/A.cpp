#include <stdio.h>
#include <algorithm>
using std::min;
#define INF 0x3fffffff
#define update(A,B) A=(A)<(B)?(A):(B)
struct{
				int from,to,cost;
}edge[51];
unsigned long long dis[51][51],pre[51][51];
int weight[51];
int main(){
				int n,m,i,j,k,l,w1,w2;
				scanf("%d%d",&n,&m);
				scanf("%d%d",&w1,&w2);
				for(i=1;i<=n;++i){
								scanf("%d",&weight[i]);
								for(j=0;j<=n;++j){
												dis[i][j]=INF;
								}
				}
				weight[0]=min(w1,w2);
				for(i=0;i<m;++i){
								scanf("%d%d%d",&j,&k,&l);
								if(j==0){
												--i;
												--m;
												update(dis[k][0],l*(w1+w2));
								}else{
									edge[i]={j,k,l};
								}
				}
				for(i=0;i<n;++i){
								for(j=0;j<m;++j){
												for(k=0;k<=n;++k){
																if(dis[edge[j].to][edge[j].from]>dis[edge[j].from][k]+edge[j].cost*(weight[edge[j].from]+weight[k])){
																				dis[edge[j].to][edge[j].from]=dis[edge[j].from][k]+edge[j].cost*(weight[edge[j].from]+weight[k]);
																				pre[edge[j].to][edge[j].from]=k;
																}
												}
								}
				}
				unsigned long long ans=INF;
				int path[51];
				scanf("%d",&j);
				for(i=0;i<=n;++i){
								if(dis[j][i]<ans){
												ans=dis[j][i];
												k=i;
								}
				}
				path[0]=j;
				path[1]=k;
				i=1;
				while(path[i]!=0){
								++i;
								path[i]=pre[j][k];
								j=k;k=path[i];
				}
				while(i>=0){
								printf("%d ",path[i--]);
				}
				puts("");
				return 0;
}
