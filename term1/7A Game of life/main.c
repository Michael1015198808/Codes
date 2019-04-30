#include <stdio.h>
#include <stdlib.h>
/*42 for " ";32 for " "*/
int main() {
    int c,time;
    char a[22][80],b[22][80],i,j,x,y;
    scanf("%d",&time);
    for(x=0;x<22;x++){
        for(y=0;y<80;y++){
            a[x][y]=32;
        }
    }
    c=getchar();
    for(j=0;j<22;j++){
        for(i=0;i<81;i++){
            c=getchar();
            if(c!='\n')a[j][i]=c;
            else i=80;
        }
    }
    while(time>0){time--;
        for(j=0;j<22;j++){
            for(i=0;i<80;i++){
                c=a[(j+21)%22][(i+79)%80]+a[(j+21)%22][i]+a[(j+21)%22][(i+1)%80]+
                  a[j][(i+79)%80]                        +a[j][(i+1)%80]+
                  a[(j+1)%22][(i+79)%80] +a[(j+1)%22][i] +a[(j+1)%22][(i+1)%80];
 
 
 
                if(c==276)b[j][i]=a[j][i];
                else if(c==286)b[j][i]=42;
                else b[j][i]=32;
                 
            }
        }
        for(x=0;x<22;x++){
            for(y=0;y<80;y++){
                a[x][y]=b[x][y];
            }
        }
    }
    for(i=0;i<22;i++){
        for(j=0;j<80;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
