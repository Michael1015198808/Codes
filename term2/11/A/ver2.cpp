#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
int n1,n2,n;
int score[5000000];
void random_selection(int,int,int);
int partition_small(const int,const int);
int partition_big(const int,const int);
int main(int argc,char *argv[]){
	srand(time(NULL));
	int i,j,k,q,left,right,no;
	long long sum=0;
	while(scanf("%d%d%d",&n1,&n2,&n)==3){
		if(n==0){
			break;
		}
		for(i=0;i<n;++i){
			scanf("%d",score+i);
		}
		left=0;
		right=n;
		no=n2;
		while(true){
			q=partition_small(left,right);
//			printf("%d,%d,%d,%d\n",left,right,no,q);
			if(q>no){
				right=left+q;
			}else if(q<no){
				left+=q;
				no-=q;
			}else{
				break;
			}
		}
		left=n2;
		right=n;
		no=n1;
		while(true){
//			printf("%d,%d,%d,%d\n",left,right,no,q);
			q=partition_big(left,right);
			if(q>no){
				left=right-q;
			}else if(q<no){
				right-=q;
				no-=q;
			}
			else{
				break;
			}
		}
//		for(i=0;i<n;++i){
//			printf("%d ",score[i]);
//		}
		sum=0;
		for(j=n2;j<n-n1;++j){
//			printf("%d ",score[j]);
			sum+=score[j];
		}
		printf("%.6lf\n",((double)sum)/(n-n1-n2));
	}
	return 0;
}
int partition_small(const int left,const int right){
	int i,j,k,temp;
	k=rand()%(right-left)+left;
	swap(score[k],score[right-1]);
	for(i=left,j=left;j<right;++j){
		if(score[j]<=score[right-1]){
			swap(score[i],score[j]);
			++i;
		}
	}
	return i-left;
}
int partition_big(const int left,const int right){
	int i,j,k,temp;
	k=rand()%(right-left)+left;
//	printf("%d %d ",k);
	swap(score[k],score[left]);
	for(i=right-1,j=right-1;j>=left;--j){
		if(score[j]>=score[left]){
			swap(score[i],score[j]);
			--i;
		}
	}
	return right-i-1;
}

