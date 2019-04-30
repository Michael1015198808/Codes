#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x2fffffff
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int cnt=60,n;
int get_up(void){
    int up=1e9,down=n-1;
    while(up!=down){
        --cnt;
        int mid=(up+down)>>1;
        int yes;
        printf("> %d\n",mid);fflush(stdout);
        scanf("%d",&yes);
        if(yes){
            down=mid+1;
        }else{
            up=mid;
        }
    }
    return up;
}
int gcd(int a,int b){
    if(b>a)return gcd(b,a);
    if(b==0)return a;
    return gcd(b,a%b);
}
int get_d(void){
    int a[60],i=0,j,k;
    while(--cnt){
        printf("? %d\n",(rand()%n)+1);fflush(stdout);
        scanf("%d",&a[i]);
        ++i;
    }
    int d=abs(a[1]-a[0]);
    for(j=0;j<i;++j){
        for(k=0;k<j;++k){
            d=gcd(d,abs(a[k]-a[j]));
        }
    }
    return d;
}
int main(){
    srand(time(NULL));
    scanf("%d",&n);
    int up=get_up(),d=get_d();
    printf("! %d %d\n",up-d*(n-1),d);fflush(stdout);
    return 0;
}
