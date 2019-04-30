//solved by dynamic programming
#include <stdio.h>
#include <vector>
//#include <windows.h>
using std::vector;
struct hello{
	int a,b;
//面积，买房数
	long long state[5];
//买房状态 
};
struct house{
	int a,b;
//面积，价格 
};
hello dp[1001]={};
vector<house> a[5]={};
char test[]="pause";
int main(){
	int i,j,k,x,z,s,delay=0;
	house temp={};
	for(i=0;i<5;++i){
		while(scanf("%d",&x)){
			if(x==-1){
				break;
			}
			temp.a=x;
			a[i].push_back(temp);
		}
	}
	for(i=0;i<5;++i){
		j=0;
		while(scanf("%d",&x)){
			if(x==-1){
				break;
			}
			a[i][j].b=x;
			++j;
		}
	}
	for(i=0;i<5;++i){
		for(j=0;j<1001;++j){
			dp[j].b=0;
		}
		s=a[i].size();
		for(j=0;j<s;++j){
			for(k=0;k<1001-a[i][j].b;++k){
//				printf("%d\t%d\t%d\t%d\t%d\t",i,j,k,dp[k].a,dp[k+a[i][j].b].a+a[i][j].a);
				if(dp[k+a[i][j].b].b<2&&(dp[k].a<dp[k+a[i][j].b].a+a[i][j].a)){
					dp[k].a=dp[k+a[i][j].b].a+a[i][j].a;
					dp[k].b=dp[k+a[i][j].b].b+1;
					for(z=0;z<5;z++){
						dp[k].state[z]=dp[k+a[i][j].b].state[z];
					}
					dp[k].state[i]|=(1<<j);
				}
/*				printf("%d\n",dp[k].a);
				if(delay==0){
					system("pause");
					scanf("%d",&delay);
				}
				--delay;
*/			}
		}
	}
	for(i=0,j=0;i<1001;++i){
		if(dp[i].a>dp[j].a){
			j=i;
		}
	}
	printf("%d\n",dp[j].a);
	for(i=0;i<5;++i){
		for(k=0;k<a[i].size();++k){
//			printf("%d\t",dp[j].state[i]);
//			printf("%d\t",1<<k);
			printf("%d",(bool)(dp[j].state[i]&(1<<k)));
//Two mistakes were made here.
//1. without右边的括号，something interesting will happen. 
//2. remember the difference between & and &&
		}
		printf("\n");
//		system(test);
	}
	return 0;
}
/*
My own test:
200 200 200 200 200 200 200 200 -1
200 200 200 200 200 200 200 200 200 -1
199 200 200 200 200 200 200 200 200 -1
200 200 200 200 200 200 200 200 -1
200 200 200 200 200 200 200 200 200 -1
600 600 600 600 600 600 600 600 -1
300 300 300 300 600 600 600 600 600 -1
200 300 600 600 600 600 600 600 600 -1
600 600 600 600 600 600 600 600 -1
100 600 600 600 600 600 600 600 600 -1
*/
