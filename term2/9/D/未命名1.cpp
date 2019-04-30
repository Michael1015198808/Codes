#include <stdio.h>
#include <algorithm>
using std::sort;
long num[100000];
int main(){
	int i,j,k,
		high,low,mid,newlow,newhigh,
		n,m;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;++i){
			scanf("%ld",num+i);
		}
		sort(num,num+n);
		high=num[n-1]-num[0];
		low=0;
		m=((n)*(n-1))>>2;
		while(high>low){
			mid=(high+low)>>1;
			k=0;
			newlow=0;
			for(i=0;i<n;++i){
					newhigh=n-1;
				if(num[n-1]-num[i]>mid){
					while(newlow<newhigh){
						j=(newlow+newhigh)>>1;
						if(num[j]-num[i]<=mid){
								newlow=j+1;
						}else{
								newhigh=j;
						}
					}
					k+=n-newlow;
				}
			}
			if(k>m){
				low=mid+1;
			}else{
				high=mid;
			}
		}
		printf("%d\n",low);
	}
	return 0;
}
