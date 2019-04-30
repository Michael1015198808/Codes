#include <stdio.h>
#include <algorithm>

int a[16],b[16];
int n,s;
int main(){
	int i,j,k;
	while(scanf("%d%d",&n,&s)==2){
		for(i=0;i<n;++i){
			a[i]=i+1;
		}
		do{
			for(i=0;i<n;++i){
				b[i]=a[i];
			}
			for(i=n-1;i>0;--i){
				for(j=0;j<i;++j){
					b[j]+=b[j+1];
				}
			}
			if(b[0]==s){
				for(i=0;i<n;++i){
					printf("%d ",a[i]);
				}
				break;
			}
		}while(std::next_permutation(a,a+n));
		putchar('\n'); 
	}
	return 0;
}
