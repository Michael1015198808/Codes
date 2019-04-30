#include <stdio.h>
#include <algorithm>
#define ep (1e-5)
#define eq(a,b) ((a)<(b+ep)&&(a)>(b-ep))
using namespace std;
void solve(void);
void show(void);

double a[13][13];
int n;
int main(){
				int t;
				scanf("%d",&t);
				while(t--){
								solve();
				}
				return 0;
}
void solve(void){
				int m,u,v;
				int i=0,j=0,k=0;
				double pro=1.0;
				scanf("%d%d",&n,&m);
				for(i=1;i<=n;++i){
								for(j=1;j<=n;++j){
												a[i][j]=0.0;
								}
				}
				for(i=0;i<m;++i){
								scanf("%d%d",&u,&v);
								if(eq(a[u][v],0)){
								a[u][v]--;
								a[v][u]--;
								a[u][u]++;
								a[v][v]++;
								}
				}
//a[1][1] to a[12][12]
				for(i=2;i<=n;++i){
								if(eq(a[i][i],0)){
												for(j=i+1;j<=n;++j){
																if(!eq(a[j][i],0)){
																				break;
																}
												}
												if(j>n){
																puts("0");
																return;
												}
												for(k=i;k<=n;++k){
																double temp=a[i][k];
																a[i][k]=a[j][k];
																a[j][k]=temp;
												}
								}
								for(j=i+1;j<=n;++j){
												for(k=i+1;k<=n;++k){
																a[j][k]-=a[i][k]*a[j][i]/a[i][i];
												}
												a[j][i]=0.0;
								}
				}
				for(i=2;i<=n;++i){
								pro*=a[i][i];
				}
				printf("%lld\n",(long long)(pro+0.5));
}
void show(void){
				int i=0,j=0;
				for(i=2;i<=n;++i){
								for(j=2;j<=n;++j){
												printf("%2.3lf\t",a[i][j]);
								}
								puts("\0");
				}
				puts("\n\n\n");
}
