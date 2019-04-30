#include <stdio.h>
#include <vector>
using std::vector;
vector<int> a;
int main(){
	int n,i,j,k,l,ans,temp,dx,dy;
	int x[700],y[700];
	bool on[700][700];
	while(scanf("%d",&n)&&n){
		ans=0;
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				on[i][j]=true;
			}
			scanf("%d%d",x+i,y+i);
		}
		for(i=0;i<n;++i){
			for(j=i+1;j<n;++j){
				if(on[i][j]){
					dx=x[i]-x[j];
					dy=y[i]-y[j];
					temp=0;
					a.clear();
					for(k=0;k<n;++k){
						if(dx*(y[k]-y[j])==dy*(x[k]-x[j])){
							a.push_back(k);
							++temp;
						}
					}
					if(temp>ans){
						ans=temp;
					}
					for(k=0;k<temp;++k){
						for(l=k;l<temp;++l){
							on[k][l]=false;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
