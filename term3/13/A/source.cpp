#include <stdio.h>
#include <string.h>
#define swap(A,B) {int temp=A;A=B;B=temp;}
#define debug(...) printf( __VA_ARGS__)
#define lamp(i,j) ((i)*6+j-7)
bool A[30][31],b[30][31];
int n=30,row=0,column=0;
void solve(void);
void gauss(void);
inline void print(void);
void init(void){
    int i,j;
    memset(b,0,sizeof(A));
    for(i=1;i<=5;++i){
        for(j=1;j<=6;++j){
            b[lamp(i,j)][lamp(i,j)]=1;
        }
    }
    //ifself
    for(i=2;i<=5;++i){
        for(j=1;j<=6;++j){
            b[lamp(i,j)][lamp(i-1,j)]=1;
        }
    }
    //up
    for(i=1;i<=4;++i){
        for(j=1;j<=6;++j){
            b[lamp(i,j)][lamp(i+1,j)]=1;
        }
    }
    //down
    for(i=1;i<=5;++i){
        for(j=2;j<=6;++j){
            b[lamp(i,j)][lamp(i,j-1)]=1;
        }
    }
    //left
    for(i=1;i<=5;++i){
        for(j=1;j<=5;++j){
            b[lamp(i,j)][lamp(i,j+1)]=1;
        }
    }
    //right
}
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
    init();
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;++i)printf("PUZZLE #%d\n",i),solve();
    return 0;
}
void solve(void){
    int i,j,k,temp;
    memcpy(A,b,sizeof(b));
    print();
    for(i=0;i<30;++i){
        scanf("%d",&temp);
        A[i][30]=temp;
    }
    gauss();
    for(i=1;i<=5;++i){
        for(j=1;j<=6;++j){
            printf("%d ",A[lamp(i,j)][30]);
        }
        putchar('\n');
    }
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
        for(i=0;i<n;++i){
            if (A[i][column]&&i!=row) {
                for (j = column; j <= n; ++j) {
                    A[i][j] ^= A[row][j];
                }
                print();
            }
        }
        ++row;
    }
}
