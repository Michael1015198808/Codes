//E. Mission Probable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int num[105][105];
int out[105];
void upper();
void front();
void left();
int n,m;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            scanf("%d",&num[i][j]);
        }
    }
    upper();
    puts("");
    front();
    puts("");
    left();
    return 0;
}
void upper(){
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            putchar(num[i][j]==0?'.':'#');
        }
        putchar('\n');
    }
}
void front(){
    int temp=0;
    int i,j;
    memset(out,0,sizeof(out));
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            out[j]=max(out[j],num[i][j]);
            temp=max(temp,num[i][j]);
        }
    }
    for(i=temp;i>0;--i){
        for(j=0;j<m;++j){
            putchar(out[j]<i?'.':'#');
        }
        puts("");
    }
    return;
}
void left(){
    int temp=0;
    int i,j;
    memset(out,0,sizeof(out));
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            out[i]=max(out[i],num[i][j]);
            temp=max(temp,num[i][j]);
        }
    }
    for(i=temp;i>0;--i){
        for(j=0;j<n;++j){
            putchar(out[j]<i?'.':'#');
        }
        puts("");
    }
    return;
}
