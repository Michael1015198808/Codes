#include <iostream>
void compute_coin(int coin_value, int& number, int& amount_left);
int main()
{
	int coins,num;
	while(scanf("%d",&coins)!=-1){
		compute_coin(25,num,coins);
		printf("%d quarters(s) ",num);
		compute_coin(10,num,coins);
		printf("%d dime(s) ",num);
		compute_coin(1,num,coins);
		printf("%d penny(pennies)\n",num);
	}
	
}
void compute_coin(int a, int& b, int& c)
{
	b=c/a;
	c=c-a*b;
}
