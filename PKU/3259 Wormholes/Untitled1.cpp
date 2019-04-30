#include <stdio.h>
int path[501][501];
int time[501];
void solve(void);
int main(){
	int f;
	scanf("%d",&f);
	while(f--){
		solve();
	}
	return 0;
}
void solve(void){
	int i,j,k,temp,n,m,w;
	scanf("%d%d%d",&n,&m,&w);
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			path[i][j]=20000;
		}
		time[i]=5000000;
	}
	for(i=0;i<m;++i){
		scanf("%d%d%d",&j,&k,&temp);
		if(temp<path[j][k]){
			path[j][k]=temp;
		}
		if(temp<path[k][j]){
			path[k][j]=temp;
		}
	}
	for(i=0;i<w;++i){
		scanf("%d%d%d",&j,&k,&temp);
		if(-temp<path[j][k]){
			path[j][k]=-temp;
		}
	}
	time[1]=0;
	for(i=0;i<n;++i){
		for(j=1;j<=n;++j){
			for(k=1;k<=n;++k){
				if(time[j]+path[j][k]<time[k]){
					time[k]=time[j]+path[j][k];
				}
			}
		}
	}
	bool flag=false;
	for(j=1;j<=n;++j){
		for(k=1;k<=n;++k){
			if(time[j]+path[j][k]<time[k]){
				time[k]=time[j]+path[j][k];
				flag=true;
			}
		}
	}
	if(flag==true){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}
