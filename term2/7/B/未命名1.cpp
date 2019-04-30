#include <stdio.h>

int main(){
	double a[101],p;
	int c,n,m,
		i,j,k;
	bool odd=true;
	while(scanf("%d",&c),c){
		scanf("%d%d",&n,&m);
		if(c>=m&&!((n^m)&1)){
			odd=true;
			a[0]=1.0;
			for(i=1;i<=c+1;++i){
				a[i]=0.0;
			}
			p=1/(double)c;
			++n;
			if(n>10000){
				n=10000;
			}
			while(--n){
				for(i=odd;i<=c;i+=2){
					a[i]=0;
					if(i-1>=0){
						a[i]+=a[i-1]*(1.0-p*(i-1));
					}
					a[i]+=a[i+1]*p*(i+1);
				}
				odd=1-odd;
			}
			printf("%.3lf\n",a[m]);
		}else{
			printf("0.000\n");
		}
	}
	return 0;
}
