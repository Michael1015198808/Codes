#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define rep(_A,_B,_C) for((_A)=(_B);(_A)<(_C);++(_A))
#define err(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
char s[3*100000+1];
void fail(void){
    puts(":(");
    exit(0);
}
int main(){
    int n,i,j,lc=0,rc=0;
    //lc:left count
    scanf("%d\n%s",&n,s);
    i=-1;j=n;
    while(i!=j-1){
        while(i!=j-1){
            ++i;
            if(s[i]==')'){
                --lc;
            }else{
                s[i]='(';
                ++lc;
            }
            if(lc>rc)break;
            if(lc<=0)fail();
        }
        while(i!=j-1){
            --j;
            if(s[j]=='('){
                --rc;
            }else{
                ++rc;
                s[j]=')';
            }
            if(lc==rc)break;
            if(rc<=0)fail();
        }
    }
    if(lc==rc)puts(s);
    else fail();
    return 0;
}

