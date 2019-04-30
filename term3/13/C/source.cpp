#include <stdio.h>
#include <string.h>
#define swap(A,B) {int temp=A;A=B;B=temp;}
#define debug(...) printf( __VA_ARGS__)

bool A[51][50];
int n,row=0,column=0;
void solve(void);
void gauss(void);
inline void print(){
    return;
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<=n;++j){
            printf("%d ",A[i][j]);
        }
        putchar('\n');
    }
    for(i=0;i<n;++i){
        printf("__");
    }
    putchar('\n');
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
void solve(void){
    int i,j,k;
    scanf("%d",&n);
    memset(A,0, sizeof(A));
    for(i=0;i<n;++i){
        int temp;
        scanf("%d",&temp);
        A[i][n]=temp;
    }
    for(i=0;i<n;++i){
        int temp;
        scanf("%d",&temp);
        if(temp==1)A[i][n]=!A[i][n];
    }
    do{
        scanf("%d%d",&i,&j);
        if(i==0||j==0)break;
        A[j-1][i-1]=1;
    }while(true);
    for(i=0;i<n;++i){
        A[i][i]=1;
    }
    print();
    gauss();
    //debug("rank:%d\n",rank);
    for(j=n-1;j>=row;--j){
        if(A[j][n]){puts("Oh,it's impossible~!!");return;}
    }
    printf("%d\n",1<<(n-row));
}
void gauss(void) {
    row = 0, column = 0;
    int i, j, k;
    for (column = 0; column < n; ++column) {
        for (i = row; i < n && A[i][column] == 0; ++i);
        if (i == n)continue;
        for (j = column; j <= n; ++j) {
            swap(A[i][j], A[row][j]);
        }
        while (++i < n) {
            if (A[i][column]) {
                for (j = column; j <= n; ++j) {
                    A[i][j] ^= A[row][j];
                }
                print();
            }
        }
        ++row;
    }
}
