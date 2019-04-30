#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::min;
#define INF 0x7fff
#define NUMBER_MAX 102
int path[NUMBER_MAX][NUMBER_MAX]={};
int next[NUMBER_MAX]={},last[1001]={},store[1001]={};
bool visited[NUMBER_MAX]={};
int aug[NUMBER_MAX]={},index;
int f=0;
int n,m,s,t;
int find(int);
int main(){
    int i,j,k,l;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;++i){
        scanf("%d",store+i);
    }
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        for(j=0;j<k;++j){
            scanf("%d",&l);
            path[last[l]][i]+=last[l]==0?store[l]:0x7fff;
            last[l]=i;
        }
        scanf("%d",&path[i][n+1]);
    }
    for(i=0;i<=n+1;++i){
        next[i]=1;
    }
    index=0;
    while(find(0)){
        for(i=0;i<=n+1;++i){
            visited[i]=false;
        }
        int temp=0x7fff;
        for(i=1;i<index;++i){
            temp=min(temp,path[aug[i]][aug[i-1]]);
        }
        for(i=1;i<index;++i){
            path[aug[i]][aug[i-1]]-=temp;
            path[aug[i-1]][aug[i]]+=temp;
        }
        f+=temp;
        index=0;
    };
    printf("%d\n",f);
    return 0;
}
int find(int l){
    if(l==n+1){
        aug[index++]=l;
        return true;
    }
    visited[l]=true;
    int i=next[l];
    if(!visited[next[l]]&&path[l][i]>0){
        if(find(next[l])){
            aug[index++]=l;
            return true;
        }
    }
    do{
        ++i;
        if(i>n+1){i-=n+1;}
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
