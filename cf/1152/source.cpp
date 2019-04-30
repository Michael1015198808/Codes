#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int a[2]={},b[2]={};
int main(){
    int n,m,i;
    int temp;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        scanf("%d",&temp);
        a[temp&1]++;
    }
    for(i=0;i<m;++i){
        scanf("%d",&temp);
        b[temp&1]++;
    }
    printf("%d\n",min(a[0],b[1])+min(a[1],b[0]));
    return 0;
}

