#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;
char DNA[100][101];
int get_dis(int a,int b){
				int cnt=0,i=0;
				while(DNA[a][i]!='\0'){
								cnt+=(DNA[a][i]!=DNA[b][i]);
								++i;
				}
				return cnt;
}
int dijkstra(int,int);
int path[100][100],dis[100];
int main(){
	int i,j,k,n,m;
	scanf("%d",&n);
	rep(i,0,n){
					scanf("%s",DNA[i]);
	}
	rep(i,0,n){
					rep(j,i,n){
									int temp=get_dis(i,j);
									temp*=temp;
									path[i][j]=path[j][i]=temp;
					}
	}
	rep(k,0,n){
					rep(i,0,n){
									rep(j,0,n){
													update(path[i][j],path[i][k]+path[k][j]);
									}
					}
	}
	int ans=INF;
	rep(i,0,n){
					int temp_ans=0;
					rep(j,0,n){
									temp_ans=max(temp_ans,path[i][j]);
					}
					update(ans,temp_ans);
	}
	printf("%d",ans);
	return 0;
}
