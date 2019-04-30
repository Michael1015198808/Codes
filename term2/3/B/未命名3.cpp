#include <stdio.h>
//#include <windows.h>
int num[1000000];
bool ok[1000000];
bool hi[1000000];
int main(){
	int n,i,j,sum,ans;
	while(scanf("%d",&n)){
		if(!n){
			return 0;
		}
		ans=0;
		for(i=0;i<n;++i){
			scanf("%d",num+i);
		}
		for(i=0;i<n;++i){
			ok[i]=hi[i]=1;
		}
		for(i=n;i>=0;--i){
			if(num[i]<0&&hi[i]){
				hi[i]=0;
				sum=num[i];
//				printf("%d\n",sum);
				j=i;
				ok[j]=0;
				if(!j){
					j=n;
				}
				--j;
				sum+=num[j];
				if(num[j]<0){
					hi[j]=0;
				}
				while(sum<0&&j!=i){
					ok[j]=0;
//					printf("%d\t%d\t%d\n",i,j,sum);
//					system("pause");
					if(!j){
						j=n;
					}
					--j;
					sum+=num[j];
					if(num[j]<0){
						hi[j]=0;
					}
				}
			}
		}
		for(i=0;i<n;++i){
			if(ok[i]){
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
