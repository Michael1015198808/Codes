#include <stdio.h>
#include <cstring>
int dp[2][100001]={},*pre=dp[0],*next=dp[1],*swap;
int main(){
	int i,j,k,temp,
		t,a,s,b,
		n[1001]={};
	while(scanf("%d%d%d%d",&t,&a,&s,&b)==4){
	
	memset(dp,0,sizeof(dp));
	memset(n,0,sizeof(n));
	for(i=0;i<a;++i){
		scanf("%d",&temp);
		++n[temp];
	}
	next[0]=pre[0]=1;
	for(i=1;i<=t;++i){
		for(j=1;j<=n[i];++j){
			next[j]=(next[j-1]+pre[j])%1000000;
		}
		for(j=n[i]+1;j<=b;++j){
			next[j]=(next[j-1]+pre[j]-pre[j-n[i]-1]+1000000)%1000000;
		}
		swap=pre;
		pre=next;
		next=swap;
	}
	for(i=s,temp=0;i<=b;++i){
		temp=(temp+pre[i])%1000000;
	}
	printf("%d\n",temp);
}
	return 0;
}

