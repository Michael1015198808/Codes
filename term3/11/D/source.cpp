#include <stdio.h>

void solve();
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    int i,n;
    unsigned long long give=0,accept=0,given=0,new_give,new_accept;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d",&new_give,&new_accept);
        //New class give all its gifts
        if(new_give<accept-given){
            //First i-1 classes can accept all without replace
            
        }
    }
}