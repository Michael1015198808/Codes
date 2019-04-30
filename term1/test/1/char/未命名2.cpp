#include <stdio.h>
#include <stdlib.h>
char input(void);
int main()
{
	int numbers=0,i=0,j=0,num=0;
	char ball[3000],o=0;
	for(i=0;i<3000;i++)ball[i]=0;
	for(scanf("%d",&numbers);numbers>0;numbers--){
		o=input();
		if(o=='P'){
			for(i=0;i<num;i++){
				printf("%c",ball[i]);
			}
			printf("\n");
		}
		if(o=='A'){
			scanf("%d",&i);
			for(j=num;j>i;j--){
				ball[j]=ball[j-1];
			}
			ball[i]=input();
			num++;
		}
		if(o=='D'){
			scanf("%d",&i);
			for(j=i;j<num;j++){
				ball[j]=ball[j+1];
			}
			ball[num]=0;
			num--;
		}
		if(o=='S'){
			scanf("%d%d",&i,&j);
			if(i!=j){
				ball[i]=ball[i]^ball[j];
				ball[j]=ball[i]^ball[j];
				ball[i]=ball[i]^ball[j];
			}
		}
	}
	return 0;
}
char input(void){
	char o;
	while((o=getchar())&&(o==' '||o=='\n'));
	return o;
}
