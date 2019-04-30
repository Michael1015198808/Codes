#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int main(){
    int n,m,r,temp;
    int i,j,k;
    int in=10000,out=0;
    cin>>n>>m>>r;
    for(i=0;i<n;++i){
        scanf("%d",&temp);
        in=min(in,temp);
    }
    for(i=0;i<m;++i){
        scanf("%d",&temp);
        out=max(out,temp);
    }
    if(in<out){
        cout<<(r/in)*out+(r%in);
    }else{
        cout<<r;
    }
    return 0;
}
