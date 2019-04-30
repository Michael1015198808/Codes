#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define INF 0x7fff
#define NUMBER_MAX 251
int path[NUMBER_MAX][NUMBER_MAX]={};
int ori_path[NUMBER_MAX][NUMBER_MAX]={};
int next_ver[NUMBER_MAX]={};
bool visited[NUMBER_MAX]={};
int aug[NUMBER_MAX]={},index;
int f=0;
int n,m,t;
int find(int);
int main(){
    map<string,int> list;
    int i,j,k,l,num=0,ans=0x7fff;
    string a,b;
    cin>>n>>m;
    for(i=0;i<m;++i){
        cin>>a>>b;
        if(list[a]==0){
            list[a]=++num;
        }
        k=list[a];
        if(list[b]==0){
            list[b]=++num;
        }
        l=list[b];
        ori_path[k][l]=1;
        ori_path[l][k]=1;
    }
    for(i=1;i<=n;++i){
        next_ver[i]=1;
    }
    for(t=2;t<=n;++t){
        f=0;
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                path[i][j]=ori_path[i][j];
            }
        }
    index=0;
        for(i=1;i<=n;++i){
            visited[i]=false;
        }
    while(find(1)){
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
    printf("%d %d\n",t,f);
    ans=min(ans,f);
    }
    printf("%d\n",ans);
    return 0;
}
int find(int l){
    if(l==t){
        aug[index++]=l;
        return true;
    }
    visited[l]=true;
    int i=next_ver[l];
    if(!visited[next_ver[l]]&&path[l][i]>0){
        if(find(next_ver[l])){
            return aug[index++]=l;
            return true;
        }
    }
    do{
        ++i;
        if(i>n){i-=n;}
        if(!visited[i]&&path[l][i]>0){
            if(find(i)){
                next_ver[l]=i;
                aug[index++]=l;
                return true;
            }
        }
    }while(i!=next_ver[l]);
    return false;
}
