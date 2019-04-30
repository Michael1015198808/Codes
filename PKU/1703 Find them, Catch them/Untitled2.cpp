#include <stdio.h>

void ini(void);
void solve(void);
void join(int,int);
int find(int);
int father[200001];
int n,m;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ini();
		solve();
	}
	return 0;
}
void ini(void){
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		father[i]=i;
	}
	for(i=100001;i<=100000+n;++i){
		father[i]=i;
	}
}
void solve(void){
	int i,a,b;
	char c;
	for(i=0;i<m;++i){
		do{
			c=getchar();
		}while(c!='D'&&c!='A');
		scanf("%d%d",&a,&b);
		if(c=='D'){
			join(a,b+100000);
			join(a+100000,b);
		}else{
			if(find(a)==find(b)){
				printf("In the same gang.\n");
			}else if(find(a)==find(b+100000)){
				printf("In different gangs.\n");
			}else{
				printf("Not sure yet.\n");
			}
		}
	}
}
void join(int a,int b){
	father[find(a)]=find(b);
}
int find(int a){
	if(father[a]!=father[father[a]]){
		father[a]=find(father[a]);
	}
	return father[a];
}
