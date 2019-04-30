#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN (100000+1)
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
vector <int> edges[MAXN];
int dfs_idx[MAXN],c[MAXN],no_apple[MAXN],son[MAXN];
inline int lowbit(int idx){return idx&-idx;}
int n;
int sum(int idx){
    int ret=0;
    while(idx>0){
        ret+=c[idx];
        idx-=lowbit(idx);
    }
    return ret;
}
void add(int idx,int ad){
    do{
        c[idx]+=ad;
        idx+=lowbit(idx);
    }while(idx<=n);
}
void dfs(int idx){
    static int cnt=0;
    dfs_idx[idx]=++cnt;
    for(int i=0;i<edges[idx].size();++i){
        dfs(edges[idx][i]);
    }
    son[dfs_idx[idx]]=cnt;
}
int main(){
    int i,j,k,op,M;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d %d",&j,&k);
        edges[j].push_back(k);
    }
    dfs(1);
    for(i=1;i<=n;++i)add(i,1);
    scanf("%d",&M);
    for(i=0;i<M;++i){
        do{
            op=getchar();
        }while(op!='Q'&&op!='C');
        scanf("%d",&j);
        j=dfs_idx[j];
        if(op=='C'){
            if(no_apple[j]){
                add(j,1);
            }else{
                add(j,-1);
            }
            no_apple[j]=~no_apple[j];
        }else{
            printf("%d\n",sum(son[j])-sum(j-1));
        }
    }
    return 0;
}

