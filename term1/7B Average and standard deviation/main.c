#include <stdio.h>
#include <stdlib.h>
double Average(double a,double b,double c,double d){
	return (a+b+c+d)/4;
}
double standard_deviation(double a,double b,double c,double d,double s){
	return pow(a-s,2)+pow(b-s,2)+pow(c-s,2)+pow(d-s,2);
}

int main() {
	double s[4],i;
	while(scanf("%lf %lf %lf %lf",&s[0],&s[1],&s[2],&s[3])!=EOF){
		i=Average(s[0],s[1],s[2],s[3]);
		printf("%.2lf %.2lf\n",i,pow(standard_deviation(s[0],s[1],s[2],s[3],i)/4,0.5));
	}
	return 0;
}
