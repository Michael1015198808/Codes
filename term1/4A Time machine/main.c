#include <stdio.h>
#include <stdlib.h>
int main() {
	int h,x;
	char a;
	scanf("%d",&h);
	x=h*60-h/12*720;
	scanf("%d %c",&h,&a);
	x=x+h+a/80*720;
	scanf("%c %d",&h,&h);
	x=h*60-h/12*720-x;
	scanf("%d %c",&h,&a);
	x=x+h+a/80*720;
	printf("%d",x-(x-1439)/1440*1440);
	return 0;
}
