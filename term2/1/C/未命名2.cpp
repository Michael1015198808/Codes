#include <stdio.h>
#include <iostream>
using std::cin;
using std::cout;
int main(){
	int x=0;
	char c;
	while(getchar()!='\n')continue;
	while(!cin.eof()){
		printf("String #%d\n",++x);
		while(c=getchar()){
			if(c=='\n')break;
				cout<<(c=='Z'?'A':++c);
			}
		printf("\n\n");
	}
}
