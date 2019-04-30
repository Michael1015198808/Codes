#include <stdio.h>
int deptha=0,depthb=0;
bool calculate(int,int);
int main(){
	int i=1;
	while(calculate(0,0)){
		printf("Tree %d: %d => %d\n",i,deptha,depthb);
		++i;
		deptha=depthb=0;
	}
	return 0;
}
bool calculate(int a,int b){
//	printf("(%d,%d)\n",a,b);
	char c;
	if(a>deptha){
		deptha=a;
	}
	if(a+b>depthb){
		depthb=a+b;
	}
	while(c=getchar()){
		if(c=='u'||c=='\n'){
			return true;
		}else if(c=='#'){
			return false;
		}
		calculate(a+1,b);
		++b;
	}
}

