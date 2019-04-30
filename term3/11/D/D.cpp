#include <stdio.h>
#define update(A,B) A=(A)>(B)?(B):(A)

void solve(void);
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
static inline void solve(void){
    int i,j=0,k=0,l=0,n;
    unsigned long long a=0,b=0;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d",&j,&k);
        if(j+k>l){
            l=j+k;
        }
        a+=j;
        b+=k;
    }
    update(a,a+b-l);
    update(a,b);
    printf("%lld\n",a);
}