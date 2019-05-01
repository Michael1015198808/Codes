//J. Wood Processing
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
#define maxm 705
#define maxn 305
class Wood{
public:
    int w,h;
    bool operator<(const Wood &wood)const{
        return h==wood.h?w<wood.w:h<wood.h;
    }
}woods[maxm];
unsigned long long cut[maxm][maxm]={},dp[maxm][maxn]={};
int main(){
    int n,k,i,j,to;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;++i){scanf("%d%d",&woods[i].w,&woods[i].h);}
    sort(woods,woods+n);
    for(i=0;i<=n;++i){
        for(j=i+1;j<=n;++j){
            cut[i][j]=cut[i][j-1]+(woods[j-1].h-woods[i].h)*1LL*woods[j-1].w;
        }
    }
    memset(dp,0x37,sizeof(dp));
    memset(dp,0,sizeof(dp[0]));
    dp[1][1]=0;
    for(i=2;i<=n;++i){
        for(j=1;j<=min(i,k);++j){
//dp[i][j] first i woods, j parts
            for(int mid=j-1;mid<i;++mid){
//first mid woods, j-1 parts
                dp[i][j]=min(dp[i][j],dp[mid][j-1]+cut[mid][i]);
            }
//dp[i][j]=dp[mid][j-1]+cut[mid][i]
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
