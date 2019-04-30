#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,j;
    	char a[64],b[64];
    for (i=0;a[i-1]>-1;i++){
		scanf("%d",&a[i]);
	}
    for (i=0;b[i-1]>-1;i++){
    	scanf("%d",&b[i]);
	}

	for (i=0;a[i]>-1;i++){
		for(j=0;b[j]>-1;j++){
			if (a[i]==b[j]) printf("%d ",a[i]);
		}
	}
	printf("\n");


	for (i=0;a[i]>-1;i++){
	printf("%d ",a[i]);
    }
	for (i=0;b[i]>-1;i++){
		for(j=0;a[j/65]>-1;j=j+65){
			if (a[j/65]==b[i]){j++;}
		}
		if(j==j/65*65){printf("%d ",b[i]);}
	}
	printf("\n");


	for (i=0;a[i]>-1;i++){
		for(j=0;b[j/65]>-1;j=j+65){
			if (a[i]==b[j/65]){j++;}
		}
		if(j==j/65*65){printf("%d ",a[i]);}
	}
	printf("\n");


	for (i=0;a[i/65]>-1;i=i+65){
		for(j=0;b[j]>-1;j++){
			if (a[i/65]==b[j]){i++;}
		}
	}
	if(i==i/65*66){printf("true");}else{printf("false");}
	return 0;
}
