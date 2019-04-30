#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
long long a[100000],cnt[99999],n,q;
long long solve(long long a);
int main(){
    int i;
    scanf("%lld",&n);
    for(i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n-1;++i){
        a[i]=a[i+1]-a[i];
    }
    sort(a,a+n-1);
    for(i=0;i<n-1;++i){
        //TODO: compute cnt[i]
    }
    scanf("%lld",&q);
    for(i=0;i<q;++i){
        long long l,r;
        cin>>l>>r;
        long long delta=r-l+1;
        cout<<solve(delta)<<' ';
    }
    putchar('\n');
    return 0;
}
long long solve(long long delta){
    long long ret=0,i;
    for(i=0;i<n-1;++i){
        ret+=
            //TODO: compute
    }
    return ret+delta;
}
