#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x2fffffff
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int main(){
    int a[3],b[3],i;
    for(i=0;i<3;++i){
        scanf("%d",&a[i]);
    }
    for(i=0;i<3;++i){
        scanf("%d",&b[i]);
    }
    int temp=0;
    for(i=0;i<3;++i){
        temp-=a[i]-b[i];
        if(temp<0){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
