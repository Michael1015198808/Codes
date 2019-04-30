#include <stdio.h>
#include <algorithm>

using namespace std;
class plant{
public:
	int x,y;
	bool operator<(const plant a)const{
		if(x<a.x){
			return true;
		}else if(x==a.x&&y<a.y){
			return true;
		}else{
			return false;
		}
	}
};
plant *col[5001]={},*temp;
plant paddy[5001];

int main(){
	int n,r,c,
		x,y,
		i,j,k,
		dx,dy,
		nx,ny,
		tempans=0,ans=2;
	bool flag;
	scanf("%d%d",&r,&c);
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d",&x,&y);
		paddy[i].x=x;
		paddy[i].y=y;
	}
	sort(paddy,paddy+n);
	for(i=1;i<=r;++i){
		col[i]=NULL;
	}
	for(i=n-1;i>=0;--i){
		col[paddy[i].x]=&paddy[i];
	}
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
//			printf("\n%d,%d;%d,%d",paddy[i].x,paddy[i].y,paddy[j].x,paddy[j].y);
			dx=paddy[j].x-paddy[i].x;
			dy=paddy[j].y-paddy[i].y;
			nx=paddy[i].x-dx;
			ny=paddy[i].y-dy;
			if(nx<=0||ny<=0||ny>=c);else{
				continue;
			}
			if((nx+ans*dx)>r){
				break;
			}
			tempans=0;
			nx+=dx;
			ny+=dy;
			while(nx>0&&nx<=r&&ny>0&&ny<=c){
				if(col[nx]==NULL){
					goto tag;
				}
				for(temp=col[nx];(*temp).x==nx&&(*temp).y<ny;++temp){
				};
				if((*temp).y==ny){
					++tempans;
					nx+=dx;
					ny+=dy;
				}else{
					goto tag;
				}
			}
			if(tempans>ans){
				ans=tempans;
			}
			tag:;
		}
	}
	if(ans>2){
		printf("%d",ans);
	}else{
		putchar('0');
	}
	return 0;
}
