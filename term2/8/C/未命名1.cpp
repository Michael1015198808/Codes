#include <stdio.h>
#include <stack>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define index my_index
#define next my_next
//命名与std库中我未使用的同名
#define INF 0x7fff
#define NUMBER_MAX 802
#define node(x,y) ((x-1)*m+y)
void bfs(void);
int find(int);
void solve();
int path[NUMBER_MAX][NUMBER_MAX]={};
int next[NUMBER_MAX]={};
int visited[NUMBER_MAX]={};
int aug[NUMBER_MAX]={};
int index;
int f=0;
int n,m,s;
int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;++i){
        solve();
        printf("Case #%d: ",i);
        if(f==0){printf("no");}
        else{printf("%d",f);}
        printf(" gift");
        if(f<2){printf(" was");}
        else{printf("s were");}
        printf(" left behind.\n");
    }
    return 0;
}
void solve(){
    int i,j,d,k,l;
    char c;
    m=f=0;
    scanf("%d%d",&n,&d);
    getchar();
    memset(path,0,sizeof(path));
    int temp[21];
    while(!isdigit(c=getchar()));
    do{
        ++m;
        temp[m]=c-'0';
    }while(isdigit(c=getchar()));
    for(i=1;i<=m;++i){
        path[node(1,i)][node(1,i)+n*m]=temp[i];
    }
    for(i=2;i<=n;+