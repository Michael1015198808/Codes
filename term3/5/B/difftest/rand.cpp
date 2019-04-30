#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define width (100)
int main(){
				srand(time(NULL));
				int cases=5;
				while(cases--){
				char map[width][width];
				int i,j;
				char c;
				for(i=0;i<width;++i){
								for(j=0;j<width;++j){
												switch(rand()&7){
																case 0:
																				c='@';
																				break;
																case 1:
																				c=rand()%9+'1';
																				break;
																default:
																				c='.';
												}
												map[i][j]=c;
								}
				}
				int a=rand()%width,b=rand()%width;
				int d,e;
				do{
								d=rand()%width;
								e=rand()%width;
				}while(a==d&&b==e);
				map[a][b]='D';
				map[d][e]='S';
				printf("%d %d\n",width,(rand()&7)+2);
				for(i=0;i<width;++i){
								for(j=0;j<width;++j){
												putchar(map[i][j]);
								}
								putchar('\n');
				}
				}
				return 0;
}
