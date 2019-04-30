#include <stdio.h>
#include <algorithm>
using namespace std;
class cow{
public:
	int a,b;
	bool operator<(const cow &another)const{
		if(a<another.a)return true;
		else if(a==another.a){
			if(b>another.b)return true;
		}
		return false;
	}
};
cow a[25001];
int main(){
	int n,t,i,ans,nflag,flag;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;++i){
		scanf("%d%d",&a[i].a,&a[i].b);
	}
	ans=nflag=i=0;
	flag=0;
	while(flag<t){
		for(i=0;i<n;++i){
			if(a[i].a<=flag+1){
				if(a[i].b>nflag){
					nflag=a[i].b;
				}
			}
		}
		++ans;
//		printf("%d->%d\n",flag,nflag);
		if(nflag>flag){
			flag=nflag;
		}else{
			printf("-1");
			return 0;
		}
	}
	printf("%d",ans);
	
	return 0;
}
