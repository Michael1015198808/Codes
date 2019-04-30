#include <stdio.h>

void mergesort(int,int);
void merge(int,int,int);
void insertsort(int,int);

long long ans=0;
int num[500001];
int numm[500001];
int main(){
	int n,i,temp;
	while(scanf("%d",&n)&&n){
		ans=0;
		for(i=0;i<n;++i){
			scanf("%d",num+i);
		}
		mergesort(0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}

void mergesort(int lb,int ub){
	if(lb>ub-10){
		insertsort(lb,ub);
	}else{
		int mid=(ub+lb)/2;
		mergesort(lb,mid);
		mergesort(mid+1,ub);
		merge(lb,mid+1,ub);
	}
	return;
}
void merge(int lb,int mid,int ub){
	int i=lb,j=mid,flag=lb;
	while(i<mid&&j<=ub){
		if(num[i]>num[j]){
			numm[flag]=num[j];
			ans+=j-flag;
			++j;
		}else{
			numm[flag]=num[i];
			++i;
		}
		++flag;
	}
	while(i<mid){
		numm[flag]=num[i];
		++flag;
		++i;
	}
	while(j<=ub){
		numm[flag]=num[j];
		++flag;
		++j;
	}
	for(i=lb;i<=ub;++i){
		num[i]=numm[i];
	}
}
void insertsort(int lb,int ub){
	int i,min,mid,max,temp;
	for(i=lb+1;i<=ub;++i){
		min=lb;
		max=i;
		temp=num[i];
		while(max>min){
			mid=(min+max)/2;
			if(temp<num[mid]){
				max=mid;
			}else{
				min=mid+1;
			}
		}
		ans+=i-min;
		for(max=i;max>min;--max){
			num[max]=num[max-1];
		}
		num[max]=temp;
	}
}
