#include <stdio.h>

int a[185];
bool b[185]={};
int main(){
	int n,sum,n3,
		i,j,k;
	scanf("%d",&n);
	n3=3*n;
	for(i=1;i<=n3;++i){
		scanf("%d",a+i);
		b[i]=true;
	}
	printf("n:%d\t500*n=%d\n",n,500*n); 
	while(getchar()!='\n');
	while(getchar()!='\n'); 
	for(sum=0,i=0;i<n;++i){
		scanf("%d",&j);
		sum+=a[j];
		if(b[j]){
			b[j]=false;
		}else{
			printf("Multi-%d\n",j);
		}
	}
	printf("%d\n",sum);
	for(sum=0,i=0;i<n;++i){
		scanf("%d",&j);
		sum+=a[j];
		if(b[j]){
			b[j]=false;
		}else{
			printf("Multi-%d\n",j);
		}
	}
	printf("%d\n",sum);
	for(sum=0,i=0;i<n;++i){
		scanf("%d",&j);
		sum+=a[j];
		if(b[j]){
			b[j]=false;
		}else{
			printf("Multi-%d\n",j);
		}
	}
	printf("%d\n",sum);
	for(i=0;i<n3;++i){
		if(b[j]){
			printf("Lose-%d\n",j);
		}
	}
	scanf("%d",&sum);
	return 0;
}
