#include "stdio.h"
#include <stdlib.h>
char a[9][9],b[9][9];
/*	aÎªÆåÅÌ
	bÎª¼ÙÉèÇé¿ö					*/
char x,y;
/*	±éÀúÃ¿Ò»¸ö¹ý³ÌÖÐÈ·¶¨¸ñ×ø±ê	*/
char time;
/*	¼ÙÉè´ÎÊý					*/
char c[10],d[10];
/*	cÍ³¼ÆÊý×ÖÊÇ·ñ¿ÉÌî 
	dÍ³¼Æ¿ÉÌîÊý×Ö¸öÊý			*/
char over=0;
/*	over=1Ê±¼´ÌîÐ´Íê±Ï			*/
void fill(void);
void suppose(int mark);
void check(void);
int main()
{
	int tests=0;
	FILE *fp;
	fp=fopen("test.txt","r");
	for(tests=fgetc(fp),tests=tests-'0';tests>0;tests--){
		printf("%d\n",tests);
		for(x=0;x<9;x++){
			for(y=0;y<9;y++){
				if((a[x][y]=fgetc(fp))&&a[x][y]!='\n'){
					a[x][y]=a[x][y]-'0';
					b[x][y]=0;
				}
				else y--;
			}
		}
		fill();
		for(x=0;x<9;x++){
			for(y=0;y<9;y++){
				printf("%d",a[x][y]);
			}
			printf("\n");
		}
	}
	fclose(fp);
	return 0;
}





void fill(void)
{
	char flag1=0,flag2=81,i,j;
/*	flag1È·ÈÏÊÇ·ñÃ»ÓÐÒ»¶¨ÕýÈ·µÄÏî£¬	£¨1ËµÃ÷±¾´ÎÓÐÌîÐ´Ïî£¬0ËµÃ÷¼ÙÉè²ÅÄÜ¼ÌÐø
	flag2±ê¼ÇÎ´ÌîÐ´¸ñÎ»ÖÃ			£¨81ËµÃ÷ÌîÐ´Íê±Ï 
	 ijÑ­»·±äÁ
	 £¬d[]´ýÑ¡Ê
 ýÁÐ*/
	for(x=0;x<9;x++){
		for(y=0;y<9;y++){
			if(a[x][y]==0){
				for(i=0;i<10;i++){
					c[i]=0;
				}
				for(i=0;i<9;i++){
					c[a[i][y]]=1;
					c[a[x][i]]=1;
					c[a[x/3*3+i/3][y/3*3+i%3]]=1; 
				}
				for(i=1,j=0;i<10;i++){
					if(c[i]==0){
						d[j]=i;
						j++;
					}
				}
				if(j==1){
					a[x][y]=d[0];
					b[x][y]=time;
					flag1=1;
				}else flag2=x*9+y;
			}
		}
	}
	if(flag2!=81&&j>0){
		if(flag1==1)fill();
		else suppose(flag2);
	}else if(j==0)check();else over=1;
}





void suppose(int mark)
{
	time++;
	int i,j,l,r;
	int num=time;
	l=mark/9;
	r=mark%9;
	for(i=0;i<9;i++){
		c[a[i][r]]=1;
		c[a[l][i]]=1;
		c[a[l/3*3+i/3][r/3*3+i%3]]=1; 
		}
	for(i=1,j=0;i<10;i++){
		d[i]=0;
		if(c[i]==0){
		d[j]=i;
		j++;
		}
	}if (j==0){time--;check();}
	else
	for(i=0;over!=1&&d[i]!=0;i++){
		a[l][r]=d[i];
		b[l][r]=num;
		fill();
	}
	time--;
}




void check(void){
	int l,r;
	for(l=0;l<9;l++){
		for(r=0;r<9;r++){
			if(b[l][r]>time){
				a[l][r]=0;
				b[l][r]=0;
			}
		}
	}
}
