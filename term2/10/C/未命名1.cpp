#include <stdio.h>
#include <algorithm>
using std::max;
//using std::cout;
//using std::endl;
long a[100000];
int next[100000];
int main(){
	long long ans,temp;
	int i,j,k,n;
	while(scanf("%d",&n)==1&&n){
		if(n==0){
			return 0;
		}
		scanf("%ld",a);
		ans=0;
		next[0]=1;
		for(i=1;i<n;++i){
			next[i]=1;
			scanf("%ld",a+i);
			if(a[i]<=a[i-1]){
				for(j=i-1;a[j]>=a[i]&&j>=0;j-=next[j]){
					temp=((long long)a[j])*(i-j-1+next[j]);
					ans=max(ans,temp);
				}
				next[i]=i-j;
			}
		}
		for(j=i-1;a[j]>0&&j>=0;j-=next[j]){
			temp=((long long)a[j])*(n-j-1+next[j]);
			ans=max(ans,temp);
		}
//		for(i=0;i<n;++i){
//			printf("%d\t",next[i]);
//		}
		printf("%lld\n",ans);
	}
	return 0;
}

