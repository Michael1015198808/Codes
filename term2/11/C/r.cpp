#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int i,n,m;
	n=rand()%3000+1;
	do{
		m=rand()%1000+1;
	}while(m>n);
	printf("%d %d\n",n,m);
	for(i=0;i<n;++i){
		printf("%d ",rand()%5000+1);
	}
	
	return 0;
}

