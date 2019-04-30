#include <stdio.h>
#include <string.h>
#define abs(_A) ((_A)>0?(_A):-(_A))
#define swap(A,B) {double temp=A;A=B;B=temp;}
#define debug(...) printf( __VA_ARGS__)
#define lamp(i,j) ((i)*6+j-7)
double A[100][101];
int n=30,row=0,column=0;
void solve(void);
void gauss(void);
inline void print(void);
inline void print(){
    return;
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<=n;++j){
            printf("%.2lf ",A[i][j]);
        }
        putchar('\n');
    }
    for(i=0;i<n;++i){
        printf("__");
    }
    putchar('\n');
}
int main(){
    int i,t;
    solve();
    return 0;
}
void solve(void){
    int i,j,k,temp;
    int m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        for(j=0;j<=n;++j){
            A[i][j]=0.0;
        }
    }
    for(i=0;i<m;++i){
        scanf("%d%d%d",&j,&k,&temp);
        double delta=(double)1/temp;
        A[j-1][k-1]-=delta;
        A[j-1][j-1]+=delta;
        A[k-1][j-1]-=delta;
        A[k-1][k-1]+=delta;
    }
    A[0][n]=1;
    A[n-1][n]=-1;
    print();
    gauss();
    print();
    printf("%.2lf\n",A[0][n]/A[0][0]);
}
void gauss(void) {
    row = 0, column = 0;
    int i, j, k;
    for (column = 0; column < n; ++column) {
        for (i = row; i < n && abs(A[i][column]) < 1e-5; ++i);
        if (i == n)continue;
        for (j = column; j <= n; ++j) {
            swap(A[i][j], A[row][j]);
        }
        for(i=0;i<n;++i){
            if (abs(A[i][column])>1e-5&&i!=row) {
                for (j = column+1; j <= n; ++j) {
                    A[i][j] -= A[row][j]/A[row][column]*A[i][column];
                }
                A[i][column]=0;
                print();
            }
        }
        ++row;
    }
}
