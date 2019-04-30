#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
char num[200005];
int mapping[11];
int main(){
    int n,i;
    scanf("%d\n",&n);
    scanf("%s",num);
    for(i=1;i<=9;++i){
        scanf("%d",&mapping[i]);
    }
    for(i=0;i<n-1;++i){
        if(num[i]<mapping[num[i]-'0']+'0')break;
    }
    /*if(i==n-1){
        num[i]=mapping[num[i]-'0']+'0';
        puts(num);
        return 0;
    }*/
    for(;i<n;++i){
        if(num[i]>mapping[num[i]-'0']+'0')break;
        num[i]=mapping[num[i]-'0']+'0';
    }
    puts(num);
    return 0;
}

