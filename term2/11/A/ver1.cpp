#include <stdio.h>
#include <iostream>
int dpsmall[11],dpbig[11];
int main(){
	int i,j,k,n1,n2,n,score;
	double sum;
	while(scanf("%d%d%d",&n1,&n2,&n)==3){
		if(n==0){
			break;
		}
		for(i=0;i<n2;++i){
			dpsmall[i]=100000000;
		}
		memset(dpbig,0,sizeof(dpbig));
		sum=0;
		for(i=0;i<n;++i){
			scanf("%d",&score);
			sum+=score;
			for(j=0;j<n1;++j){
				if(score>dpbig[j]){
					break;
				}
			}
			for(k=n1;k>j;--k){
				dpbig[k]=dpbig[k-1];
			}
			dpbig[j]=score;
			for(j=0;j<n2;++j){
				if(score<dpsmall[j]){
					break;
				}
			}
			for(k=n2;k>j;--k){
				dpsmall[k]=dpsmall[k-1];
			}
			dpsmall[j]=score;
		}
		for(i=0;i<n1;++i){
			sum-=dpbig[i];
		}
		for(i=0;i<n2;++i){
			sum-=dpsmall[i];
		}
		printf("%.6lf\n",sum/(n-n1-n2));
	}
	return 0;
}

