#include <stdio.h>

long a[9999];
int main(){
	int p,m,i,j,k,l,temp,t=0;
	scanf("%d",&p);
	for(l=1;l<=p;++l){
		t=0;
		scanf("%d",&k);
		scanf("%d",&k);
		printf("%d %d\n",l,(k+1)>>1);
		for(i=0;i<k;++i){
			if(i&1==1){
				printf("%d ",a[i>>1]);
				++t;
				if(t==10){
					t=0;
					putchar('\n');
				}
			}
			scanf("%d",&temp);
			for(j=0;j<i;++j){
				if(temp>a[j]){
					break;
				}
			}
			for(int k=i;k>j;--k){
				a[k]=a[k-1];
			}
			a[j]=temp;
		}
		printf("%d\n",a[i>>1]);
	}
	return 0;
}

