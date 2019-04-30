#include <stdio.h>
#include <algorithm>
#include <algorithm>
using namespace std;
struct town{
	int  cow,no;
	bool operator<(const town ano)const{
		return cow<ano.cow;
	}
};
long long dp[60001]={},p;
bool flag[181];
town a[181];
int main(){
	int n,m,ans,n3,record,
		i,j,k;
	scanf("%d",&n);
	n3=3*n;
	m=n*500;
	for(i=0;i<n3;++i){
		scanf("%d",&(a[i].cow));
		a[i].no=i+1;
	}
	sort(a,a+n3);
	for(i=0;i<n;++i){
		printf("%d",a[i].no);
		putchar('\n');
	}
	ans=0;
	i=n;
	dp[0]=1;
	for(i=n;i<n3;++i){
		for(j=m<<1;j>=a[i].cow;--j){
			if(dp[j-a[i].cow]){
				dp[j]|=(dp[j-a[i].cow]<<1);
			}
		}
	}
	for(i=n;i<n3;++i){
		flag[i]=true;
	}
	for(i=0,p=1;i<n;++i){
		p<<=1;
	}
	for(i=m+1;;++i){
		if(dp[i]&p){
//			record=i;
			break;
		}
	}
	p>>=1;
	for(j=n;j<n3;++j){
		if(i-a[j].cow>=0){
			if(dp[i-a[j].cow]&p){
				p>>=1;
				flag[j]=false;
				printf("%d",a[j].no);
				putchar('\n');
				i-=a[j].cow;
			}
		}
	}
	for(i=n;i<n3;++i){
		if(flag[i]){
			printf("%d",a[i].no);
			putchar('\n');
		}
	}
//	printf("\n%d",record);
	return 0;
}

