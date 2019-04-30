#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,c,e,a[50],b[50];
	for(i=0;i<=49;i++){
		a[i]=b[i]=0;
	}
	while((scanf("%d",&c))!=-1){
		e=1;
		for(i=0;i<=49&&e==1;i++){
			if(c==a[i]){b[i]++;e=0;}}
		if (e==1)
			for(i=0;i<=49;i++){
				if (b[i]==0){a[i]=c;b[i]++;e=0;}} 
	}
	for(e=49;e>=0;e--){
	for(i=0;i<e;i++){if(a[i]<a[i+1]){
		c=a[i+1];a[i+1]=a[i];a[i]=c;
		c=b[i+1];b[i+1]=b[i];b[i]=c;}}}
	printf("N    Count\n");
	for(i=0;i<=49;i++){
		if(b[i]>0)
		printf("%d    %d\n",a[i],b[i]);
	}
	return 0;
}
