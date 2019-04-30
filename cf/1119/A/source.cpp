#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int a[300000];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;++i){
        if(
                a[0]!=a[n-1-i]||
                a[i]!=a[n-1]
        )break;
    }
    printf("%d\n",n-1-i);
    return 0;
}

