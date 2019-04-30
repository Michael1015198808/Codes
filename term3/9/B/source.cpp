#include <stdio.h>
#include <vector>
#include <queue>
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;

bool visited[21]={};
int edges[21][21]={};
vector<vector<int> >edge_set(21);
int degree[21]={};
int cnt_visit=0;
bool dfs_eular(int);
bool dfs_hami(int);
int n,m;
void matrix(void){
	int i,j;
	rep(i,1,n+1){
		rep(j,1,n+1){
			printf("%d,",edges[i][j]);
		}
		putchar('\n');
	}
}
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	rep(i,0,n){
	    visited[i]=false;
	}
	rep(i,0,m){
	    scanf("%d%d",&j,&k);
		if(j!=k) {
			degree[j]++;
			degree[k]++;
			if(edges[j][k]==0) {
				edge_set[j].push_back(k);
				edge_set[k].push_back(j);
			}
			edges[j][k]++;
			edges[k][j]++;
		}else{
			edges[j][j]++;
			--m;
			--i;
		}
	}
	cnt_visit=1;
	//Euler part
	rep(i,1,n+1){
		visited[i]=true;
		if(dfs_eular(i)){
			break;
		}
		visited[i]=false;
	}
	if(cnt_visit!=n){
		puts("Miss Shizue");
		return 0;
	}
	//Hami part
	int cnt_odd=0,temp=1;
	rep(i,1,1+n) {
		if(degree[i]&1) {
			cnt_odd++;
			temp=i;
		}
	}
	if(cnt_odd<=2){
		if(dfs_hami(temp)){
			return 0;
		}
	}
	puts("Miss Leon");
	return 0;
}
//vector<int> eularpath;
bool dfs_eular(int s){
	int i,j;
	/*rep(i,0,eularpath.size()){
		printf("%d,",eularpath[i]);
	}
	printf("%d\n",s);
	eularpath.push_back(s);*/
	rep(j,0,edge_set[s].size()){
		i=edge_set[s][j];
		if(edges[s][i]==0){
			continue;
		}
		if(visited[i]){
			continue;
		}
		++cnt_visit;
		if(cnt_visit==n){
			return true;
		}
		visited[i]=true;
		if(dfs_eular(i)){
			return true;
		}
		visited[i]= false;
		--cnt_visit;
	}
	//eularpath.pop_back();
	return false;
}
bool dfs_hami(int s){
    int i,j;
	rep(j,0,edge_set[s].size()){
	    i=edge_set[s][j];
		if(edges[s][i]==0){
			continue;
		}
		--m;
		if(m==0){
			puts("Find Leon");
			printf("%d %d\n",i,s);
			while(edges[s][s]-->0){
				printf("%d %d\n",s,s);
			}
			return true;
		}
		edges[s][i]--;
		edges[i][s]--;
		if(dfs_hami(i)){
			printf("%d %d\n",i,s);
			while(edges[s][s]-->0){
				printf("%d %d\n",s,s);
			}
			return true;
		}
		edges[s][i]++;
		edges[i][s]++;
		++m;
	}
	return false;
}
