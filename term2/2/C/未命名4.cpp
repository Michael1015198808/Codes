#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
struct cor{
	int x,y;
};
class hi{
public:
	long long a,b;
	bool operator <(const hi&i)const{return (a<i.a)||((a==i.a)&&(b<i.b));}
};
using std::vector;
int main(){
	cor f1,f2;
	vector <cor>flower;
	vector <hi>dis;
	cor tempc;
	hi temph;
	int i,j,n;
	unsigned long long r1=0,r2=0;
	unsigned long long ans=0,temp=0;
	scanf("%d%d%d%d%d",&n,&f1.x,&f1.y,&f2.x,&f2.y);
	for(i=0;i<n;++i){
		scanf("%d%d",&tempc.x,&tempc.y);
		flower.push_back(tempc);
		temph.a=pow(flower[i].x-f1.x,2)+pow(flower[i].y-f1.y,2);
		temph.b=pow(flower[i].x-f2.x,2)+pow(flower[i].y-f2.y,2);
		if(temph.a&&temph.b){
			dis.push_back(temph);
		}else{
			--i;
			--n;
		}
	}
	std::sort(dis.begin(),dis.end());
	ans=dis[n-1].a;
//	printf("%d",ans);
	r2=0;
	for(i=n-1;i>=0;--i){
		r1=dis[i].a;
		temp=r1+r2;
		if(temp<ans){
			ans=temp;
		}
//		printf("T%d\t%d\t%d\n",r1,r2,temp);
		if(dis[i].b>r2){
			r2=dis[i].b;
		}
	}
	if(r2<ans){
		ans=r2;
	}
	printf("%lld",ans);
}
/*
5 0 0 5 0
9 4
8 3
-1 0
1 4
0 0
*/
