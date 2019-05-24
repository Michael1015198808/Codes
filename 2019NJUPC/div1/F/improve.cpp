//F. Neural Network
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define IN 300013
#define OUT 300014
class Node{
public:
    int to,cost;
    Node(int a,int b){to=a;cost=b;}
    bool operator<(const Node& n)const{
        return cost<n.cost;
    }
};
int read_node(void){
    int c,n;
    do{
        c=getchar();
    }while(c!='I'&&c!='H'&&c!='O');
    getchar();
    scanf("%d",&n);
    switch(c){
        case 'I':return n+000000;
        case 'H':return n+100005;//Small margin to prevent bug.
        case 'O':return n+200010;
    }
}
vector<Node>edges[300015];
int dis[300015];
int main(){
    int n,m,i,j;
    int n1,n2,w;
    memset(dis,0,sizeof(dis));
    scanf("%d\n",&m);
    for(i=0;i<m;++i){
        n1=read_node();n2=read_node();
        while(getchar()!='(');
        scanf("%d",&w);
        edges[n1].push_back(Node(n2,w));
    }
    priority_queue <Node> q;
    for(i=1;i<=100000;++i){
        q.push(Node(i,0x3f3f3f3f));
        edges[i+200000].push_back(Node(OUT,0x3f3f3f3f));
    }
    while(dis[OUT]==0){
        Node u=q.top();q.pop();
        if(dis[u.to]>u.cost)continue;
        dis[u.to]=u.cost;
        for(i=0;i<edges[u.to].size();++i){
            Node v=edges[u.to][i];
            v.cost=min(dis[u.to],v.cost);
            if(v.cost>dis[v.to]){
                dis[v.to]=v.cost;
                q.push(v);
            }
        }
    }
    printf("%d\n",dis[OUT]);
    return 0;
}
