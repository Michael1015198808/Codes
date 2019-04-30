#include <stdio.h>
#include <queue>
#define newx (temp.x+dir[i][0])
#define newy (temp.y+dir[i][1])
using std::queue;
struct point{
				int x,y;
};
int dir[4][2]={
				{1,0},
				{0,1},
				{-1,0},
				{0,-1}};

char map[100][100];
unsigned short dis[100][100];
int main(){
	int n,m,i,j,k;
	char c;
	point S,G;
	queue <point> q;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			do{
				c=getchar();
			}while(c=='\n');
			map[i][j]=c;
			dis[i][j]=0x3fff;
			if(c=='S'){
				S.x=i;
				S.y=j;
			}
			if(c=='G'){
				G.x=i;
				G.y=j;
			}
		}
	}
	q.push(S);
	j=-1;
	while(!q.empty()){
		++j;
		k=q.size();
	 	while(k--){
			point temp=q.front();
			q.pop();
			for(i=0;i<4;++i){
				if((0<=newx)&&(newx<n)&&(0<=newy)&&(newy<m)){
					if(map[newx][newy]!='#'){
					if(j+1<dis[newx][newy]){
						point t;
						t.x=newx;
						t.y=newy;
						q.push(t);
						dis[newx][newy]=j+1;
					}
					}
				}
			}
		}
	}
	printf("%d\n",dis[G.x][G.y]);
	return 0;
}
