#include <stdio.h>
int main(){
	int i,x;
	char c;
	scanf("%d",&i);
	getchar();
	for(x=1;x<=i;x++){
		printf("String #%d\n",x);
		while((c=getchar())!='\n'&&c!=EOF){
			printf("%c",c=='Z'?'A':++c);
		}
		printf("\n\n");
	}
}
