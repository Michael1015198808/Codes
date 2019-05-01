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
class Team{
public:
    int idx,ac,t;
    bool operator<(const Team &team)const{
        return ac==team.ac?(t==team.t?idx==0:t<team.t):ac>team.ac;
    }
}teams[1005];
int a[15];
int fast[15];
int jyy[15];
int dp[1<<13]={};
int cost[1<<13]={};
int main(){
    int n,m,i=0,j;
    cin>>n>>m;
    memset(fast,0x37,sizeof(fast));
    teams[i].ac=teams[i].t=0;
    teams[i].idx=i;
    for(j=0;j<m;++j){
        problems[j].id=j;
        if(scanf("%d",&problems[j].t)!=1){
            problems[j].t=30000;
        }
    }
    sort(problems,problems+m);
    for(j=m-1;problems[j].t>25000;--j);
    while(j-->0){
        problems[j+1].t-=problems[j].t;
    }
    sort(problems,problems+m);
    if(i==0){
        for(j=0;j<m;++j){
            jyy[problems[j].id]=problems[j].t;
        }
    }
    int sum=0;
    for(j=0;j<m;++j){
        sum+=problems[j].t;
        a[problems[j].id]=sum;
    }
    for(j=0;j<m;++j){
        if(a[j]<25000){
            ++teams[i].ac;
            teams[i].t+=a[j];
        }
    }
    for(i=1;i<n;++i){
        teams[i].idx=i;
        for(j=0;j<m;++j){
            int temp;
            if(scanf("%d",&temp)==1){
                fast[j]=min(fast[j],temp);
                ++teams[i].ac;
                teams[i].t+=temp;
            }
        }
    }
    sort(teams,teams+n);
    for(i=1;i<1<<m;++i){
        for(j=0;j<m;++j){
            if((1<<j)&i){
                cost[i]=cost[i^(1<<j)]+jyy[j];
                break;
            }
        }
        for(j=0;j<m;++j){
            if((1<<j)&i){
                dp[i]=max(dp[i],dp[i^(1<<j)]+(cost[i]<=fast[j]&&cost[i]<20000));
            }
        }
    }
    cout<<dp[(1<<m)-1]<<' ';
    for(i=0;i<n;++i){
        if(teams[i].idx==0){
            cout<<i+1<<'\n';
            break;
        }
    }
    return 0;
}
