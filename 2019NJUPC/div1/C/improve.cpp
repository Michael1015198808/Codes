//C. ICPC
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
class Problem{
public:
    int id,t;
    bool operator<(const Problem &p)const{
    return t<p.t;
    }
}problems[15];
int a[15],fast[15],jyy[15],jyy_ac=0,jyy_t=0,dp[1<<13]={},cost[1<<13]={},rk=1;
int main(){
    int n,m,i=0,j;
    cin>>n>>m;
    memset(fast,0x37,sizeof(fast));
    for(j=0;j<m;++j){
        problems[j].id=j;
        if(scanf("%d",&problems[j].t)!=1){
            problems[j].t=30000;
        }
    }
    sort(problems,problems+m);
    for(j=m-1;problems[j].t>25000;--j);
    while(j-->0)
        problems[j+1].t-=problems[j].t;
    sort(problems,problems+m);
    for(j=0;j<m;++j)
        jyy[problems[j].id]=problems[j].t;
    int sum=0;
    for(j=0;j<m;++j){
        sum+=problems[j].t;
        a[problems[j].id]=sum;
    }
    for(j=0;j<m;++j){
        if(a[j]<25000){
            ++jyy_ac;
            jyy_t+=a[j];
        }
    }
    for(i=1;i<n;++i){
        int temp_ac=0,temp_t=0;
        for(j=0;j<m;++j){
            int temp;
            if(scanf("%d",&temp)==1){
                fast[j]=min(fast[j],temp);
                ++temp_ac;
                temp_t+=temp;
            }
        }
        rk+=(temp_ac==jyy_ac?temp_t<jyy_t:temp_ac>jyy_ac);
    }
    for(i=1;i<1<<m;++i){
        for(j=0;j<m;++j){
            if((1<<j)&i){
                cost[i]=cost[i^(1<<j)]+jyy[j];
                break;
            }
        }
        for(j=0;j<m;++j)
            if((1<<j)&i)
                dp[i]=max(dp[i],dp[i^(1<<j)]+(cost[i]<=fast[j]&&cost[i]<20000));
    }
    cout<<dp[(1<<m)-1]<<' '<<rk;
    return 0;
}
