#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int n,i;
	srand((int)time(NULL));
	for(i=0;i<10;++i){
		n=rand()%250000+250001;
		printf("%d\n",n);
		while(n--){
			printf("%d\n",rand()%999999999+1);
		}
	}
	putchar('0');
	return 0;
}
