#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
#define maxn = 3*100000+1;
using namespace std;
struct node{
    bool is_max;
    vector <int> child;
}V[maxn];
int global_cnt=0;
int min_cnt(node *p){
    if(p->is_max==1){
        return 0;
    }else{
        int i,j,ret=0;
        j=p->child.siz3e();
        for(i=0;i<j;++i){
            ret+=min_cnt(V[p->child[i]]);
        }
        global_cnt+=ret;
        return ret;
    }
}
int max_path(node *p){
    int i,j,k;
    int (*f)(node*);
    if(p->is_max){
        f=max_path;
    }else{
        f=min_cnt;
    }
    int ret=INF;
    for(i=0;i<j;++i){
        ret=min(ret,min_cnt(V[p->child[i]]));
    };
    return ret;
}
int main(){
    printf("%d\n",global_cnt-max_path(root));
    return 0;
}

