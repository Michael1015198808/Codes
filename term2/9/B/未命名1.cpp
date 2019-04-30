#include <stdio.h>
#include <algorithm>
using namespace std;
struct point{
	long x,y;
	bool operator<(const point &another)const{
		if(x<another.x){
			return true;
		}else if(x>another.x){
			return false;
		}
		return y<another.y;
	}
	bool operator==(const point &another)const{
		if(x==another.x&&y==another.y){
			return true;
		}
		return false;
	}
};
point midpoint[499500],node[1000];
void solve(void);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
void solve(void){
	int n,i,j,k=0,temp=0,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d",&node[i].x,&node[i].y);
	}
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
			midpoint[k].x=node[i].x+node[j].x;
			midpoint[k].y=node[i].y+node[j].y;
			++k;
		}
	}
	sort(midpoint,midpoint+k);
	for(i=1;i<k;++i){
		if(midpoint[i]==midpoint[i-1]){
			++temp;
		}else{
			ans+=temp*(temp+1)/2;
			temp=0;
		}
	}
	printf("%d\n",ans);
}

