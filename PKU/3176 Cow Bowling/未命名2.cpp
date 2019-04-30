#include <stdio.h>

char a[350][350];
int dp[350][350]={};
int main(){
	int i,j,k,
		ans=0,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		for(j=0;j<=i;++j){
			scanf("%d",&a[i][j]);
		}
	}
	dp[0][0]=a[0][0];
	for(i=1;i<n;++i){
		dp[i][0]=dp[i-1][0]+a[i][0];
		for(j=1;j<i;++j){
			dp[i][j]= dp[i-1][j-1]>dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j];
			dp[i][j]+=a[i][j];
		}
		dp[i][i]=dp[i-1][i-1]+a[i][i];
	}
	for(i=0;i<n;++i){
		if(dp[n-1][i]>ans){
			ans=dp[n-1][i];
		}
	}
	printf("%d",ans);
	return 0;
}
