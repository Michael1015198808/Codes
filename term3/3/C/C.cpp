#include <stdio.h>
#define num 100000
int fa[num+10];
void solve(void);
int find(int);
void unite(int,int);
int main(){
	int t;
		solve();
	return 0;
}
void solve(void){
	int n,m,i,j,k;
	char c;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;++i){
		fa[i]=i;
	}
	for(j=0;j<m;++j){
		do{
			c=getchar();
		}while(c!='K'&&c!='F');
		getchar();
		getchar();
		getchar();
		scanf("%d",&i);
		if(c=='K'){
			fa[i]=i+1;
		}else{
			if(find(i)==n){
				puts("-1");
			}else{
				printf("%d\n",fa[i]);
			}
		}
	}
}
int find(int i){
	if(fa[i]==fa[fa[i]]){
		return fa[i];
	}else{
		return fa[i]=find(fa[i]);
	}
}
void unite(int a,int b){
	fa[find(a)]=find(b);
	return;
}

