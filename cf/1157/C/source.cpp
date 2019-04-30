#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int n,a[200005],idx=-1;
char s[200005];
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    int last=0,l=0,r=n-1;
    while(l<=r){
        if(last<a[l]&&(a[l]<a[r]||a[r]<last)){
            last=a[l];
            ++l;
            s[++idx]='L';
        }else if(last<a[r]&&(a[r]<a[l]||a[l]<last)){
            last=a[r];
            --r;
            s[++idx]='R';
        }else if(a[l]==a[r]&&last<a[l]){
            int ans1=0,ans2=0;
            for(i=l;;++i){
                if(a[i]<=a[i-1])break;
            }
            ans1=i-l;
            for(i=r;;--i){
                if(a[i]<=a[i+1])break;
            }
            ans2=r-i;
            if(ans1>ans2){
                for(i=0;i<ans1;++i){
                    s[++idx]='L';
                }
            }else{
                for(i=0;i<ans2;++i){
                    s[++idx]='R';
                }
            }
            break;
        }else{
            break;
        }
    }
    printf("%d\n",++idx);
    puts(s);
    return 0;
}

