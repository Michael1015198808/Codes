#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solve(void);
int main(){
    //int n=0;
    //scanf("%d",n);
    //while(n--){
        solve();
    //}
    return 0;
}
void solve(void){
    int b,k,i,j;
    int a[100000];
    const char *ans[]={"even","odd"};
    scanf("%d%d",&b,&k);
    rep(i,0,k){
        scanf("%d",&a[i]);
    }
    err("%d,%d\n",b,b&1);
    if((b&1)==0){
        puts(ans[a[k-1]&1]);
    }else{
        int p=0;
        rep(i,0,k){
            p^=a[i];
        }
        puts(ans[p&1]);
    }
    return;
}
