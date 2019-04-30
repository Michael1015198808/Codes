#include <stdio.h>

int main(){
	int i,j,k,
		a,b,c,
		n,s;
	long long ans=0;
	scanf("%d%d",&n,&s);
	a=5000;
	for(i=0;i<n;++i){
		scanf("%d%d",&b,&c);
		if(b<a){
			a=b;
		}
		ans+=c*a;
		a+=s;
	}
	printf("%lld",ans);
	putchar('\n');
	return 0;
}

