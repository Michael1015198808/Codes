#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#define newx (temp.x+dir[i][0])
#define newy (temp.y+dir[i][1])
using namespace std;
struct point{
				int x,y,t;
				char next;
				int j;
};
int dir[4][2]={
				{1,0},
				{0,1},
				{-1,0},
				{0,-1}};

map <pair<int,int>,int> dic;
char mapc[100][100],visit[100][100][10][1<<5];
unsigned long long ans;
int main(){
	int n,m;
	char c;
	point S;
	queue <point> q;
	while(scanf("%d%d",&n,&m)==2){
	int i,j,k,l=0,cnt_j=0;
		if(n==0&&m==0){
			continue;
		}
		ans=0x7fffffff;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			do{
				c=getchar();
			}while(c=='\n'||c==' ');
			mapc[i][j]=c;
			for(k=0;k<=m;++k){
				for(l=0;l<32;++l){
					visit[i][j][k][l]=false;
				}
			}
			if(c=='S'){
				S.x=i;
				S.y=j;
				S.t=0;
				S.next=0;
				S.j=0;
				visit[i][j][0][0]=true;
			}
			if(c=='J'){
				dic[make_pair(i,j)]=cnt_j++;
			}
		}
	}
	q.push(S);
	while(!q.empty()){
		point temp=q.front();
		q.pop();
		//printf("x%d\ty%d\tn%d\tj%d\tt%d\n",temp.x,temp.y,temp.next,temp.j,temp.t);
		if(temp.t>=ans){
			continue;
		}
		point next;
		for(i=0;i<4;++i){
			if((0<=newx)&&(newx<n)&&(0<=newy)&&(newy<n)){
				if(mapc[newx][newy]!='@'){
					switch(mapc[newx][newy]){
						case 'J':
							if(temp.j&(1<<dic[make_pair(newx,newy)])){
								goto d;
							}
							//printf("J.no%d",dic[make_pair(newx,newy)]);
							//printf("%d %d %d %d\n",newx,newy,temp.next,temp.j|(1<<dic[make_pair(newx,newy)]));
							if(!visit[newx][newy][temp.next][temp.j|(1<<dic[make_pair(newx,newy)])]){
								next=temp;
								next.j|=1<<dic[make_pair(newx,newy)];
								next.x=newx;
								next.y=newy;
								next.t+=2;
								visit[next.x][next.y][next.next][next.j]=true;
								q.push(next);
							}
							break;
						case 'D':
							if(temp.next==m){
								ans=temp.t+1;
								break;
							}
						case 'S':
						case '.':
d:;
							if(!visit[newx][newy][temp.next][temp.j]){
								next=temp;
								next.x=newx;
								next.y=newy;
								next.t+=1;
								visit[next.x][next.y][next.next][next.j]=true;
								q.push(next);
							}
							break;
						default:
							if(mapc[newx][newy]-'0'==temp.next+1){
							if(!visit[newx][newy][temp.next+1][temp.j]){
								next=temp;
								next.x=newx;
								next.y=newy;
								next.t+=1;
								next.next+=1;
								visit[next.x][next.y][next.next][next.j]=true;
								q.push(next);
							}
							}else{
								goto d;
							}
					}
				}
			}
		}
	}
	if(ans==0x7fffffff){
		puts("gg");
	}else{
		printf("%llu\n",ans);
	}
	}
	return 0;
}
