#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int i,j,n;
	srand(time(NULL));
	n=rand()%100+100;
	printf("%d\n",n);
	for(i=0;i<n;++i){
		for(j=0;j<6;++j){
			printf("%d ",rand()%10);
		}
		putchar('\n');
	}
	
	return 0;
}
