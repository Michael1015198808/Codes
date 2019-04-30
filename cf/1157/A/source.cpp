#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int main(){
    int n,cnt=0;
    int a[11]={};
    scanf("%d",&n);
    while(true){
        if(n<=10){
            if(a[n]==1){
                break;
            }else{
                a[n]=1;
            }
        }
        ++cnt;
        ++n;
        while(n%10==0)n/=10;
    }
    printf("%d\n",cnt);
    return 0;
}

