#include <stdio.h>
#include <limits.h>
#define min(A,B) ((A)<(B)?(A):(B))
#define INF (0x3fffffff)
void test(void);
void solve(void);
int i,j,n,mini=0;
int dp[3001]={},a[3000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
void solve(void){
	mini=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
		dp[i]=INF;
	}
	dp[0]=a[0];
	dp[1]=INT_MIN;
	for(i=1;i<n;++i){
		for(j=i;j>mini;--j){
			dp[j+1]=min(dp[j+1],dp[j]+1);
			if(a[i]>dp[j]){
				dp[j]=a[i];
			}else{
				dp[j]=INF;
			}
		}
		dp[j+1]=min(dp[j+1],dp[j]+1);
		if(a[i]>dp[j]){
			dp[j]=a[i];
		}else{
			++mini;
		}
	}
	printf("%d\n",mini);
}
void test(void){
	printf("%d:\n",i);
	for(j=mini;j<=i+1;++j){
		printf("dp[%d]=%d\n",j,dp[j]);
	}
	getchar();
}
