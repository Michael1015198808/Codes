#include <stdio.h>
#include <stdlib.h>
void qsort(int* p,int,int);
int main(){
	int C,n,V,W,con[101]={0};
	int i,j,k,soluc,soluv;
	scanf("%d",&C);
	while(C--){
		soluc=0,soluv=0;
		scanf("%d%d%d",&n,&V,&W);
		for(i=0;i<n;++i){
			scanf("%d",con+i);
		}
		qsort(con,0,i-1);
		con[i]=100000000;
		j=0;
		while(soluc<=soluv*W){
			soluc+=con[j];
			++soluv;
			++j;
		}
		soluc-=con[j-1];
		--soluv;
		printf("%d ",soluv*V);
		if(soluv==0){
			printf("0.00\n");
		}else{
			printf("%.2lf\n",((double)soluc)/soluv/100.00);
		}
	}
}
void qsort(int a[], int low, int high)
{
    if(low >= high){
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];
    while(first < last){
        while(first < last && a[last] >= key){
            --last;
        }
        a[first] = a[last];
        while(first < last && a[first] <= key){
            ++first;
        }
        a[last] = a[first];
    }
    a[first] = key;
    qsort(a, low, first-1);
    qsort(a, first+1, high);
}
