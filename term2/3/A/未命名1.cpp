#include <stdio.h>
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
int main(){
	int n,i,j,k;
	char station[9];
	string O1,O2;
	while(scanf("%d",&n)==1){
		cin>>O1>>O2;
		i=j=k=0;
		while(j<n){
			while(k>0){
				if(station[k-1]==O2[j]){
					--k;
					++j;
				}else{
					break;
				}
			}
			if(i<n&&i-j<9){
				station[k++]=O1[i++];
			}else{
				break;
			}
		}
		if(j!=n){
			printf("No.\n");
		}else{
			printf("Yes.\n");
			i=j=k=0;
			while(j<n){
				while(k>0){
					if(station[k-1]==O2[j]){
						--k;
						++j;
						printf("out\n");
					}else{
						break;
					}
				}
				if(i<n){
					station[k++]=O1[i++];
					printf("in\n");
				}else{
					break;
				}
			}
		}
		printf("FINISH\n");
	}
	return 0;
}
