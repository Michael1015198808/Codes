#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int n1,n2,n,i;
	srand((int)time(NULL));
	n1=rand()%9+1;
	n2=rand()%9+1;
	n=1+n1+n2+rand()%(5000000-n1-n2);
	printf("%d %d %d\n",n1,n2,n);
	for(i=0;i<n;++i){
		printf("%d ",rand()%100000000+1);
	}
	n1=rand()%9+1;
	n2=rand()%9+1;
	n=1+n1+n2+rand()%(5000000-n1-n2);
	printf("\n%d %d %d\n",n1,n2,n);
	for(i=0;i<n;++i){
		printf("%d ",rand()%100000000+1);
	}
	printf("\n0 0 0");
	return 0;
}

