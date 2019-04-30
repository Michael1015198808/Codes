#include <stdio.h>
#include <map>
using namespace std;
int gcd(int,int); 

int main(){
	long long gcd,lcm,a,b,i;
	map <long,int> m;
	while(scanf("%lld%lld",&lcm,&gcd)==2){
		gcd/=lcm;
		for(i=2;i<=gcd;++i){
			while(gcd%i==0){
				gcd/=i;
				++m[gcd];
			}
		}
	}
	return 0;
}
int gcd(int a,int b){
	int c;
	if(a<b){
		c=a;
		a=b;
		b=c;
	}
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
