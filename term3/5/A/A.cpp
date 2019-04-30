#include <stdio.h>
#define in (0<x+dir[i][0]&&x+dir[i][0]<=height&&0<y+dir[i][1]&&y+dir[i][1]<=width)
#define stone (field[x+dir[i][0]][y+dir[i][1]]==1)
void dfs(int,int,int);
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int field[21][21];
int ans,width,height,sx,sy,gx,gy;
int main(){
	int i,j;
	while(scanf("%d%d",&width,&height)==2){
		if(width==0){
			break;
		}
		ans=11;
		for(i=1;i<=height;++i){
			for(j=1;j<=width;++j){
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
		dfs(sx,sy,0);
		if(ans==11){
						printf("-1\n");
		}else{
						printf("%d\n",ans);
		}
	}
	return 0;
}
void dfs(int ori_x,int ori_y,int time){
		if(time==ans){
			return;
		}
		if(ori_x==gx&&ori_y==gy){
			ans=time;
			return;
		}
		++time;
		int i;
		int x=ori_x,y=ori_y;
		for(i=0;i<4;++i){
			if(in){
				if(!stone){
					while(in){
						if(stone){
							field[x+dir[i][0]][y+dir[i][1]]=0;
							//printf("(%d,%d)->(%d,%d)%d\n",ori_x,ori_y,x,y,field[5][6]);
							dfs(x,y,time);
							field[x+dir[i][0]][y+dir[i][1]]=1;
							break;
						}
						x+=dir[i][0];
						y+=dir[i][1];
						if(x==gx&&y==gy){
							ans=time;
							return;
						}
					}
					x=ori_x,y=ori_y;
				}
			}
		}
		return;
}
