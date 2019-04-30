#include <stdio.h>
#include <iostream>
#include <algorithm>
//#include <windows.h>
#define max(A,B) (A>B)?A:B
class ffloor{
public:
	int w,s;
	bool operator<(const ffloor& a)const{
		return (w+s)<(a.w+a.s);
	}
	void swap(ffloor& a){
		int temp;
		temp=a.w;
		a.w=w;
		w=temp;
		temp=a.s;
		a.s=s;
		s=temp;
	}
	void show(void)const{
		printf("%d\t%d\n",w,s);
	}
};

ffloor a[100000];
using std::sort;
//void qsort(floor*,int,int);
int main(){
	int n;
	int i,j,k;
	long long ans,all;
	while(scanf("%d",&n)==1){
		ans=all=0;
		for(i=0;i<n;++i){
			scanf("%d%d",&(a[i].w),&(a[i].s));
		}
		sort(a,a+n);
		for(i=0;i<n;++i){
//			a[i].show();
			all+=a[i].w;
		}
		for(i=n-1;i>-1;--i){
			all-=a[i].w;
			ans=max(all-a[i].s,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
void qsort(floor a[],int l,int r){
	if(r>l){
		int i=l,j=r;
		while(j>i){
			while(a[j]<=a[i]&&j>i){
				--j;
			}
			if(j==i){
				break;
			}
			a[i].swap(a[j]);
			while(a[j]<=a[i]&&j>i){
				++i;
			}
			a[i].swap(a[j]);
		}
//		printf("%d-%d-%d-%d\n",l,i,j,r);
//		for(int b=l;b<r;++b){
//			a[b].show();
//		}
//		printf("\n");
		qsort(a,l,i-1);
		qsort(a,i+1,r);
	}
}
*/
