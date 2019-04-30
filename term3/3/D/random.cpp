#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define people (100)
#define length (198)
int main(){
	srand(time(NULL));
	char name[100][200];
	int group[100];
	int i,j;
	for(i=0;i<people;++i){
		for(j=0;j<length-1;++j){
			name[i][j]=rand()%26+'a';
		}
		name[i][length-1]='\0';
		group[i]=rand()&3;
	}
	printf("1\n%d\n",people-1);
	for(i=1;i<people;++i){
//		printf("%d\t",i);
		if(group[i]==3||group[i-1]==3){
			continue;
		}
		switch((group[i]-group[i-1]+3)%3){
			case 0:
				printf("0 %s %s\n",name[i],name[i-1]);
				break;
			case 1:
				printf("1 %s %s\n",name[i],name[i-1]);
				break;
			case 2:
				printf("1 %s %s\n",name[i],name[i-1]);
				break;
			default:
				break;
		}
	}
	for(i=0;i<people;++i){
		if(group[i]==3){
			printf("3 %s\n",name[i]);
		}
	}
	return 0;
}
