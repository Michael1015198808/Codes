#include<stdio.h>
#include <stdlib.h>
int main(){
	int n=0,m=0,x=0,y=0;
	long long tem=0,k;
	scanf("%d %d",&n,&m);
	int (*a)[m]=malloc(sizeof(int[n][m]));
	for(x=0;x<n;x++){
		for(y=0;y<m;y++)scanf("%d",&a[x][y]);
	}
	for(x=0;x<n-3;x++){
		for(y=0;y<m;y++){
			k=a[x][y]*a[x+1][y]*a[x+2][y]*a[x+3][y];
			if(k>tem)tem=k;
		}
	}
	for(x=0;x<n;x++){
		for(y=0;y<m-3;y++){
			k=a[x][y]*a[x][y+1]*a[x][y+2]*a[x][y+3];
			if(k>tem)tem=k;
		}
	}
	for(x=0;x<n-3;x++){
		for(y=0;y<m-3;y++){
			k=a[x][y]*a[x+1][y+1]*a[x+2][y+2]*a[x+3][y+3];
			if(k>tem)tem=k;
		}
	}
	for(x=3;x<n;x++){
		for(y=0;y<m-3;y++){
			k=a[x][y]*a[x-1][y+1]*a[x-2][y+2]*a[x-3][y+3];
			if(k>tem)tem=k;
		}
	}
	printf("%d",tem);
	return 0;
}
