#include<stdio.h>
#include <stdlib.h>
sort(int a[],int head,int tail);
int main(){
	int n,j;
	scanf("%d",&n);
	int a[n];
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
	sort(a,0,n-1);
	return 0;
}

sort(int a[],int x,int y){
	int i=0;
	for(i=y;i>x;i--){
		if(a[i]>a[i-1]){
			  a[i]=a[i]^a[i-1];
			a[i-1]=a[i]^a[i-1];
			  a[i]=a[i]^a[i-1];
		}
	}
	for(i=0;i<=y;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	if(x<y-1)sort(a,x+1,y);
}
