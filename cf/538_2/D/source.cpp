#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x2fffffff
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define update(A,B) A=min(A,B)
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int a[5000];
int cnt[2][5000][5000];
int dp(int mode,int l,int r){
//mode 0: c_l 1:c_r-1
//range [l,r)
    if(cnt[mode][l][r]!=0x3f3f3f3f){
        return cnt[mode][l][r];
    }
    if(l==r-1)return 0;
    if(mode==0){
        update(cnt[mode][l][r],dp(0,l+1,r)+1);
        update(cnt[mode][l][r],dp(1,l+1,r)+(a[l]!=a[r-1]));
    }else{
        update(cnt[mode][l][r],dp(1,l,r-1)+1);
        update(cnt[mode][l][r],dp(0,l,r-1)+(a[l]!=a[r-1]));
    }
    return cnt[mode][l][r];
}
int main(){
    int n=0,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
        if(i>0&&a[i]==a[i-1]){
            --i;--n;
        }
    }
    memset(cnt,0x3f,sizeof(cnt));
    for(i=0;i<n;++i){
        cnt[0][i][i]=cnt[1][i][i]=0;
    }
    printf("%d\n",min(dp(0,0,n),dp(1,0,n)));
    return 0;
}
