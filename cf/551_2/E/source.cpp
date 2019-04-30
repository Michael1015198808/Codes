#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
int main(){
    vector<int> x,y;
    int n,i,j,temp;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        printf("? %d %d %d %d\n",i,1,i,n);
        fflush(stdout);
        scanf("%d",&temp);
        if(temp&1){
            x.push_back(i);
        }
    }
    for(j=1;j<=n;++j){
        printf("? %d %d %d %d\n",1,j,n,j);
        fflush(stdout);
        scanf("%d",&temp);
        if(temp&1){
            y.push_back(j);
        }
    }
    if(x.size()==0||y.size()==0){
        if(x.size()==0){
            int low=1,up=n;
            while(low!=up){
                int mid=(low+up)>>1;
                printf("? %d %d %d %d\n",low,y[0],mid,y[0]);
                fflush(stdout);
                scanf("%d",&temp);
                if(temp&1){
                    up=mid;
                }else{
                    low=mid+1;
                }
            }
            printf("! %d %d %d %d\n",low,y[0],low,y[1]);
        }else{
            int low=1,up=n;
            while(low!=up){
                int mid=(low+up)>>1;
                printf("? %d %d %d %d\n",x[0],low,x[0],mid);
                fflush(stdout);
                scanf("%d",&temp);
                if(temp&1){
                    up=mid;
                }else{
                    low=mid+1;
                }
            }
            printf("! %d %d %d %d\n",x[0],low,x[1],low);
        }
    }else{
        printf("? %d %d %d %d\n",x[0],y[0]);
        fflush(stdout);
        scanf("%d",&temp);
        temp&=1;
        printf("! %d %d %d %d\n",x[0],y[temp],x[1],y[1-temp]);
    }
    return 0;
}

