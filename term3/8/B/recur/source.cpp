#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define test(format, ...) //printf(format, __VA_ARGS__)
#define rep(A,B,C) for(A=(B);A<C;++A)
#define update(A,B) A=(A)<(B)?(A):(B)
#define INF 0x3fffffff
using namespace std;
struct{
                int v,next;
}edge[20000];
int num=-1;
int dfn[1001],low[1001],head[1001],belong[1001];
bool vis[1001];
int stack[1001];
int cut_vertex[1001],cnt_cut_vertex;
int sub[1001];
void add(int p,int q){
                static int cnt_edge=-1;
                edge[++cnt_edge].next=head[p];
                edge[cnt_edge].v=q;
                head[p]=cnt_edge;
                return;
}
int tarjan(int x,int from){
                //printf("%d to %d\n",x);
                static int cnt=0,index=-1;
                int i,j,k;
                dfn[x]=low[x]=++cnt;
                test("%dcnt%d\n",cnt,x);
                vis[x]=1;
                stack[++index]=x;
                for(i=head[x];i!=-1;i=edge[i].next){
                                int v=edge[i].v;
                                if(v==from)continue;
                                if(!dfn[v]){
                                                if(tarjan(v,x)<low[x]){
                                                                low[x]=low[v];
                                                }else{
                                                                if(cut_vertex[cnt_cut_vertex]!=x){
                                                                                cut_vertex[++cnt_cut_vertex]=x;
                                                                                sub[x]=2;
                                                                }else{
                                                                                ++sub[x];
                                                                }
                                                }
                                }else if(vis[v]){
                                                update(low[x],dfn[v]);
                                }
                }
                if(low[x]==dfn[x]){
                                ++num;
                                do{
                                                belong[stack[index]]=num;
                                                vis[stack[index]]=0;
                                                --index;
                                }while(x!=stack[index+1]);
                }
                test("tarjan (%d,%d) returns %d\n",x,from,low[x]);
                return low[x];
}
int main(){
    int i,j,k,n,m;
    int time=0;
    cut_vertex[0]=0;
    cnt_cut_vertex=0;
    rep(i,1,1001){
                    head[i]=-1;
                    dfn[i]=0;
                    vis[i]=0;
    }
    n=0;
    while(scanf("%d%d",&j,&k)==2){
        if(j!=0||k!=0){
            add(j,k);
            add(k,j);
            if(j>n){
                n=j;
            }
            if(k>n){
                n=k;
            }
        }else{
            tarjan(1,0);
            if(--sub[1]<2){
                --cnt_cut_vertex;
            }
        rep(i,1,n+1){
            if(dfn[i]){
                continue;
            }
            *(int*)0=0;
            //Judge whether the graph is connected.
        }
        rep(i,1,n+1){
            test("%d\tdfn%d\tlow%d\n",i,dfn[i],low[i]);
        }
        printf("Network #%d\n",++time);
        if(cnt_cut_vertex==0){
            puts("No SPF nodes");
        }else{
            sort(cut_vertex+1,cut_vertex+cnt_cut_vertex+1);
            if(cnt_cut_vertex>=n)*(int*)0=0;
            rep(i,1,cnt_cut_vertex+1){
                printf("SPF node %d leaves %d subnets\n",cut_vertex[i],sub[cut_vertex[i]]);
            }
        }
	return main();
        }
    }
    return 0;
}
