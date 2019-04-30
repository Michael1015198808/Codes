#include <stdio.h>
bool test(char c);
int main(){
	int i=0,j=0,posi=0;
	char s[81]={'Z'},temp;
	temp=getchar();
	if(test(temp)){
		while(test(temp=getchar()));
	}
	s[0]=temp;
	while(1){
		if(temp==EOF){
			break;
		}
		for(i=1;i<80;++i){
			s[i]=getchar();
			if(test(s[i])){
				break;
			}
		}
		s[i]='\0'; 
		if(s[0]=='<'){
			if(s[1]=='b'||s[1]=='B'){
				printf("\n");
				posi=0;
			}else{
				if(posi){
					printf("\n");
				}
				for(j=0;j<16;++j){
					printf("-----");
				}
				printf("\n");
				posi=0;
			}
		}else{
			if(posi+i+1>80){
				printf("\n");
				posi=i;
				for(j=0;s[j]!='\0';++j){
		      		printf("%c",s[j]);
				}
			}else{
				if(posi){
					printf(" ");
				}
				for(j=0;s[j]!='\0';++j){
					printf("%c",s[j]);
				}
				posi+=i+1;
			}
		}
		while(test(temp=getchar()));
		s[0]=temp;
	}
	printf("\n");
	return 0;
}
bool test(char c){
	if(c==' '||c=='\t'||c=='\n'){
		return true;
	}
	return false;
}
