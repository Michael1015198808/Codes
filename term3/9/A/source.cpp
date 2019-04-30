#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;
int outd[26],ind[26];
bool connected[26];
vector<vector<int> >edges(26);
bool gold(void);
bool silver(void);
bool dfs(int now){
	int i;
	for(i=0;i<edges[now].size();++i){
		if(!connected[edges[now][i]]){
			connected[edges[now][i]]=1;
			dfs(edges[now][i]);
		}
	}
}
int main(){
	int i,j,k,n;
	char c,temp;
	scanf("%d",&n);
	rep(i,0,26){
		ind[i]=outd[i]=connected[i]=0;
	}
	rep(i,0,n){
		while('\n'==(j=getchar()));
		j-='a';
		while('\n'!=(temp=getchar())){
			k=temp;
		};
		k-='a';
		ind[j]++;
		outd[k]++;
		edges[j].push_back(k);
		edges[k].push_back(j);
	}
	rep(i,0,26){
		if(ind[i]!=0){
			break;
		}
	}
	dfs(i);
	rep(i,0,26) {
		if (connected[i] == 0 && (ind[i] != 0 || outd[i] != 0)) {
			puts("Nothing");
			return 0;
		}
	}
	if(gold()){
	    puts("Gold");
	}else if(silver()){
	    puts("Silver");
	}else{
		puts("Nothing");
	}
	return 0;
}
bool gold(void){
	int i=0,mark=0;//
	rep(i,0,26){
		switch (ind[i]-outd[i]){
			case 1:
				if(mark&1){
					return false;
				}
				mark|=1;
				break;
			case -1:
				if(mark&2){
					return false;
				}
				mark|=2;
				break;
			case 0:
				break;
			default:
				return false;
		}
	}
	return mark==3||mark==0;
}
bool silver(void){
	int i=0,mark=0;
	rep(i,0,26){
		if((ind[i]+outd[i])&1){
			++mark;
		}
	}
	return mark<3;
}
