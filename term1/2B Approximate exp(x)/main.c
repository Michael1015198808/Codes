#include <stdio.h>
#include <math.h>
int main() {
	double x,y,n;
	int t;
	while(scanf("%lf",&x)==1){
	n=1,y=1;
	printf("%.3f\n",exp(x));
    	for (t=1;t<=100;t++){
    	n=n*x/t;
    	y=y+n;
    	printf("%.3f",y);
	        if (t==t/10*10){printf("\n");}
			else printf(" ");}
		}
    return 0;
}
