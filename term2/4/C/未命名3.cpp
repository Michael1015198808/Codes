#include <stdio.h>
#include <math.h>
#include <iostream>
#include <queue>
using std::endl;
int main(){
	std::priority_queue<long double,std::vector<long double>,std::greater<long double> >height;
	int c,n,i;
	long double t0,t,r,p,h,x;
	std::cout.flags(std::ios::fixed);
	std::cout.precision(2);
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		std::cin>>h>>r>>t0;
		for(i=0;i<n;++i){
			t=t0-i;
			if(t<=0){
				height.push(h);
				continue;
			}
			p=2*sqrt(h/5);
//			cout<<p<<endl;
			while(t>p){
				t-=p;
//				cout<<t<<endl;
			}
			if(t>p/2){
				t=p-t;
//				printf("c:%.2lf\n",5*t*t);
				height.push(h-5.0*t*t);
			}else{
//				printf("c:%.2lf\n",10.0-5.0*t*t);
				height.push(h-5.0*t*t);
			}
		}
		--n;
		for(i=0,x=0;;++i){
			std::cout<<(height.top()+0.02*r*i);
			height.pop();
			if(i==n){
				break;
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
/*
2
1 10 10 100

*/
