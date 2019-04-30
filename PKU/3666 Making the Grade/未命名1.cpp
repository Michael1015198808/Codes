#include <stdio.h>
#include <algorithm>
using std::min;
#define INF 1000000000
long a[2000]={};
long dp[2000][2000]={},ans=INF;
int main(){
	int n,temp,
		i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		dp[0][i]=0;
		for(j=0;j<n;++j){
			dp[i][j]=INF;
		}
	} 
	for(i=0;i<n;++i){
		scanf("%ld",a+i);
	}
	for(i=1;i<n;++i){
		for(j=0;j<i;++j){
			if(a[i]<a[j]){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a[j]-a[i]);
			}else{
				dp[i][i]=min(dp[i][i],dp[i-1][j]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]-a[j]+a[i]);
			}
		}
	}
	for(i=0;i<n;++i){
		ans=min(ans,dp[n-1][i]);
	}

	for(i=1;i<n;++i){
		dp[0][i]=0;
		for(j=0;j<n;++j){
			dp[i][j]=INF;
		}
	} 
	for(i=0;i<(n>>1);++i){
		temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
	for(i=1;i<n;++i){
		for(j=0;j<i;++j){
			if(a[i]<a[j]){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a[j]-a[i]);
			}else{
				dp[i][i]=min(dp[i][i],dp[i-1][j]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]-a[j]+a[i]);
			}
		}
	}
	for(i=0;i<n;++i){
		ans=min(ans,dp[n-1][i]);
	}
	printf("%d",ans);
	return 0;
}

