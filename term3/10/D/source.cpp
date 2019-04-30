#include <stdio.h>
#include <string.h>
int n,m,ans,left[501];
bool map[501][501]={};
bool s[501],t[501];
bool check(int);
int main(){
    int i,j,k;
    while(scanf("%d%d",&n,&m)==2){
        if(m==0&&n==0)break;
        memset(map,0,sizeof(map));
        ans=0;
        for(i=0;i<m;++i){
            scanf("%d%d",&j,&k);
            map[j][k]=1;
        }
        for(k=1;k<=n;++k){
            for(i=1;i<=n;++i){
                for(j=1;j<=n;++j){
                    map[i][j]=map[i][j]||(map[i][k]&&map[k][j]);
                }
            }
        }
        for(i=1;i<=n;++i){
            memset(s,0,501);
            memset(t,0,501);
            if(check(i)){
                ++ans;
            }
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
bool check(int u){
    int v;
    s[u]=1;
    for(v=1;v<=n;++v){
        if(map[u][v])if(!t[v]){
            t[v]=1;
            if(left[v]==0){
                left[v]=u;
                return true;
            }else{
                if(check(left[v])){
                    left[v]=u;
                    return true;
                }
            }
        }
    }
    return false;
}