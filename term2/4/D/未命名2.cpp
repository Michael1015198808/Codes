#include <stdio.h>
char cat[101][100]={},len[101]={};
int main(){
	cat[0][0]=cat[1][0]=len[0]=len[1]=1;
	int i,j1,j2,k,l;
	for(i=2;i<101;++i){
		for(j1=0;j1<i;++j1){
			j2=i-1-j1;
			for(k=0;k<len[j1];++k){
				for(l=0;l<len[j2];++l){
					cat[i][k+l]+=cat[j1][k]*cat[j2][l];
					cat[i][k+l+1]+=cat[i][k+l]/10;
					cat[i][k+l]=cat[i][k+l]%10;
				}
			}
		}
		for(j1=100;;--j1){
			if(cat[i][j1]){
				len[i]=j1+1;
				break;
			}
		}
	}
	tag:;
	scanf("%d",&i);
	if(i==-1){
		return 0;
	}
	for(j1=len[i]-1;j1>-1;--j1){
		printf("%d",cat[i][j1]);
	}
	printf("\n");
	goto tag;
}
