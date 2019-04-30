#include <stdio.h>
#include <set>
#include <map> 
using namespace std;
int a[1000000]={};
int main(){
	int i,j,k,total,now,p,min=1000000;
	set<int> idea;
	scanf("%d",&p);
	for(i=0;i<p;++i){
		scanf("%d",a+i);
		idea.insert(a[i]);
	}
	total=idea.size();
	i=j=now=0;
	map <int,int> points;
	while(j<p){
		while(j<p&&now<total){
			if(points[a[j]]++==0){
				++now;
			}
			++j;
		}
		while(i<p&&now==total){
			if(--points[a[i]]==0){
				--now;
			}
			++i;
		}
		if(j-i<min){
			min=j-i;
		}
	}
	printf("%d",min+1);
	return 0;
}

