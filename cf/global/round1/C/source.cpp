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
void solve(void);
int ans[]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main(){
    int n=0;
    scanf("%d",&n);
    while(n--){
        solve();
    }
    return 0;
}
void solve(void){
    int t;
    scanf("%d",&t);
    if(t&(t+1)){
        int i=1;
        while(i<t){
            i<<=1;
            ++i;
        }
        printf("%d\n",i);
    }else{
        int i=1,j=1;
        while(i<t){
            i<<=1;
            ++i;
            ++j;
        }
        //err("j:%d",j);
        printf("%d\n",ans[j]);
    }
    return;
}

