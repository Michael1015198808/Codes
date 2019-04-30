#include <stdio.h>

int list[100001];
bool flag[100001];
void solve(void);
int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		solve();
	}
	return 0;
}
void solve(void){
	int s,n,ans=0,
		i,j,k;
	scanf("%d%d",&s,&n);
	for(i=0;i<n;++i){
		scanf("%d",list+i);
	}
	for(i=0;i<s;++i){
		flag[i]=true;
	}
	for(i=0;i<n;++i){
		list[n]=list[i];
		for(j=i+1;list[j]!=list[i];++j);
		if(j==n){
		}else{
			if(j-i<s){
				if(i%s<j%s){
					for(k=0;k<i%s;++k){
						flag[k]=false;
					}
					for(k=j%s;k<n;++k){
						flag[k]=false;
					}
				}else{
					for(k=j%s;k<i%s;++k){
						flag[k]=false;
					}
				}
			}else if(j-i<2*s){
				if(i%s>j%s){
					for(k=0;k<j%s;++k){
						flag[k]=false;
					}
					for(k=i%s;k<n;++k){
						flag[k]=false;
					}
				}else{
					for(k=i%s;k<j%s;++k){
						flag[k]=false;
					}
				}
			}else{
				putchar('0');
				putchar('\n');
				return;
			}
		}
	}
	for(i=0,ans=0;i<s;++i){
		if(flag[i]){
			++ans;
		}
	}
	printf("%d",ans);
	putchar('\n');
	return;
}
