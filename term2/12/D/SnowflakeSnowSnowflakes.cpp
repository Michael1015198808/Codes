#include <stdio.h>
#include <vector>
#define mod 999983
using namespace std;
struct snow{
	long length[6];
	int min;
};
long hash(snow);
bool equalsnow(snow,snow);
snow a[100000];
snow* hashtable[mod]={};
int main(){
	bool flag=false;
	int n,i,j,k,temp;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		temp=0;
		for(j=0;j<6;++j){
			scanf("%ld",&(a[i].length[j]));
			if(a[i].length[j]<a[i].length[temp]){
				temp=j;
			}
		}
		a[i].min=temp;
		temp=hash(a[i]);
//		printf("%d\n",temp);
		while(hashtable[temp]!=0){
			if(equalsnow(a[i],*(hashtable[temp]))){
					++i;
					goto found;
			}
			temp+=97;
		}
		hashtable[temp]=&(a[i]);
	}
	printf("No two snowflakes are alike.");
	return 0;
	found:;
	for(;i<n;++i){
		temp=0;
		for(j=0;j<6;++j){
			scanf("%ld",&(a[i].length[j]));
		}
	}
	printf("Twin snowflakes found.");
	return 0;
}
long hash(snow a){
	long sum1=0,sum2=0;
	int i;
	for(i=0;i<6;i+=2){
		sum1+=a.length[i];
		sum1-=a.length[i+1];
		sum2+=a.length[i];
		sum2+=a.length[i+1];
	}
	if(sum1<0){
		sum1=0-sum1;
	}
	return sum2%mod+(sum1%mod)&255;
}
bool equalsnow(snow p,snow q){
	int a,i,j;
	if(p.length[p.min]==q.length[q.min]){
		for(i=0;i<6;++i){
			for(j=0,a=i;j<6;++j){
				if(p.length[a]!=q.length[j]){
					break;
				}
				a=(a+1)%6;
			}
			if(j==6){
				return true;
			}
		}
		for(i=0;i<6;++i){
			for(j=0,a=i;j<6;++j){
				if(p.length[a]!=q.length[j]){
					break;
				}
				a=(a+5)%6;
			}
			if(j==6){
				return true;
			}
		}
	}
	return false;
}

