#include <stdio.h>

int main(){
	int n,k,m,i,temp;
	while(scanf("%d",&n)&&n){
		scanf("%d%d",&k,&m);
		i=1,temp=0;
		while(++i<n){
			temp=(temp+k)%i;
		}
		printf("%d\n",(temp+m)%n+1);
	}
	return 0;
}
