#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	srand((int)time(NULL));
	int n,sum=0,a[181],i;
	tag:;
	n=rand()%50+11;
	for(i=0;i<3*n;++i){
		a[i]=rand()%1000;
		sum+=a[i];
	}
	if(sum<500*n){
		goto tag;
	}else{
		printf("%d",n);
		for(i=0;i<3*n;++i){
			printf("\n%d",a[i]);
		}
	}
	printf("\nLine\n"); 
	return 0;
}
