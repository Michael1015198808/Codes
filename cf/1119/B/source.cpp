#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int n,h;
int a[1000];
int main(){
    int i,j,k,ans;
    scanf("%d%d",&n,&h);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(ans=1;ans<=n;++ans){
        sort(a,a+ans);
        k=0;
        for(i=ans-1;i>=0;i-=2){
            k+=a[i];
        }
        if(k>h){
            --ans;
            break;
        }
    }
    if(ans>n)--ans;
    printf("%d\n",ans);
    return 0;
}

