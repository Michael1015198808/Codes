#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::min;
#define INF 0x7fff
int path[201][201]={};
int next[201]={};
bool visited[201]={};
int aug[201]={},index;
int f=0;
int n,m,s,t;
int find(int);
int main(){
    int i,j,k,l;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(i=0;i<m;++i){
        scanf("%d%d%d",&j,&k,&l);
        path[j][k]+=l;
    }
    for(i=1;i<=n;++i){
        next[i]=1;
    }
    index=0;
    while(find(s)){
        for(i=1;i<=n;++i){
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
    if(l==t){
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
        if(i>n){i-=n;}
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