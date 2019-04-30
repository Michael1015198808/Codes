#include <stdio.h>
#include <iostream>
#include <algorithm>
using std::pair;
using std::sort;
using std::min;

bool solve(void);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
					if(solve()){
									printf("Good Ending\n");
					}else{
									printf("Bad Ending\n");
					}
	}
	return 0;
}
bool solve(void){
				int n,a,b;
				int i,j,k;
				scanf("%d%d%d",&n,&a,&b);
				pair<int,int> enemys[10000];
				for(i=0;i<n;++i){
								scanf("%d%d",&enemys[i].first,&enemys[i].second);
				}
				sort(enemys,enemys+n);
				i=0;
				while(i<n){
								j=enemys[i].second;
								while(enemys[i].first<j&&i<n){
												++i;
												j=min(j,enemys[i].second);
								}
								if(a>=b){
								a-=b;
								}else{
								return false;
								}
				}
				return true;
}

