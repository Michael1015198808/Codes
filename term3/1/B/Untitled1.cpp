#include <stdio.h>
#define INF (0x7FFFFFFF)
#define min(A,B) ((A)<(B)?(A):(B))
#define DEBUG
#undef DEBUG
unsigned len[17][17];
unsigned dp[1<<16][17];
unsigned path[17];
int main(){
	int n,temp,goal=0;
	int i,j,k,loop,ans=INF,final=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&temp);
		goal|=((bool)temp)<<i;
	}
	for(i=0;i<=n;++i){
		for(j=0;j<=n;++j){
			scanf("%d",&(len[i][j]));
		}
	}
	for(i=0;i<(1<<n);++i){
		for(j=0;j<=n;++j){
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n;++i){
		dp[1<<(i-1)][i]=len[0][i];
	}
	for(loop=1;loop<n;++loop){
		int comb=(1<<loop)-1;
		while(comb<1<<n){
			for(j=1;j<=n;++j){
				if((1<<(j-1))&comb){
					for(k=1;k<=n;++k){
						dp[comb|(1<<(k-1))][k]=min(dp[comb|(1<<(k-1))][k],dp[comb][j]+len[j][k]);
					}
				}
			}
			int x=comb&-comb, y=comb+x;
			comb=((comb&~y)/x>>1)|y;
		}
	}
	for(i=1;i<=n;++i){
		if(ans>dp[goal][i]){
			final=i;
			ans=dp[goal][i];
		}
	}
	printf("%d\n",ans);
	j=n;
	path[--j]=final;
	//ans	the minimum time cost
	//final	the last point
	goal^=(1<<(final-1));
	while(goal){
		for(i=1;i<=n;++i){
			if(ans==dp[goal][i]+len[i][final]){
				path[--j]=i;
				ans=dp[goal][i];
				final=i;
				goal^=1<<(final-1);
			}
		}
	}
	for(;j<n;++j){
		printf("%d ",path[j]);
	}
	putchar('\n');
	return 0;
}
