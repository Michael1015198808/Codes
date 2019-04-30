#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
long a[4000],b[4000],c[4000],d[4000];
int test[16000000]={};
int main(){
	int i,j,k,n;
	long long ans=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%ld%ld%ld%ld",a+i,b+i,c+i,d+i);
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	sort(d,d+n);
	for(i=0,k=0;i<n;++i){
		for(j=0;j<n;++j){
			test[k]=a[i]+b[j];
			++k;
		}
	}
	sort(test,test+n*n);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			int temp=-c[i]-d[j];
			ans+=upper_bound(test,test+n*n,temp)-lower_bound(test,test+n*n,temp);
		}
	}
	printf("%ld",ans);
	return 0;
}

