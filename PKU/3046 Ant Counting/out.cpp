#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void output(void);
int main(){
	int i;
	srand(time(NULL));
	for(i=0;i<5;++i){
		output();
	}
}
void output(void){
	int i,j,k,l;
	i=rand()%190+10;
	j=rand()%1000000;
	do{
	k=rand()%j;
	l=rand()%j;
	}while(k>l);
	printf("%d %d %d %d\n",i,j,k,l);
	while(j--){
		printf("%d\n",rand()%i+1);
	}
	return;
}

