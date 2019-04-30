#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define test(format, ...) //printf(format, __VA_ARGS__)
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
using namespace std;
int num=-1;
int dfn[1001],low[1001],head[1001];
int stack[1001];
int cut_vertex[1001],cnt_cut_vertex=0,cnt_cut_edge=-1;
pair<int,int> cut_edge[50001];
bool lookup[1001]={};
int cnt_edge=-1;
int cnt_tarjan=0;
int index=-1;
bool path[1001][1001]={};
vector<int> edge[1001];
int tarjan(int x,int from){
    int i,j,k;
    dfn[x]=low[x]=++cnt_tarjan;
		int up_bound=edge[x].size();
		rep(i,0,up_bound){
        int v=edge[x][i];
        if(v==from)continue;
        if(!dfn[v]){
            if(tarjan(v,x)<low[x]){
                low[x]=low[v];
            }
						if(low[v]>=dfn[x]){
                if(low[v]>dfn[x]){
                    cut_edge[++cnt_cut_edge].first=min(v,x);
                    cut_edge[cnt_cut_edge].second=max(v,x);
                }
                if(lookup[x]==0)
                cut_vertex[++cnt_cut_vertex]=x;
                lookup[x]=1;
            }
        }else{
            update(low[x],dfn[v]);
        }
    }
    return low[x];
}
int tarjan_root(int x){
    int i,j=0;
    dfn[x]=low[x]=++cnt_tarjan;
    stack[++index]=x;
		int up_bound=edge[x].size();
		rep(i,0,up_bound){
        int v=edge[x][i];
        if(!dfn[v]){
            if(tarjan(v,x)<low[x]){
                low[x]=low[v];
            }else if(low[v]>=dfn[x]){
                if(low[v]>dfn[x]){
                    cut_edge[++cnt_cut_edge].first=min(v,x);
                    cut_edge[cnt_cut_edge].second=max(v,x);
                }
                ++j;
            }
        }else{
            update(low[x],dfn[v]);
        }
    }
    if(j>1) {
        cut_vertex[++cnt_cut_vertex]=x;
    }
    if(low[x]==dfn[x]){
        ++num;
        do{
            --index;
        }while(x!=stack[index+1]);
    }
    return low[x];
}
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n+1){
        head[i]=-1;
        dfn[i]=0;
    }
    rep(i,0,m){
        scanf("%d%d",&j,&k);
				if(path[j][k]==0){
								path[j][k]=path[k][j]=1;
								edge[j].push_back(k);
								edge[k].push_back(j);

				}
    }
    tarjan_root(1);
    if(cnt_cut_vertex==0){
        puts("Null");
    }else{
        sort(cut_vertex+1,cut_vertex+cnt_cut_vertex+1);
        rep(i,1,cnt_cut_vertex+1){
            printf("%d ",cut_vertex[i]);
        }
        putchar('\n');
        sort(cut_edge,cut_edge+cnt_cut_edge+1);
        rep(i,0,cnt_cut_edge+1){
            printf("%d %d\n",cut_edge[i].first,cut_edge[i].second);
        }
    }
    return 0;
}
