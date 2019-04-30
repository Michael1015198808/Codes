#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::min;
#define INF 0x7fff
#define node(A,B) (((A)-1)*n+(B))
#define NUMBER_MAX 5001
int path[NUMBER_MAX][NUMBER_MAX]={};
int next[NUMBER_MAX]={};
bool visited[NUMBER_MAX]={};
int aug[NUMBER_MAX]={},index;
int f=0;
int n,m,s,t;
int find(int);
int main(){
    int i,j,k,l,x,y;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            path[node(i,j)][n*m+node(i,j)]=1;
            if(i>1)path[n*m+node(i,j)][node(i,j)-n]=1;
            if(i<m)path[n*m+node(i,j)][node(i,j)+n]=1;
            if(j>1)path[n*m+node(i,j)][node(i,j)-1]=1;
            if(j<n)path[n*m+node(i,j)][node(i,j)+1]=1;
        }
    }
    for(j=1;j<=n;++j){
        path[n*m+node(1,j)][2*n*m+1]=0x7fff;
        path[n*m+node(m,j)][2*n*m+1]=0x7fff;
    }
    for(i=1;i<=m;++i){
        path[n*m+node(i,1)][2*n*m+1]=0x7fff;
        path[n*m+node(i,n)][2*n*m+1]=0x7fff;
    }
    for(i=0;i<k;++i){
        scanf("%d%d",&x,&y);
        //printf("(%d,%d):%d\n",x,y,node(x,y));
        path[0][node(x,y)]=1;
    }
    for(i=1;i<=n*m;++i){
        next[i]=1+n*m;
    }
    for(i=n*m+1;i<2*n*m;++i){
        next[i]=2*n*m+1;
    }
    index=0;
    while(find(0)){
        for(i=1;i<=2*n*m+1;++i){
            visited[i]=false;
        }
        for(i=1;i<index;++i){
            path[aug[i]][aug[i-1]]-=1;
            path[aug[i-1]][aug[i]]+=1;
        }
        f+=1;
        index=0;
    };
    if(f<k){
        printf("not ");
    }
    puts("possible");
    return 0;
}
int find(int l){
    if(l==n*m*2+1){
        aug[index++]=l;
        return true;
    }
    visited[l]=true;
    int i=next[l];
    if(!visited[next[l]]&&path[l][i]>0){
        if(find(next[l])){
            return aug[index++]=l;
            return true;
        }
    }
    do{
        ++i;
        if(i>n*m*2+1){i-=n*m*2+1;}
        if(!visited[i]&&path[l][i]>0){
            if(find(i)){
                next[l]=i;
                aug[index++]=l;
                return true;
            }
        }
    }while(i!=next[l]);
    return false;
}
