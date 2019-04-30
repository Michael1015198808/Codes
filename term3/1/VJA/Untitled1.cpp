#include <stdio.h>
#include <iostream>
#include <string.h>
#define INF (0xfffffff)
#define min(A,B) ((A)>(B)?(B):(A))
unsigned dp[21][21][21][21]={};
int cherry[21][21]={};

unsigned solve(int,int,int,int);
int main(){
	int n,m,k,time=0;
	int i,j,l,x,y;
	while(scanf("%d%d%d",&n,&m,&k)==3){
		memset(cherry,0,sizeof(cherry));
		for(i=0;i<k;++i){
			scanf("%d%d",&x,&y);
			cherry[x][y]=1;
		}
		for(i=0;i<=n;++i){
			for(j=0;j<=m;++j){
				cherry[i][j]+=cherry[i][j-1]+cherry[i-1][j]-cherry[i-1][j-1];
			}
		}
		for(i=0;i<=n;++i){
			for(j=0;j<=m;++j){
				for(k=0;k<=n;++k){
					for(l=0;l<=m;++l){
						dp[i][j][k][l]=INF;
					}
				}
			}
		}
		std::cout<<"Case "<<++time<<": "<<solve(0,0,n,m)<<std::endl;
	}
	return 0;
}
unsigned solve(int lux,int luy,int rdx,int rdy){
	if(dp[lux][luy][rdx][rdy]!=INF){
		return dp[lux][luy][rdx][rdy];
	}
	int i=cherry[rdx][rdy]-cherry[lux][rdy]-cherry[rdx][luy]+cherry[lux][luy];
	if(i>0){
		if(i==1){
			return dp[lux][luy][rdx][rdy]=0;
		}
	}else{
		return INF;
	}
//	printf("%d\t%d\t%d\t%d\n",lux,luy,rdx,rdy);
	for(i=lux+1;i<rdx;++i){
		dp[lux][luy][rdx][rdy]=min(dp[lux][luy][rdx][rdy],rdy-luy+solve(lux,luy,i,rdy)+solve(i,luy,rdx,rdy));
	}
	for(i=luy+1;i<rdy;++i){
		dp[lux][luy][rdx][rdy]=min(dp[lux][luy][rdx][rdy],rdx-lux+solve(lux,i,rdx,rdy)+solve(lux,luy,rdx,i));
	}
	return dp[lux][luy][rdx][rdy];
}

