#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int i,j,k;
	putchar('1');
	putchar('\n');
	i=rand()%10+1;
	j=rand()%10+1;
	printf("%d %d",i,j);
	putchar('\n');
	while(j--){
		printf("%d ",rand()%i+1);
	}
}

