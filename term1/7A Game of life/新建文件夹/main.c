#include <stdio.h>
#include <stdlib.h>
#define WIDE 30
#define HIGH 30
/*42 for " ";32 for " "*/
int main() {
    int c,time;
    char a[HIGH][WIDE],b[HIGH][WIDE],i,j,x,y,t;
    scanf("%d",&time);
    for(x=0;x<HIGH;x++){
        for(y=0;y<WIDE;y++){
            a[x][y]=32;
        }
    }
    c=getchar();
    for(j=0;j<HIGH;j++){
        for(i=0;i<=WIDE;i++){
            c=getchar();
            if(c!='\n')a[j][i]=c;
            else i=WIDE;
            if(c==EOF)j=HIGH;
        }
    }
	for(t=1;t<=time;t++){
        for(j=0;j<HIGH;j++){
            for(i=0;i<WIDE;i++){
            	c=0-a[j][i];
            	for(x=WIDE-1;x<WIDE+2;x++){
            		for(y=HIGH-1;y<HIGH+2;y++){
            			c=c+a[(j+y)%HIGH][(i+x)%WIDE];
					}
				}
 
 
 
                if(c==276)b[j][i]=a[j][i];
                else if(c==286)b[j][i]=42;
                else b[j][i]=32;
                 
            }
        }
        for(x=0;x<HIGH;x++){
            for(y=0;y<WIDE;y++){
                a[x][y]=b[x][y];
            }
        }
        printf("Generation:%d\n",t);
        for(i=0;i<HIGH;i++){
    		for(j=0;j<WIDE;j++){
            	printf("%c",a[i][j]);
        	}
        printf("\n");
    	}
        system("pause");
    }
    return 0;
}
