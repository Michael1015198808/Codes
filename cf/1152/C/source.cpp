#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int main(){
    int i,a,b,d,ans=0,aaans=0,idx=0;
    scanf("%d%d",&a,&b);
    if(a>b){
        int temp=b;
        b=a;a=temp;
    }else if(a==b){
        printf("%d\n",0);
        return 0;
    }
    if(b%a==0){printf("0\n");return 0;}
    if(b>=2*a){
        for(int i=1;;++i){
            if((b-a)%(a+i)==0){
                printf("%d\n",i);
                return 0;
            }
        }
    }else{
        int q=(a-1)/(b-a)+1;
        printf("%d\n",q*(b-a)-a);
    }
    return 0;
}
