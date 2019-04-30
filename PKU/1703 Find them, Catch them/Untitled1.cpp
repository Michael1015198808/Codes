#include <stdio.h>

bool diff[100001];
int father[100001];
void join(int,int);
void judge(int,int);
int find(int);
void ini(void);
void solve(void);
void show(void);
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
	for(i=1;i<=n;++i){
		diff[i]=false;
	}
}
void solve(void){
	int i,a,b;
	char c;
	for(i=0;i<m;++i){
		do{
			c=getchar();
		}while(c!='A'&&c!='D');
		scanf("%d%d",&a,&b);
		if(c=='A'){
			judge(a,b);
		}else{
			join(a,b);
		}
//		show();
	}
}
void join(int a,int b){
	find(a);
	find(b);
	diff[father[a]]=!diff[a]^diff[b];
	father[father[a]]=father[b];
}
int find(int a){
	if(father[a]!=father[father[a]]){
		find(father[a]);
		diff[a]^=diff[father[a]];
		father[a]=father[father[a]];
	}
	return father[a];
}
void judge(int a,int b){
	if(find(a)==find(b)){
		if(diff[a]==diff[b]){
			printf("In the same gang.\n");
		}else{
			printf("In different gangs.\n");
		}
	}else{
		printf("Not sure yet.\n");
	}
}
void show(void){
	int i;
	for(i=1;i<=n;++i){
		printf("%3d ",father[i]);
	}
	putchar('\n');
	for(i=1;i<=n;++i){
		printf("%3d ",diff[i]);
	}
	putchar('\n');
}
