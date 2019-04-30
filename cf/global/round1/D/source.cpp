#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x2fffffff
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
#define update(_A,_B) _A=max(_A,_B)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solve(void);
int a[1000001]={};
int dp[1000001][3][3]={};
int main(){
    //int n=0;
    //scanf("%d",n);
    //while(n--){
        solve();
    //}
    return 0;
}
void solve(void){
    int n,m;
    int i,j,k,l;
    int temp;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        scanf("%d",&temp);
        ++a[temp];
    }
    for(i=1;i<=m+2;++i){
        for(j=0;j<3;++j){
            for(k=0;k<3;++k){
                //if(j+k>a[i-1])break;
                for(l=0;l<3;++l){
                    if(j+k+l>a[i-1])break;
                    update(dp[i][k][l],dp[i-1][j][k]+l+(a[i-1]-j-k-l)/3);
                }
            }
        }
    }
    /*while(scanf("%d%d%d",&i,&j,&k)==3){
        printf("%d\n",dp[i][j][k]);
    }*/
    temp=0;
    printf("%d",dp[m+2][0][0]);
    
    return;
}

