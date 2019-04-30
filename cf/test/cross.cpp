#include <stdio.h>
int cnt(node *p){
    int i,size=p->child.size();
    int ret;
    if(p->is_max){
        ret=INF;
        for(i=0;i<size;++i){
            ret=min(ret,cnt(V[p->child[i]]));
        }
    }else{
        ret=0;
        for(i=0;i<size;++i){
            ret+=cnt(V[p->child[i]]);
        }
    }
    return ret;
}
