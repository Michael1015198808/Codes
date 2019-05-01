//A. Coffee and Chicken
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char mat[100][100];
int cnt1=0,cnt2=0;
int m,n;
int direc[8][2]={
{1,0},
{1,1},
{0,1},
{-1,1},
{-1,0},
{-1,-1},
{0,-1},
{1,-1}
};
void judge(int i,int j){
    int di,l;
    for(di=0;di<8;++di){
        int x=i,y=j;
    for(l=0;l<strlen("COFFEE");++l){
        if(x>=0&&x<=n&&y>=0&&y<=m){
                if(mat[x][y]!="COFFEE"[l])break;
        //printf("123\n");
        }else{
        break;
        }
        x+=direc[di][0];
        y+=direc[di][1];
    }
    if(l==strlen("COFFEE"))cnt1++;
    }
    for(di=0;di<8;++di){
        int x=i,y=j;
    for(l=0;l<strlen("CHICKEN");++l){
        if(x>=0&&x<=n&&y>=0&&y<=m){
                if(mat[x][y]!="CHICKEN"[l])break;
        }else{
        break;
        }
        x+=direc[di][0];
        y+=direc[di][1];
    }
    if(l==strlen("CHICKEN"))cnt2++;
    }
}
int main(){
    int i,j,k,c;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
    for(j=0;j<m;++j){
        do{
        c=getchar();
        }while(c==' '||c=='\n');
        mat[i][j]=c;
    }
    }
    for(i=0;i<n;++i){
    for(j=0;j<m;++j){
        if(mat[i][j]=='C'){
        judge(i,j);
        }
    }
    }
    printf("COFFEE x %d\nCHICKEN x %d\n",cnt1,cnt2);
    return 0;
}
