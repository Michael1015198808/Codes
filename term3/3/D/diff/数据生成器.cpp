#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define people 10
//The first two lines are
//1
//22000
//And I manually add them.
//So do not care.
int main(){
				srand(time(NULL));
				char name[1000][20];
				int group[1000];
				int a[1000]={};
				int i,j,k,cnt=0;
tag:;
				for(i=0;i<people;++i){
								name[i][0]=i+'a';
								name[i][1]='\0';
								group[i]=rand()%3;
//								printf("%d\n",group[i]);
				}
				for(i=0;i<people;++i){
								for(j=i+1;j<people;++j){
												if(!strcmp(name[i],name[j])){
																				goto tag;
																				}
																				}
																				}
				printf("1\n22\n");
				for(i=0;i<20;++i){
												j=rand()%people;
												k=rand()%people;
												if(a[j]==1&&a[k]==1){
																++cnt;
								switch((group[j]-group[k]+3)%3){
								case 0:
									printf("1 %s %s\n",name[j],name[k]);
									break;
								case 1:
									printf("0 %s %s\n",name[j],name[k]);
									break;
								case 2:
									printf("0 %s %s\n",name[k],name[j]);
									break;
												}}else{
								switch((group[j]-group[k]+3)%3){
								case 0:
									printf("0 %s %s\n",name[j],name[k]);
									break;
								case 1:
									printf("1 %s %s\n",name[j],name[k]);
									break;
								case 2:
									printf("1 %s %s\n",name[k],name[j]);
									break;
								}
								a[j]=a[k]=1;}
								if(i%10==5){
												do{
												j=rand()%people;
												}while(a[j]==0);
												printf("2 %s\n",name[j]);
												a[j]=0;
												group[j]=rand()%3;
								}
				}
				//This is the number of false statements.
				//I remove them manually.
				//So do no care.
				return 0;
}
