#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
vector <int> ans;
int main(){
    uint64_t n,i=40;
    scanf("%d",&n);
    while(2**i>n)){
        --i;
    }
    --i;
    while(i>1){
        if((n>>i)&1){
            ans.push_back(i);
            n^=(1<<i)-1;
            ++n;
        }
        --i;
    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size()-1;++i){
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[ans.size()-1]);
    return 0;
}

