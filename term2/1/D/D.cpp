#include <stdio.h>
int main(){
	int x=0,y=1;
	long long ans=0;
	scanf("%d",&x);
	for(y=1;x>1;++y,--x){
		ans+=(x-1)*y;
	}
	ans+=y;
	printf("%lld",ans);
}
