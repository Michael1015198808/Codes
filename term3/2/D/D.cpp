#include <stdio.h>
#include <algorithm>
using std::sort;
using std::min;
class spot{
public:
				int a,b;
}data[100000];
bool operator<(spot a,spot b){
				if(min(a.a,b.b)<min(a.b,b.a)){
								return true;
				}else if(min(a.a,b.b)==min(a.b,b.a)&&a.a<b.a){
								return true;
				}else{
								return false;
				}
}
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
				int n,i=0,j=0,k=0;
				scanf("%d",&n);
				for(i=0;i<n;++i){
								scanf("%d%d",&(data[i].a),&(data[i].b));
				}
				sort(data,data+n);
				for(i=0;i<n;++i){
								j+=min(k,data[i].a);
								k-=min(k,data[i].a);
								k+=data[i].b;
				}
				printf("%d\n",j);
}

