#include <stdio.h>
#include <stdlib.h>
int n=0,m=0;
char a[100][100];
void dfs(int x,int y);
int main()
{
	int l,r,c,num=0;
	scanf("%d%d",&n,&m);
	for(l=0;l<n;l++){
		for(r=0;r<m;r++){
			a[l][r]=0;
			c=getchar();
			if(c=='W')a[l][r]=1;
			if(c=='\n')r--;
		}
	}
	for(l=0;l<n;l++){
		for(r=0;r<m;r++){
			if(a[l][r]){
				dfs(l,r);
				num++;
			}
		}
	}
	printf("%d",num);
	return 0;
}
void dfs(int x,int y){
	a[x][y]=0;
	int i=0;
	for(i=0;i<9;i++){
		if(0<=(x-1+i/3)&&(x-1+i/3)<n&&0<=(y-1+i%3)&&(y-1+i%3)<m&&a[x-1+i/3][y-1+i%3])dfs(x-1+i/3,y-1+i%3);
	}
}
