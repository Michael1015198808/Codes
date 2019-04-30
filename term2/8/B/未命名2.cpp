#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

long A[500][500],B[500][500],tempa[2][500],tempb[2][500],C[500][500];
int main(){
	int i,j,k,n,sum[2],x,y;
	scanf("%d",&n);
	memset(tempa,0,sizeof(tempa));
	memset(tempa,0,sizeof(tempb));
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%ld",&A[i][j]);
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			tempa[0][j]+=A[i][j];
			tempa[1][j]+=A[i][j]*i;
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%ld",&B[i][j]);
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			tempb[0][j]+=tempa[0][i]*B[i][j];
			tempb[1][j]+=tempa[1][i]*B[i][j];
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%ld",&C[i][j]);
		}
	}
	for(i=0;i<n;++i){
		sum[0]=sum[1]=0;
		for(j=0;j<n;++j){
			sum[0]+=C[j][i];
			sum[1]+=C[j][i]*j;
		}
		if((sum[0]!=tempb[0][i])||(sum[1]!=tempb[1][i])){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}

