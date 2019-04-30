#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//Modified to n^3
int W[201][201],n,m,lx[201],ly[201],left[201];
int min_de[201];
bool S[201],T[201];
bool match(int u){
    S[u]=true;
    int i;
    for(i=1;i<=n;++i)if(lx[u]+ly[i]==W[u][i]&&!T[i]){
        T[i]=true;
        if(!left[i]||match(left[i])){
            left[i]=u;
            return true;
        }
    }
    return false;
}
void update(){
    int a=1<<30,i,j;
    for(i=1;i<=n;++i)if(S[i]){
        a=min(a,min_de[i]);
        j=i;
    }
    for(i=1;i<=n;++i){
        if(S[i]){
            lx[i]-=a;
            min_de[i]-=a;
        }
        if(T[i])ly[i]+=a;
    }
    min_de[j]=0x7ffff;
    for(i=1;i<=n;++i){if(W[i][j]!=lx[j]+ly[i])
        min_de[j]=min(min_de[j],W[i][j]-lx[j]-ly[i]);
    }
}
void KM(){
    int i,j;
    for(i=1;i<=n;++i){
        left[i]=lx[i]=ly[i]=0;
        for(j=1;j<=n;++j){
            lx[i]=max(lx[i],W[i][j]);
        }
    }
    for(i=1;i<=n;++i){
        min_de[i]=lx[i];
        for(j=1;j<=n;++j){
            if(lx[i]!=W[i][j]){
                min_de[i]=min(min_de[i],lx[i]-W[i][j]);
            }
        }
        while(true){
            memset(S,0,201);
            memset(T,0,201);
            if(match(i))break;else update();
        }
    }
}
int main(){
    struct{
        int x,y;
    }l[201],r[201];
    int i,j,k;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;++i){
        scanf("%d%d",&l[i].x,&l[i].y);
    }
    for(i=1;i<=n;++i){
        scanf("%d%d",&r[i].x,&r[i].y);
    }
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            W[i][j]=5000-abs(l[i].x-r[j].x)-abs(l[i].y-r[j].y);
        }
    }
    if(n<m){
        for(i=1;i<=m;++i){
            for(j=n+1;j<=m;++j){
                W[i][j]=5000;
            }
        }
        n=m;
    }else{
        for(i=m+1;i<=n;++i){
            for(j=1;j<=n;++j){
                W[i][j]=5000;
            }
        }
        m=n;
    }
    KM();
    int ans=0;
    for(i=1;i<=n;++i){
        ans+=W[left[i]][i];
    }
    printf("%d\n",5000*n-ans);
    return 0;
}
