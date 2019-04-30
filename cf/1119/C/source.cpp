#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int line[500],column[500];
int main(){
    int n,m,temp,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            scanf("%d",&temp);
            line[i]^=temp;
            column[j]^=temp;
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            scanf("%d",&temp);
            line[i]^=temp;
            column[j]^=temp;
        }
    }
    [&]{
        i=j=0;
        for(i=0;i<n;++i){
            if(line[i]&1)return;
        }
        for(j=0;j<m;++j){
            if(column[j]&1)return;
        }
    }();
    if(i==n&&j==m){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}

