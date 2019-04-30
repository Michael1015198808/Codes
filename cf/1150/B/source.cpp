#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
char pat[55][55];
int n;
int direc[4][2]={
{1,0},
{1,-1},
{1,1},
{2,0}
};
void judge(){
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(pat[i][j]=='.'){
                pat[i][j]='#';
                for(int k=0;k<4;++k){
                    int newx=i+direc[k][0];
                    int newy=j+direc[k][1];
                    if(newx>=0&&newx<n&&newy>=0&&newy<n&&pat[newx][newy]=='.'){
                        pat[newx][newy]='#';
                    }else{
                        return;
                    }
                }
            }
        }
    }
    cout<<"YES";
    exit(0);
}
int main(){
    int i;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>pat[i];
    }
    judge();
    cout<<"NO"<<endl;
    return 0;
}

