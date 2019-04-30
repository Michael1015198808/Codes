#include <stdio.h>
#include <stdlib.h>
int main() {
	double P,i,m,c;
	scanf("%lf",&P);
	scanf("%lf",&i);
	scanf("%lf",&m);
	scanf("%lf",&c);
	printf("%.2lf",(pow(P/2.2,0.756)*70+0.0385*i*P*m)/0.9/c);
	
	
	return 0;
}
