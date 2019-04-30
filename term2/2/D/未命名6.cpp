#include <stdio.h>
#include <windows.h>
#define test(A) for(i=0;i<n;++i){for(j=0;j<m;++j){A}}
char map[200][200];
char tox[200][200];
char toy[200][200];
char findx[200][200][10]={};
char findy[200][200][10]={};
int movex[10];
int movey[10];

void find(int,int,int,int);
int main(){
	int n,m,q;
	int i,j,k;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			while((map[i][j]=getchar())=='\n');
			map[i][j]-='0';
		}
	}
	for(i=0;i<10;++i){
		scanf("%d%d",movex+i,movey+i);
	}
/* 	for(i=0;i<10;++i){
		printf("re%d:%d\t%d\n",i,movex[i],movey[i]);
	}
*/	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
//			printf("i:%d j:%d %d x%d %d y%d %d\n",i,j,map[i][j],movex[map[i][j]],i+movex[map[i][j]],movey[map[i][j]],j+movey[map[i][j]]);
//			system("pause");
			if(-1<(i+movex[map[i][j]])&&i+movex[map[i][j]]<n&&-1<j+movey[map[i][j]]&&j+movey[map[i][j]]<m){
				tox[i][j]=i+movex[map[i][j]];
				toy[i][j]=j+movey[map[i][j]];
			}else{
				tox[i][j]=i;
				toy[i][j]=j;
			}
//			printf("(%d,%d) ",tox[i][j],toy[i][j]);
		}
//		printf("\n");
	}
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			for(k=0;k<10;++k){
				if(!findx[i][j][k]){
					find(i,j,k,m*n);
				}
			}
		}
	}
	test(printf("(%d,%d)\n",findx[i][j][8],findy[i][j][8]);)
	return 0;
}
void find(int a,int b,int c,int timer){
	int x=tox[a][b];
	int y=toy[a][b];
	if(map[x][y]!=c){
		if(timer){
			find(x,y,c,timer-1);
			findx[a][b][c]=findx[x][y][c];
			findy[a][b][c]=findy[x][y][c];
		}else{
			findx[a][b][c]=-1;
			findy[a][b][c]=-1;
		}
	}else{
		findx[a][b][c]=x;
		findy[a][b][c]=y;
	}
}

