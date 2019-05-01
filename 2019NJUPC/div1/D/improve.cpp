//D. Match Maker
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
#define TRAIL 100
using namespace std;
uint64_t x[200005],n;
bool is_prime[1000001];
uint64_t nxt[1000001];
bool test(uint64_t div){
    uint64_t cnt=0;
    for(uint64_t i=0;i<n;++i){
        if(x[i]%div==0)++cnt;
    }
    return cnt>((n-1)>>1);
}
int main(){
    uint64_t i,j,k;
    cin>>n;
    srand(time(NULL));
    memset(is_prime,1,sizeof(is_prime));
    for(k=2,i=2;i<1000001;++i){
        if(!is_prime[i])continue;
        nxt[k]=i;
        k=i;
        for(j=i<<1;j<1000001;j+=i){
            is_prime[j]=0;
        }
    }
    for(i=0;i<n;++i){
        cin>>x[i];
    }
    for(i=0;i<TRAIL;++i){
        uint64_t choosen=x[rand()%n];
        for(j=2;j*j<=choosen;j=nxt[j]){
            if(!is_prime[j])continue;
            if(choosen%j==0){
                if(test(j)){
                    puts("YES");
                    return 0;
                }
            }
            while(choosen%j==0){choosen/=j;}
        }
        if(choosen!=1&&test(choosen)){
            puts("YES");
            return 0;
        }
        //clog<<i<<endl;
    }
    puts("NO");
    return 0;
}
