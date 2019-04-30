#include <stdio.h>
int num[3000]={0};
int sum[1002]={0};
int main(){
	int n,m,flag,i,j,k,tem;
	while(scanf("%d%d",&n,&m)==2){
		flag=0;
		for(i=0;i<n;++i){
			scanf("%d",num+i);
		}
		for(i=0;i<n;++i){
			for(j=i+1;j<n;++j){
				tem=num[i]+num[j];
				for(k=flag;k>0;--k){
					sum[k]=sum[k-1];
					if(tem<sum[k]){
						break;
					}
				}
				sum[k]=tem;
				if(flag<1000){
					++flag;
				}
//				printf("%d\t%d\t%d\n",num[i],num[j],tem);
//				printf("%d\t%d\t%d\t%d\n\n",sum[0],sum[1],sum[2],sum[3]);
//				getchar();
			}
		}
		for(i=0;i<m-1;++i){
			printf("%d ",sum[i]);
		}
		printf("%d",sum[i]); 
		printf("\n");
	}
		return 0;
}

