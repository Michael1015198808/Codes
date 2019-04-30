#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100001]={};
int main(){
    int i,j;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    while(--i>0){
        a[i]-=a[i-1];
    }
    sort(a+1,a+n);
    unsigned long long ans=0;
    for(i=1;i<=n-k;++i){
        ans+=a[i];
    }
    cout<<ans+k<<endl;
    return 0;
}
