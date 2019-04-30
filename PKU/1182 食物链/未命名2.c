#include <stdio.h>
int father[150001];
int find(int x){
	if(father[x]==x){
		return x;
	}else{
		return father[x]=find(father[x]);
	}
}
void unite(int a,int b){
	father[father[a]]=father[b];
}

int main(){
	int N,K,count=0,n,x,y;
	scanf("%d",&N);
	for(K=1;K<=3*N;K++){
		father[K]=K;
	}
	scanf("%d",&K);
	while(K--){
		scanf("%d%d%d",&n,&x,&y);
		if(x>N||y>N){
			count++;
		}else{
			if(n==1){
				if(find(x)==find(y+N)||find(x)==find(y+2*N)){
					count++;
				}else{
					unite(x,y);
					unite(x+N,y+N);
					unite(x+2*N,y+2*N);
				}
			}else{
				if(find(x)==find(y)||find(x)==find(y+2*N)){
					count++;
				}else{
					unite(x,y+N);
					unite(x+N,y+2*N);
					unite(x+2*N,y);
				}
			}
		}
	}
	printf("%d",count);
	return 0;
}

