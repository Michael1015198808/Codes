#include <iostream>
#include <memory>
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
void what_day(int day);

int main()
{
	int century,year,month,day;
	while(scanf("%d %d %d",&year,&month,&day)==3){
	what_day((day+getMonthValue(month,year)+getYearValue(year)+getCenturyValue(year))%7);
	}
	return 0;
}

bool isLeapYear(int a)
{
	if((a%4==0&&a%100!=0)||a%400==0)
	{
		return true;
	}else return false;
}

int getCenturyValue(int a)
{
	return (3-a/100%4)*2;
}

int getYearValue(int a)
{
	int b=a%100;
	return b+b/4;
}

int getMonthValue(int a, int b)
{
	if(a>6){
		if(a>9){
			if(a==12)return 5;
			if(a==11)return 3;
			if(a==10)return 0;
		}
		else {
			if(a==9)return 5;
			if(a==8)return 2;
			if(a==7)return 6;
		}
	}
	else 
		if(a>3){
			if(a==6)return 4;
			if(a==5)return 1;
			if(a==4)return 6;
	}	else {
			if(a==3)return 3;
			if(a==2&&isLeapYear(b)==1)return 2;
			if(a==2&&isLeapYear(b)==0)return 3;
			if(a==1&&isLeapYear(b)==1)return 6;
			if(a==1&&isLeapYear(b)==0)return 0;	
	}
}

void what_day(int x)
{
	if(x>3){
		if(x==6)printf("Satur");
		if(x==5)printf("Fri");
		if(x==4)printf("Thurs");
	}
	if(x<2){
		if(x==1)printf("Mon");
		if(x==0)printf("Sun");
	}else{
		if(x==3)printf("Wednes");
		if(x==2)printf("Tues");
	}
	printf("day\n");
}
