#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int b[200050];
int cnt[5]={};
bool is_prime[200005];
int main(){
    int n,i,j,sum=0;
    cin>>n;
    memset(is_prime,1,sizeof(is_prime));
    for(i=2;i<=200000;++i){
        if(is_prime[i]){
            for(j=i<<1;j<200000;j+=i){
                is_prime[j]=0;
            }
        }
    }
    for(i=0;i<n;++i){
        int temp;
        cin>>temp;
        ++cnt[temp];
    }
    while(i-->0){
        if(is_prime[sum-1]){
            b[i]=1;
            --cnt[1];
        }else if(cnt[2]>0){
            b[i]=2;
            --cnt[2];
        }else{
            break;
        }
    }
    ++i;
    while(i-->0){
        b[i]=1;
    }
    for(i=0;i<n;++i){
        printf("%d ",b[i]);
    }
    return 0;
}

