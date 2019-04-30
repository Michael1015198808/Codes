#include <stdio.h>
#include <windows.h>
bool tile[20][20]={0};
int W,H,ans=0;
void dfs(int,int);
int main(){
	int i,j,k,x,y;
	char c;
	while(scanf("%d%d",&W,&H)==2){
		if(W||H){
			ans=0;
			getchar();
			for(i=0;i<H;++i){
				for(j=0;j<W;++j){
					if((c=getchar())=='#'){
						tile[i][j]=0;
					}else{
						tile[i][j]=1;
						if(c=='@'){
							x=i;
							y=j;
						}
					}
				}
				getchar();
			}
/*			for(i=0;i<H;++i){
				for(j=0;j<W;++j){
					printf("%d",tile[i][j]);
				}
				printf("\n");
			}
			printf("%d\t%d\n",x,y);
*/			dfs(x,y);
			printf("%d\n",ans);
		}else{
			break;
		}
	}
	return 0;
}
void dfs(int x,int y){
	int i,j;
/*	for(i=0;i<H;++i){
		for(j=0;j<W;++j){
			printf("%d",tile[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d\t%d\n",x,y);
	system("pause");
*/	++ans;
	tile[x][y]=0;
	if(tile[x+1][y]&&x+1<H){
		dfs(x+1,y);
	}
	if(tile[x-1][y]&&x>0){
		dfs(x-1,y);
	}
	if(tile[x][y+1]&&y+1<W){
		dfs(x,y+1);
	}
	if(tile[x][y-1]&&y>0){
		dfs(x,y-1);
	}
	return;
}
