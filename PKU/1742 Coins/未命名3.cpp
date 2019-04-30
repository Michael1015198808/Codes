#include <stdio.h>
#include <iostream>
using namespace std;
int dp[100001];
int main(){
	int a[100],b[100],
		i,j,k,l,
		n,m,ans;
	while(scanf("%d%d",&n,&m)==2){
		if(n==0){
			break;
		}
		memset(dp,-1,sizeof(dp));
		for(i=0;i<n;++i){
			scanf("%d",a+i);
		}
		for(i=0;i<n;++i){
			scanf("%d",b+i);
		}
		dp[0]=0;
		for(i=0;i<n;++i){
			for(j=0;j<=m;++j){
				if(dp[j]>=0){
					dp[j]=b[i];
				}else if(j<a[i]){
					dp[j]=-1;
				}else if(dp[j-a[i]]>0){
					dp[j]=dp[j-a[i]]-1;
				}else{
					dp[j]=-1;
				}
			}
		}
		ans=0;
		for(i=1;i<=m;++i){
			if(dp[i]>-1){
				++ans;
			}
		}
		printf("%d",ans);
		putchar('\n');
	}
	return 0;
}

