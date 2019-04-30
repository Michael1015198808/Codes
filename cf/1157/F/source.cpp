#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int cnt[200005]={};
class{
public:
    int sum,l,r;
}ans={0,0,0};
int main(){
    int n,i,l,r,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int temp;
        scanf("%d",&temp);
        ++cnt[temp];
    }
    cnt[200002]=100;
    for(l=0;cnt[l]==0;++l);
    while(l<=200000){
        sum=cnt[l];
        for(r=l+1;cnt[r]>=2;++r)sum+=cnt[r];
        sum+=cnt[r];
        if(sum>ans.sum){
            ans.sum=sum;
            ans.l=l;
            ans.r=r;
        }
        for(l=r;cnt[l]==0;++l);
    }
    printf("%d\n",ans.sum);
    for(i=ans.l;i<ans.r;++i){
        printf("%d ",i);
    }
    ++cnt[i];
    for(i=ans.r;i>=ans.l;--i){
        while(--cnt[i]){
            printf("%d ",i);
        }
    }
    return 0;
}

