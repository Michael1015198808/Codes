#include <stdio.h>
#include <algorithm>
using namespace std;

//I think this algorithm is easier & much faster
void solve();
char a[40][16];
int m,n,ans,cnt_odd,cnt_even;
void cut(int,int);
void dfs(int,int);
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
void solve(){
    int i,j,k;
    char c;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            do{
                c=getchar();
            }while(c!='o'&&c!='*');
            a[i][j]=c;
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            if(a[i][j]=='*'){
                cut(i,j);
            }
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            if(a[i][j]=='o'){continue;}
            cnt_odd=0;
            cnt_even=0;
            dfs(i,j);
            ans+=max(cnt_odd,cnt_even);
        }
    }
}
int dir[4][2]={-1,0,1,0,0,-1,0,1};
void cut(int x,int y){
    int cnt=0,i,j;
    int nx,ny;
    for(i=0;i<4;++i){
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(nx<0||nx>=n){
            continue;
        }
        if(ny<0||ny>=m){
            continue;
        }
        if(a[nx][ny]=='*'){
            ++cnt;
            j=i;
        }
    }
    if(cnt<2){
        ++ans;
        a[x][y]='o';
        if(cnt==1){
            a[x+dir[j][0]][y+dir[j][1]]='o';
            for(i=0;i<4;++i){
                nx=x+dir[j][0]+dir[i][0];
                ny=y+dir[j][1]+dir[i][1];
                if(nx<0||nx>=n){
                    continue;
                }
                if(ny<0||ny>=m){
                    continue;
                }
                if(i!=j&&a[nx][ny]=='*'){
                    cut(nx,ny);
                }
            }
        }
    }
}
void dfs(int x,int y){
    int i;
    int nx,ny;
    if((x+y)&1){
        cnt_odd++;
    }else{
        cnt_even++;
    }
    a[x][y]='o';
    for(i=0;i<4;++i){
        nx=x+dir[i][0];
        ny=y+dir[i][1];
                if(nx<0||nx>=n){
                    continue;
                }
                if(ny<0||ny>=m){
                    continue;
                }
        if(a[nx][ny]=='*'){
            dfs(nx,ny);
        }
    }
}