#include <stdio.h>
int n;
int a[100],b[100];
int tree[100][100],index[100];
void fun(int,int,int,int);
int main(){
				scanf("%d",&n);
				int i,j;
				for(i=0;i<n;++i){
								scanf("%d",&a[i]);
								index[i]=0;
				}
				for(i=0;i<n;++i){
								scanf("%d",&b[i]);
				}
				fun(0,0,n,0);
				i=0;
				while(index[i]>0){
					for(j=0;j<index[i];++j,putchar(' ')){
						printf("%d",tree[i][j]);
					}
					puts("");
					++i;
				}
				return 0;
}
void fun(int al,int bl,int len,int depth){
				//printf("%d,%d,%d,%d,%d\n",al,bl,len,depth,a[al]);
				if(len==1){
					tree[depth][index[depth]++]=a[al];
					return;
				}
				int i;
				for(i=0;i<len;++i){
								if(a[al]==b[bl+i]){
												tree[depth][index[depth]++]=a[al];
												fun(al+1,bl,i,depth+1);
												fun(al+i+1,bl+i+1,len-i-1,depth+1);
												return;
								}
				}
}
