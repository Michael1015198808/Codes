#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::min;
#define food(A) A
#define guest1(A) (A+f)
#define guest2(A) (A+f+n)
#define drink(A) (A+f+2*n)
#define total (2*n+f+d)
int path[402][402]={};
int next[402]={};
bool visited[402]={};
int aug[402]={},index;
int flow=0;
int n,f,d;
int find(int);
int p_drink(int i){return drink(i);}
int main(){
    int i,j,k,l;
    scanf("%d%d%d",&n,&f,&d);
    for(i=1;i<=n;++i){
        path[guest1(i)][guest2(i)]=1;
        scanf("%d%d",&k,&l);
        for(j=0;j<k;++j){
            int temp;
            scanf("%d",&temp);
            path[food(temp)][guest1(i)]=1;
        }
        for(j=0;j<l;++j){
            int temp;
            scanf("%d",&temp);
            path[guest2(i)][drink(temp)]=1;
        }
    }
    for(i=1;i<=f;++i){
        path[0][food(i)]=1;
    }
    for(i=1;i<=d;++i){
        path[drink(i)][total+1]=1;
    }
    index=0;
    while(find(0)){
        for(i=1;i<=total;++i){
            visited[i]=false;
        }
        for(i=1;i<index;++i){
            path[aug[i]][aug[i-1]]-=1;
            path[aug[i-1]][aug[i]]+=1;
        }
        flow+=1;
        index=0;
    };
    printf("%d\n",flow);
    return 0;
}
int find(int l){
    if(l==total+1){
        aug[index++]=l;
        return true;
    }
    if(l!=0)
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
        if(i>total+1){i-=total+2;}
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
