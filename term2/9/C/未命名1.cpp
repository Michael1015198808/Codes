#include <stdio.h>
#include <algorithm>
using std::sort;
struct node{
	int x,y;
};
void solve(void);
bool vertical(const node&,const node&);
bool horizon(const node&,const node&);
node stone[131072];
int main(){
	int t;
	if(sizeof(int)==2){
		*(int*)0=0;
	}
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
void solve(void){
	int i,j,
		x,y,
		m,n,k,
		ans=0;
	scanf("%d%d%d",&m,&n,&k);
	for(i=0;i<k;++i){
		scanf("%d%d",&x,&y);
		stone[i].x=x;
		stone[i].y=y;
	}
	sort(stone,stone+k,vertical);
	for(i=0,x=1,y=0;i<k;++i){
		if(stone[i].x>x){
			ans+=stone[i].x-x-1;
			if(n-y>1){
				++ans;
			}
			x=stone[i].x;
			y=0;
		}
		if(stone[i].y-y>2){
			++ans;
		}
		y=stone[i].y;
	}
	ans+=m-x;
	if(n-y>1){
		++ans;
	}
	sort(stone,stone+k,horizon);
	for(i=0,x=0,y=1;i<k;++i){
		if(stone[i].y>y){
			ans+=stone[i].y-y-1;
			if(m-x>1){
				++ans;
			}
			y=stone[i].y;
			x=0;
		}
		if(stone[i].x-x>2){
			++ans;
		}
		x=stone[i].x;
	}
	ans+=n-y;
	if(m-x>1){
		++ans;
	}
	printf("%d\n",ans);
}
bool vertical(const node &a,const node &b){
	if(a.x<b.x){
		return true;
	}
	if(a.x>b.x){
		return false;
	}
	return a.y<b.y;
}
bool horizon(const node &a,const node &b){
	if(a.y<b.y){
		return true;
	}
	if(a.y>b.y){
		return false;
	}
	return a.x<b.x;
}
