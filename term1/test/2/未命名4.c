#include<stdio.h>
#include <stdlib.h>
int main(){
	int ceshicishu,i;
	char a[1005];
		a[0]=0;
	for(scanf("%d",&ceshicishu),scanf("%c",&a[0]);ceshicishu>0;ceshicishu--){
		i=1;
		while((a[i]=getchar())!=EOF&&a[i]!='\n'){
				if((a[i]-a[i-1])==(a[i]/80+1)){
					i=i-2;
				}
				if(a[i]!=' ')i++;
		}
		if(i==1){
			printf("1\n");
		}else printf("0\n");
	}
	return 0;
}
