#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,j,p,q,flag;
	scanf("%d",&p);
    int a[p-1];
    for (i=0;i<=p-1;i++){
		scanf("%d",&a[i]);
	}
    scanf("%d",&q);
    int b[q-1];
	for (j=0;j<=q-1;j++){
    	scanf("%d",&b[j]);
	}


	for (i=0;i<=p-1;i++){
		for(j=0;j<=q-1;j++){
			if (a[i]==b[j]) printf("%d ",a[i]);
		}
	}
	printf("\n");
/**¡É**/

	for (i=0;i<=p-1;i++){
	printf("%d ",a[i]);
    }
	for (i=0,flag=1;i<=q-1;i++,flag=1){
		for(j=0;j<=p-1;j++){
			if (a[j]==b[i]){flag=0;}
		}
		if(flag==1){printf("%d ",b[i]);}
	}
	printf("\n");
/**¡È**/

	for (i=0,flag=1;i<=p-1;i++,flag=1){
		for(j=0;j<=q-1;j++){
			if (a[i]==b[j]){flag=0;}
		}
		if(flag==1){printf("%d ",a[i]);}
	}
	printf("\n");
/**-**/

	for (i=0,flag=0;i<=p-1;i++){
		for(j=0;j<=q-1;j++){
			if (a[i]==b[j]){flag++;}
		}
	}
	if(flag==i){printf("true");}else{printf("false");}
	return 0;
}
