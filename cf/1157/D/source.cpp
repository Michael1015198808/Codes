#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int a[100000]={};
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    if(n<k*(k+1)/2){
        puts("NO");
        return 0;
    }
    n-=k*(k+1)/2;
    a[0]+=n/k;
    n%=k;
    int sum=a[0];
    for(i=1;i<k;++i){
        int temp=min(n/(k-i),i-1+sum);
        n-=temp*(k-i);
        a[i]+=temp;
        sum+=temp;
    }
    if(n>0){
        puts("NO");
        return 0;
    }
    puts("YES");
    sum=0;
    int test=0;
    for(i=0;i<k;++i){
        sum+=a[i];
        printf("%d ",i+1+sum);
        test+=i+1+sum;
    }
    printf("\ntest:%d\n",test);
}
