#include <stdio.h>
#include <stdlib.h>
char a[9][9],b[9][9];
/*	a为棋盘
	b为假设层数					*/
char x,y;
/*	遍历每一个过程中确定格坐标	*/
char time;
/*	假设次数					*/
char c[10],d[10];
/*	c统计数字是否可填 
	d储存待选可填数字			*/
char over;
/*	over=1时即填写完毕			*/
void fill(void);
void suppose(int mark);
void check(void);
int main()
{
	int tests;
	for(scanf("%d",&tests);tests>0;tests--){
		time=0;
		over=0;
		for(x=0;x<9;x++){
			for(y=0;y<9;y++){
				if((a[x][y]=getchar())&&a[x][y]!='\n'){
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
	return 0;
}





void fill(void)
{
	char flag1=0,flag2=81,i,j;
	char test1,test2;
/*	flag1确认是否没有一定正确的项，	（1说明本次有填写项，0说明假设才能继续
	flag2标记未填写格位置			（81说明填写完毕 
	 ij循环变量 
 */
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
	char i,j,l,r;
	char num=time;
	char e[10]; 
	l=mark/9;
	r=mark%9;
	for(i=0;i<9;i++){
		c[a[i][r]]=1;
		c[a[l][i]]=1;
		c[a[l/3*3+i/3][r/3*3+i%3]]=1; 
		}
	for(i=1,j=0;i<10;i++){
		e[i]=0;
		if(c[i]==0){
		e[j]=i;
		j++;
		}
	}if (j==0){time--;check();}
	else
	for(i=0;over!=1&&e[i]!=0;i++){
		check();
		a[l][r]=e[i];
		b[l][r]=num;
		fill();
	}
	time--;
}




void check(void){
	int l,r;
	for(l=0;l<9;l++){
		for(r=0;r<9;r++){
			if(b[l][r]>=time){
				a[l][r]=0;
				b[l][r]=0;
			}
		}
	}
}
1
510000600
000000040
023000071
000000003
700000198
001800752
000604020
600012500
009000000

