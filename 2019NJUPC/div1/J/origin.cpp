//J. Wood Processing
//Method I:Divide & Conquer
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
#define maxm 5005
#define maxn 3005
class Wood{
public:
    int w,h;
    bool operator<(const Wood &wood)const{
        return h==wood.h?w<wood.w:h<wood.h;
    }
}woods[maxm];
uint64_t dp[maxn][maxm]={},rwid[maxm]={0};
void solve(int div,int l,int r,int vl,int vr){
    int64_t maxsum=0;
    int m=(l+r)>>1,idx=0;
    if(r-l<0)return;
//Calculate dp[div][m] and devide point(idx)
//dp[div-1][mid]+ {mid+1...r-1}
    for(int mid=min(m-1,vr);mid>=vl;--mid){
        if(dp[div-1][mid]+(rwid[m]-rwid[mid])*woods[mid].h>maxsum){
            idx=mid;
            maxsum=dp[div-1][mid]+(rwid[m]-rwid[mid])*woods[mid].h;
        }
    }
    dp[div][m]=maxsum;
    solve(div,l,m-1,vl,idx);
    solve(div,m+1,r,idx,vr);
}
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;++i)
        scanf("%d%d",&woods[i].w,&woods[i].h);
    sort(woods,woods+n);
    for(i=1;i<=n;++i){
        rwid[i]=rwid[i-1]+woods[i-1].w;
        dp[1][i]=(rwid[i])*woods[0].h;
    }
    for(i=2;i<=k;++i)
        solve(i,i,n,i-1,n);
    cout<<[&]{
        int64_t ret=0;
        for(int i=0;i<n;++i){
            ret+=woods[i].w*1LL*woods[i].h;
        }
        return ret;
    }()-dp[k][n]<<endl;
    return 0;
}
