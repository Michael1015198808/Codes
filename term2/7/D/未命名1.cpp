#include <stdio.h>

int main(){
	int n,one,zero,con_zero;
	char c,a[100];
	while((c=getchar())!=EOF){
		n=one=zero=con_zero=0;
		a[n]=c;
		if(c=='1'){
			++one;
		}else{
			++zero;
		}
		while((c=getchar())!='\n'){
			++n;
			a[n]=c;
			if(c=='1'){
				++one;
			}else{
				++zero;
				if(a[n-1]=='0'){
					++con_zero;
				}
			}
		}
		if(a[n]=='0'&&a[0]=='0'){
			++con_zero;
		}
		++n;
//		printf("total%d\n1%d\n0%d\n00%d\n",n,one,zero,con_zero);
		if(con_zero*n>zero*zero){
			printf("SHOOT");
		}else if(con_zero*n<zero*zero){
			printf("ROTATE");
		}else{
			printf("EQUAL");
		}
		putchar('\n');
	}
	return 0;
} 
