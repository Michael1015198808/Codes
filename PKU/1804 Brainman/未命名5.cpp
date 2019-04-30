#include <stdio.h>

void mergesort(int left,int right);
void merge(int left,int midium,int right);
int ans=0,aa[1005],naa[1005];
int main(void){
	int n=0,m=0,i=0,length=0;
	scanf("%d",&n);
	for(m=1;m<=n;m++){
		ans=0;
		scanf("%d",&length);
		for(i=0;i<length;i++){
			scanf("%d",&aa[i]);
		}
		mergesort(0,length-1); 
		printf("Scenario #%d:\n%d\n\n",m,ans);
	}
}
void mergesort(int a,int b){
	if(a<b){
		int mid=(a+b)/2;
		mergesort(a,mid);
		mergesort(mid+1,b);
		merge(a,mid+1,b);
	}
}
void merge(int a,int n,int b){
	int i=a,j=n,x=0;
	while(i<n&&j<=b){
		if(aa[i]<=aa[j]){
			naa[i+(j-n)]=aa[i];
			i++;
		}else{
			naa[i+(j-n)]=aa[j];
			ans+=n-i;
			j++;
		}
	}
	while(i<n){
		naa[i+j-n]=aa[i];
		i++;
	}
	while(j<=b){
		naa[i+j-n]=aa[j];
		j++;
	}
	for(i=a;i<=b;i++){
		aa[i]=naa[i];
	}
}
