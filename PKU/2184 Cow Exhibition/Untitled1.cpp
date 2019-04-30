#include <stdio.h>
#include <algorithm>
using std::max;
int smartness[200005];
int main(){
	int* dp=smartness+100001;
	int i,j,k,n,s,f,ans=0;
	scanf("%d",&n);
	for(i=0;i<200005;++i){
		smartness[i]=-10000000;
	}
	dp[0]=0;
	for(i=0;i<n;++i){
		scanf("%d%d",&s,&f);
		if(s>=0){
			for(j=100000;j>s-100000;--j){
				dp[j]=max(dp[j],dp[j-s]+f);
			}
		}else if(f>0){
			for(j=-100000;j<100000+s;++j){
				dp[j]=max(dp[j],dp[j-s]+f);
			}
		}
	}
	for(i=0,ans=0;i<100000;++i){
		if(dp[i]>0){
			ans=max(ans,dp[i]+i);
		}
	}
	printf("%d\n",ans);
	return 0;
}

