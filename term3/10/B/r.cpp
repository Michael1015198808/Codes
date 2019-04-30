#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
				srand(time(NULL));
				int r,c,i,j;
				r=rand()%40+1;
				c=rand()%10+1;
				putchar('1');
				putchar('\n');
				printf("%d %d\n",r,c);
				for(i=0;i<r;++i){
								for(j=0;j<c;++j){
												putchar(rand()&1?'*':'o');
								}
								putchar('\n');
				}
				return 0;
}
