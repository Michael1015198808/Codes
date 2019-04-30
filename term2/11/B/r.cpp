#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int a,b,c,i,j,k;
	srand(time(NULL)); 
	a=rand()%3+2;
	printf("%d\n",a);
	for(i=0;i<a;++i){
		b=rand()%1000+1;
		c=rand()%2000+1;
		printf("%d %d\n",b,c);
		for(j=0;j<b;++j){
			for(k=0;k<c;++k){
				printf("%d ",rand()%10000+1);
			}
			putchar('\n');
			putchar('\n');
			putchar('\n');
			putchar('\n');
			putchar('\n');
		}
	}
	return 0;
}

