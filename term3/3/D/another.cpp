#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
				int i,j,k;
				srand(time(NULL));
				printf("1\n100000\n");
				for(i=0;i<100000;++i){
						j=rand()&3;
						if(j>1){
										printf("%d %c\n",j,rand()%26+'a');
						}else{
										printf("%d %c %c\n",j,rand()%26+'a',rand()%26+'a');
						}
				}
				return 0;
}
