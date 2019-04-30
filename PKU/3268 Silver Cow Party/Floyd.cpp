#include <stdio.h>
#include <vector>
#include <queue>
#define INF 2000000

using namespace std;
typedef pair<int,int> P;
int dp[1001][1001];
bool test[1001]={};
priority_queue<P,vector<P>,greater<P> > q;
int main(){
	int i,j,k,n,m,x,a,b,c,max=0;
	scanf("%d%d%d",&n,&m,&x);
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			dp[i][j]=INF;
		}
		dp[i][i]=0;
	}
	for(i=0;i<m;++i){
		scanf("%d%d%d",&a,&b,&c);
		if(dp[a][b]>c){
			dp[a][b]=c;
		}
	}
	for(i=1;i<=n;++i){
		if(i==x){
			continue;
		}
		q.push(P(dp[x][i],i));
	}
	while(!q.empty()){
		P temp=q.top();
		q.pop();
		i=temp.second;
		if(test[i]){
			continue;
		}
		test[i]=true;
		for(j=1;j<=n;++j){
			if(i!=x&&dp[x][i]+dp[i][j]<dp[x][j]){
				dp[x][j]=dp[x][i]+dp[i][j];
				q.push(P(dp[x][j],j));
			}
		}
	}
//	putchar('t');
	for(i=1;i<=n;++i){
		if(i==x){
			continue;
		}
		q.push(P(dp[i][x],i));
	}
	while(!q.empty()){
		P temp=q.top();
		q.pop();
		i=temp.second;
		if(!test[i]){
			continue;
		}
//		printf("%d %d\n",temp.first,temp.second);
		test[i]=false;
		for(j=1;j<=n;++j){
			if(dp[j][i]+dp[i][x]<dp[j][x]){
				dp[j][x]=dp[j][i]+dp[i][x];
				q.push(P(dp[j][x],j));
			}
		}
	}
	for(i=1;i<=n;++i){
		if(dp[i][x]+dp[x][i]>max){
			max=dp[i][x]+dp[x][i];
		}
	}
	printf("%d",max);
	return 0;
}

