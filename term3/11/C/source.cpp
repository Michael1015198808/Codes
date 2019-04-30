#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::min;
#define INF 0x7fff
int path[202][202]={};
int next[202]={};
bool visited[202]={};
int aug[202]={},index;
int f=0;
int n,m,s,t;
int find(int);
int main(){
    int i,j,k,l;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d%d",&j,&k);
        path[0][i]+=j;
        path[i][201]+=k;
    }
    for(i=0;i<m;++i){
        scanf("%d%d%d",&j,&k,&l);
        path[j][k]=l;
        path[k][j]=l;
    }
    for(i=1;i<=n;++i){
        next[i]=1;
    }
    index=0;
    while(find(0)){
        for(i=1;i<=201;++i){
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
    if(l==201){
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
        if(i>=202){i-=202;}
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
