//F. Neural Network
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define I( _x) ( _x)
#define H( _x) ( _x+100000)
#define O( _x) ( _x+200000)
#define IN 300003
#define OUT 300004
class node{
public:
    int to,cost;
    bool operator<(const node& n)const{
        return cost<n.cost;
    }
};
vector<node>edges[300005];
bool visit[300005];
int dis[300005];
int main(){
    int n,m,i,j;
    int c1,c2,n1,n2,w;
    memset(visit,0,sizeof(visit));
    memset(dis,0,sizeof(dis));
    scanf("%d\n",&m);
    for(i=0;i<m;++i){
        do{
            c1=getchar();
        }while(c1!='I'&&c1!='H'&&c1!='O');
        getchar();
        scanf("%d",&n1);
        do{
            c2=getchar();
        }while(c2!='I'&&c2!='H'&&c2!='O');
        getchar();
        scanf("%d",&n2);
        int temp;
        do{
            temp=getchar();
        }while(temp!='(');
        scanf("%d",&w);
        switch(c1){
            case 'I':
                n1=I(n1);
                break;
            case 'H':
                n1=H(n1);
                break;
            case 'O':
                n1=O(n1);
                break;
        }
        switch(c2){
            case 'I':
                n2=I(n2);
                break;
            case 'H':
                n2=H(n2);
                break;
            case 'O':
                n2=O(n2);
                break;
        }
        node temp___;
        temp___.to=n2;
        temp___.cost=w;
        edges[n1].push_back(temp___);
    }
    priority_queue <node> q;
    for(i=1;i<=100000;++i){
        node temp;
        temp.to=i;
        temp.cost=0x3f3f3f3f;
        q.push(temp);
    }
    while(!q.empty()){
        node u=q.top();q.pop();
        if(dis[u.to]>u.cost)continue;
        dis[u.to]=u.cost;
        for(i=0;i<edges[u.to].size();++i){
            node v=edges[u.to][i];
            v.cost=min(dis[u.to],v.cost);
            if(v.cost>dis[v.to]){
                q.push(v);
            }
        }
    }
    int ans=0;
    for(i=1;i<=100000;++i){
        ans=max(ans,dis[O(i)]);
    }
    printf("%d\n",ans);
    return 0;
}
