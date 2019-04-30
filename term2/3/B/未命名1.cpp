#include <stdio.h>
int num[1000000]={0};
int main(){
	int partial,i,n,sum,ans;
	while(scanf("%d",&n)==1){
		if(!n){
			break;
		}
		for(i=0;i<n;++i){
			scanf("%d",num+i);
		}
		sum=ans=0;
		partial=1000000000;
		for(i=0;i<n;++i){
			sum+=num[i];
			if(num[i]<0&&sum<partial){
				partial=sum;
			}
		}
		for(i=0;i<n;++i){
			if(partial>=0){
				++ans;
			}
			partial-=num[i];
		}
		printf("%d\n",ans);
	}
}
