#include <stdio.h>
#define num 131072
int fa[2*num];
void solve(void);
int find(int);
void unite(int,int);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
void solve(void){
	int n,m,i,j,k;
	char c;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		fa[i]=i;
		fa[i+num]=i+num;
	}
	for(i=0;i<m;++i){
		do{
			c=getchar();
		}while(c!='A'&&c!='D');
		scanf("%d %d",&j,&k);
		if(c=='D'){
			unite(j,num+k);
			unite(num+j,k);
		}else{
			if(find(j)==find(k)){
				puts("In the same gang.");
			}else if(find(j+num)==find(k)){
				puts("In different gangs.");
			}else{
				puts("Not sure yet.");
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

