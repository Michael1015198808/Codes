#include <stdio.h>
#include <stdlib.h>
#include<iostream>
int main() {
	bool a[127];
	int i=0,j,n,y,m;
	while((a[i]=getchar())!=EOF&&a[i]!='\n'){
	i++;}
	/*for input*/
	
	for(j=97;j<=122;j++,y=0){
	for(n=0;n<=i;n++){
		if(a[n]==j){
			if(y==0){
				y=1;
			}else{
					i--;
					for(m=n;m<=i;m++){
						a[m]=a[m+1];
					}
					n--;
				}
		}
	}
}
	/*for deleting*/
	
	for(j=0;j<i;j++){
	putchar(a[j]);}
	return 0;
}
/*a97~z122*/
