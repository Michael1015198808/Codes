#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define print_map  		rep(i,0,n){\
						rep(j,0,n){\
										if(path[i][j][0]==INF){\
														printf("INF ");\
										}else\
										printf("%3d ",path[i][j][0]);\
						}\
						puts("");\
		}\
		puts("");\
		rep(i,0,n){\
						rep(j,0,n){\
										if(path[i][j][1]==INF){\
														printf("INF ");\
										}else\
										printf("%3d ",path[i][j][1]);\
						}\
						puts("");\
		}\
		puts("");
 
#define INF 50000
using namespace std;
unsigned int path[100][100][2];
int has_door[100],has_wing[100];
int dis[100];
int main(){
    int i,j,k,l,n,m1,m2,door,total;
    scanf("%d%d%d",&n,&m1,&m2);
    rep(i,0,n){
                    rep(j,0,n){
                                    path[i][j][0]=path[i][j][1]=INF;
                    }
										path[i][i][0]=path[i][i][1]=0;
    }
    scanf("%d%d",&door,&total);
    rep(i,0,door){
                    scanf("%d",&j);
                    has_door[i]=j-1;
    }
    rep(i,0,door){
                    scanf("%d",&j);
                    has_wing[i]=j-1;
    }
    rep(i,0,m1){
                    scanf("%d%d%d",&j,&k,&l);
                    update(path[j-1][k-1][0],l);
    }
    rep(i,0,m2){
                    scanf("%d%d%d",&j,&k,&l);
                    update(path[j-1][k-1][1],l);
    }
  	rep(k,0,n){
                    rep(i,0,n){
                                    rep(j,0,n){
                                                    update(path[i][j][0],path[i][k][0]+path[k][j][0]);
                                                    update(path[i][j][1],path[i][k][1]+path[k][j][1]);
                                    }
                    }
    }
    rep(i,0,door){
                    dis[i]=path[0][has_door[i]][0]+path[has_door[i]][has_wing[i]][1];
    }
    sort(dis,dis+door);
    int ans=0;
    rep(i,0,total){
                    if(dis[i]>INF){
                                    puts("-1");
                                    return 0;
                    }
                    ans+=dis[i];
    }
    printf("%d\n",ans);
    return 0;
}
