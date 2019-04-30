#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x2fffffff
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solve(void);
int a[200000],b[200000];
int main(){
    //int n=0;
    //scanf("%d",n);
    //while(n--){
        solve();
    //}
    return 0;
}
void solve(void){
    int n,m,k;
    int i,j,cnt=0,num=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    memcpy(b,a,sizeof(int)*n);
    sort(b,b+n);
    int brk=b[n-m*k];
    for(i=0;b[n-m*k+i]==brk;++i){
        ++num;
    }
    long long ans=0;
    for(i=0;i<m*k;++i){
        ans+=b[n-1-i];
    }
    cout<<ans<<endl;
    i=-1;j=1;
    while(j<k){
        ++i;
        if(a[i]>=brk){
            if(a[i]==brk){
                if(num>0)--num;
                else continue;
            }
            ++cnt;
            if(cnt==m){
                printf("%d ",i+1);
                cnt=0;
                ++j;
            }
        }
    }
    return;
}

