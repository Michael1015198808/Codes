#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int a[200005],cnt[200005]={},fa[200005];
int find(int idx){
    if(fa[idx]==fa[fa[idx]])return fa[idx];
    else return fa[idx]=find(fa[idx]);
}
void unite(int a,int b){
    fa[find(a)]=find(b);
}
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",&a[i]);
    for(i=1;i<=n;++i){
        int temp;
        scanf("%d",&temp);
        ++cnt[temp];
        fa[i]=i;
    }
    for(i=0;i<n;++i){
        int temp=(n-a[i])%n;
        while(cnt[find(temp)]==0){
            temp=find(temp);
            unite(temp,(temp+1)%n);
        }
        --cnt[fa[temp]];
        printf("%d ",(a[i]+fa[temp])%n);
    }
    return 0;
}

