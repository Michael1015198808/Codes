#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100+10;
const int inf = 0x3fffffff;

int n,m,sx,sy,ans,cnt;
char map[MAXN][MAXN];
int vis[MAXN][MAXN][15][40];
int dir[4][2]={1,0,0,1,-1,0,0,-1};

struct Node{
    int x,y,key,status,step;
};

void bfs(){
    Node s;
    queue<Node> q;
    q.push((Node){sx,sy,0,0,0}); //初始状态压入队列
    while(!q.empty()){
        s=q.front();q.pop();
        int x=s.x,y=s.y,k=s.key,st=s.status,d=s.step; //中间变量，用于push值。
        if(k==m && map[x][y]=='D'){ //更新最小值
            ans=min(ans,d);
        }
        if(vis[x][y][k][st]!=0) continue; //访问过则继续下一次
        vis[x][y][k][st]=1;
        for(int i=0;i<4;++i){ //四个方向的标记
            int tx=x+dir[i][0];
            int ty=y+dir[i][1];
            int tmp=map[tx][ty]-'A'; //用来判断是否为蛇
            if(tmp>=0 && tmp<cnt){ //如果是蛇
                if((1<<tmp) & st)//如果第二次访问，则步长加1。这里判断方法是状态与tmp左移想与是否为1，
                    q.push((Node){tx,ty,k,st,d+1});
                else //如果第一次访问，则步长加2，将状态存为已经访问过,将该tmp置为奇数，保证tmp下一次左移后相与必为1
                    q.push((Node){tx,ty,k,(1<<tmp) | st,d+2});
            }
            else{
                if(map[tx][ty]==k+'1') //如果为当前钥匙的下一个钥匙，则钥匙加1，步长加1
                    q.push((Node){tx,ty,k+1,st,d+1});
                else if(tx>0 && tx<=n && ty>0 &&ty<=n && map[tx][ty]!='@') //否则其它可以访问的情况将步长加1
                    q.push((Node){tx,ty,k,st,d+1});
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&n,&m) && (n||m)){
        memset(map,0,sizeof(map)); //初始化
        memset(vis,0,sizeof(vis));
        cnt=0; //记录蛇的数量
        for(int i=1;i<=n;++i){
            scanf("%s",map[i]+1);
            for(int j=1;j<=n;++j){
                if(map[i][j]=='S'){
                    sx=i;sy=j;
                }
                if(map[i][j]=='J'){
                    map[i][j]='A'+cnt; //对蛇进行标号
                    ++cnt;
                }
            }
        }
        ans=inf;
        bfs();
        if(ans==inf) printf("gg\n");
        else printf("%d\n",ans);
    }
    return 0;
}
