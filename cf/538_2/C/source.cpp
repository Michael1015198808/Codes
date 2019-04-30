#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x2fffffff
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef vector<int> vi;
unsigned long long n;
unsigned long long cul(unsigned long long num,unsigned long long devi){
    if(num==0)return 0;
    return num/devi+cul(num/devi,devi);
}
int main(){
    unsigned long long b,ans=0,i=2,j=0,k=0,cnt=-1;
    vector<unsigned long long>base,order;
    cin>>n>>b;
    while(i*i<=b){
        if(b%i==0){
            base.push_back(i);
            order.push_back(0);
            ++cnt;
            while(b%i==0){
                b/=i;
                ++order[cnt];
            }
        }
        ++i;
    }
    if(b>1){
        base.push_back(b);
        order.push_back(1);
        ++cnt;
    }
    ans=-1;
    for(i=0;i<=cnt;++i){
        ans=min(ans,cul(n,base[i])/order[i]);
    }
    cout<<ans<<endl;
    return 0;
}
