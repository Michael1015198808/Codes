#include <stdio.h>

char tree[33]={};
void inorder(int);
int max;
int main(){
	int i=1,depth;
	char c;
	scanf("%d",&depth);
	max=(1<<depth);
	do{
		while((c=getchar())=='\n');
		tree[i]=c;
		if(i>=(max>>1)){
			++i; 
			while(!(i&1)){
				i>>=1;
			}
		}else{
			i<<=1;
		}

	}while(i!=1);
	inorder(1);
	return 0;
}
void inorder(int i){
 	if(i>=max){
		return;
	}
	inorder(i<<1);
	if(tree[i]!='#'){
		putchar(tree[i]);
	}
	inorder((i<<1)+1);
}

