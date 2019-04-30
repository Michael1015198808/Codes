#include <stdio.h>
#include <queue>
#include <string>
using std::queue;
struct point{
	int x,y,t;
};
queue <point> a;
int map[302][302]={};
const int direcx[4]={1,0,-1,0};
const int direcy[4]={0,1,0,-1};
int main(){
	int m,x,y,t,
		nx,ny,
		i,j,k;
	point pre,next;
	scanf("%d",&m);
	for(i=0;i<302;++i){
		for(j=0;j<302;++j){
			map[i][j]=-1;
		}
	}
	for(i=0;i<m;++i){
		scanf("%d%d%d",&x,&y,&t);
		if(map[x][y]==-1||map[x][y]>t){
			map[x][y]=t;
		}
		for(j=0;j<4;++j){
			nx=x+direcx[j];
			ny=y+direcy[j];
			if(nx>=0&&ny>=0){
				if(map[nx][ny]==-1||map[nx][ny]>t){
					map[nx][ny]=t;
				}
			}
		}
	}
	if(map[0][0]==-1){
		printf("0");
		return 0;
	}
	if(map[0][0]==0){
		printf("-1");
		return 0;
	}
	pre.x=pre.y=pre.t=0;
	a.push(pre);
	while(!a.empty()){
		pre=a.front();
		a.pop();
		next.t=pre.t+1;
		for(i=0;i<4;++i){
			next.x=pre.x+direcx[i];
			if(next.x<0){
				continue;
			}
			next.y=pre.y+direcy[i];
			if(next.y<0){
				continue;
			}
			if(map[next.x][next.y]==-1){
				printf("%d",next.t);
				return 0;
			}
			if(map[next.x][next.y]>next.t){
//				printf("(%d,%d,%d)",next.x,next.y,next.t);
				a.push(next);
				map[next.x][next.y]=next.t;
			}
		}
	}
	printf("-1");
	return 0;
}

