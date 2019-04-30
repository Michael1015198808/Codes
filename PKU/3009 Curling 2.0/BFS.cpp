#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int field[21][21];
bool test[20][20];
int dp[20][20];
int main(){
	int i,j,k,width,height,sx,sy,gx,gy;
	queue<P> a;
	while(scanf("%d%d",&width,&height)==2){
		if(width==0){
			break;
		}
		for(i=0;i<height;++i){
			for(j=0;j<width;++j){
				scanf("%d",&(field[i][j]));
				if(field[i][j]>1){
					if(field[i][j]==2){
						sx=i;
						sy=j;
					}else{
						gx=i;
						gy=j;
					}
				}
			}
		}
		for(i=0;i<height;++i){
			for(j=0;j<width;++j){
				test[i][j]=false;
				dp[i][j]=11;
			}
		}
		while(!a.empty()){
			a.pop();
		}
		a.push(make_pair(sx,sy));
		dp[sx][sy]=0;
		field[sx][sy]=0;
		P now;
//		printf("%d %d->%d %d\n",sx,sy,gx,gy);
		do{
			now=a.front();
			int x=now.first,y=now.second;
			a.pop();
//			printf("%d:%d,%d\n",dp[x][y],x,y);
//down
			while(field[x+1][y]==0&&x<height){
				++x;
			}
			if(gx==x+1&&gy==y){
				if(dp[gx][gy]>dp[now.first][now.second]+1){
					dp[gx][gy]=dp[now.first][now.second]+1;
				}
			}else
			if(x<height&&dp[x][y]>dp[now.first][y]+1){
				dp[x][y]=dp[now.first][y]+1;
				a.push(P(x,y));
			}
//right
			x=now.first;
			while(field[x][y+1]==0&&y<width){
				++y;
			}
			if(gx==x&&gy==y+1){
				if(dp[gx][gy]>dp[now.first][now.second]+1){
					dp[gx][gy]=dp[now.first][now.second]+1;
				}
			}else
			if(y<width&&dp[x][y]>dp[x][now.second]+1){
				dp[x][y]=dp[x][now.second]+1;
				a.push(P(x,y));
			}
//up
			y=now.second;
			while(field[x-1][y]==0&&x>0){
				--x;
			}
			if(gx==x-1&&gy==y){
				if(dp[gx][gy]>dp[now.first][now.second]+1){
					dp[gx][gy]=dp[now.first][now.second]+1;
				}
			}else
			if(x>0&&dp[x][y]>dp[now.first][y]+1){
				dp[x][y]=dp[now.first][y]+1;
				a.push(P(x,y));
			}
//left
			x=now.first;
			while(field[x][y-1]==0&&y>0){
				--y;
			}
			if(gx==x&&gy==y-1){
				if(dp[gx][gy]>dp[now.first][now.second]+1){
					dp[gx][gy]=dp[now.first][now.second]+1;
				}
			}else
			if((y>0&&dp[x][y]>dp[x][now.second]+1)){
				dp[x][y]=dp[x][now.second]+1;
				a.push(P(x,y));
			}
//			printf("%d %d\n",x,y);
		}while((dp[now.first][now.second]<dp[gx][gy])&&!(a.empty()));
		if(dp[gx][gy]<11){
			printf("%d\n",dp[gx][gy]);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}

