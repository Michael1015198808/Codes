#include <stdio.h>
#include <stdlib.h>
int main() {
	double money,insert;
	money=0;
	while(money<3.5){
	printf("%.2lf Please put ",money);
	if (3.5-money>=1){printf("dollar($3.50):\n");}
	   else{if (3.5-money>=0.25){printf("quarter($3.50):\n");}
	        else{if (3.5-money>=0.1){printf("dime($3.50):\n");}
	             else{printf("nickel($3.50):\n");}
	   }
	   }
	scanf("%lf",&insert);
	money=money+insert;
	}
	printf("Enjoy your deep-fried twinkie, change:%.2f",money-3.5);
	return 0;
}
