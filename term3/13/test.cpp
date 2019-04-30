#include <stdio.h>
#include <string.h>
#define swap(A,B) {int temp=A;A=B;B=temp;}
#define debug(...) printf( __VA_ARGS__)

bool A[51][50];
int n=5,rank=5;
void solve(void);
void gauss(void);
void print(void);
int main(){
    int t;
    solve();
    return 0;
}
void solve(void){
    int i,j,k;
    memset(A,0, sizeof(A));
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            int temp;
            scanf("%d",&temp);
            A[i][j]=temp;
        }
    }
    print();
    gauss();
    debug("rank:%d\n",rank);
}
void gauss(void){
    int i,j,k,l;
    for(i=0;i<n;++i){
        for(j=i-n+rank;A[j][i]==0&&j<n;++j);
        if(j==n){--rank;continue;}
        for(k=i;k<n+1;++k)swap(A[i][k],A[j][k]);
        for(k=j+1;k<n;++k){
            if(A[k][i]){
                for(l=i;l<n+1;++l){
                    A[k][l]^=A[j][l];
                }
    print();
            }
        }
    }
}
void print(){
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<n+1;++j){
            printf("%d ",A[i][j]);
        }
        putchar('\n');
    }
        putchar('\n');
}
