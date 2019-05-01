//A. Coffee and Chicken
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char mat[100][100];
int m,n;
int direc[8][2]={
{-1, 1},{ 0, 1},{ 1, 1},
{-1, 0},        { 1, 0},
{-1,-1},{ 0,-1},{ 1,-1}
};
int judge(int i,int j,int di,const char* s){
    for(int l=0;l<strlen(s);++l){
        if(!(i>=0&&i<n&&j>=0&&j<m)||mat[i][j]!=s[l])
            return 0;
        i+=direc[di][0];
        j+=direc[di][1];
    }
    return 1;
}
int count(const char* s){
    int ret=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(mat[i][j]==s[0])//Use 'C' is faster
                for(int di=0;di<8;++di)
                    ret+=judge(i,j,di,s);
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            do{
                mat[i][j]=getchar();
            }while(mat[i][j]==' '||mat[i][j]=='\n');
        }
    }
    printf("COFFEE x %d\nCHICKEN x %d\n",count("COFFEE"),count("CHICKEN"));
    return 0;
}
