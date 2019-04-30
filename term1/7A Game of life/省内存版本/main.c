#include <stdio.h>
#include <stdlib.h>
/*
参考致谢：王中杰 
0for dead→dead
1for life→life
3for life→dead
4for dead→life
%2=当前回合死活（ 1为生，0为死） 
%3=下一回合死活 （1为生，0为死 ） 
*/
int main() {
    char a[22][80],c,x,y,j,i,time;
    scanf("%d",&time);
    for(x=0;x<22;x++){
        for(y=0;y<80;y++){
            a[x][y]=0;
        }
    }
    c=getchar();
    x=0;
    for(j=0;j<22;j++){
        for(i=0;i<81;i++){
            c=getchar();
            if(c=='*')a[j][i]=1;
            else if(c=='\n')i=80;
            else if(c==EOF)	j=21;
        }
    }
    while(time>0){time--;
        for(j=0;j<22;j++){
            for(i=0;i<80;i++){
            			c=0-a[j][i];
                for(x=(j+21)%22;x!=(j+2)%22;x=(x+1)%22){
                	for(y=(i+79)%80;y!=(i+2)%80;y=(y+1)%80){
                		c=c+a[x][y]%2;
					}
				}
                if(a[j][i]==0){
                	if(c==3)
                	a[j][i]=4;
				}
                else if(c<2||c>3)a[j][i]=3;
            }
        }
        for(x=0;x<22;x++){
            for(y=0;y<80;y++){
                a[x][y]=a[x][y]%3;
            }
        }
    }
    for(i=0;i<22;i++){
        for(j=0;j<80;j++){
        	if(a[i][j]==0)	printf(" ");
        	else			printf("*");
		}
        printf("\n");
    }
    return 0;
}
