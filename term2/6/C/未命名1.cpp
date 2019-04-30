#include<cstdio>
#include<map>
class bone{
public:
	int state;
	char num;
	bone(void){
		state=0;
		num=0;
	}
};
using namespace std;
const int maxn=24;
map<int,bone> table;
int	bitcount(int x){return x==0?0:bitcount(x>>1)+(x&1);}

int	main(){
	int	n,mid,next,i,j,k,temp,ans;
	bone given[maxn],toput;
	char count,anss;
	char s[1000];
	while(scanf("%d",&n)==1&&n){
		getchar();
		for(i=0;i<n;++i){
			while((temp=getchar())!='\n'&&temp!=EOF){
				temp-='A';
				given[i].state+=1<<(temp);
			}
		}
		table.clear();
		mid=n/2;
		temp=1<<mid;
		
		for(i=0;i<temp;++i){
			k=0;
			count=0;
			for(j=0;j<mid;++j){
				if(i&(1<<j)){
					k^=given[j].state;
					++count;
				}
			}
			if(table[k].num<count){
				toput.state=i;
				toput.num=count;
				table[k]=toput;
			}
		}
		ans=0;
		anss=0;
		next=mid+(n&1);
		temp=1<<next;
		for(i=0;i<temp;++i){
			k=0;
			count=0;
			for(j=0;j<next;++j){
				if(i&(1<<j)){
					k^=given[mid+j].state;
					++count;
				}
			}
			if(table.count(k)&&bitcount(ans)<table[k].num+count){
				ans=(i<<mid)^table[k].state;
				anss=table[k].num+count;
			}
		}
		printf("%d\n",anss);
		for(i=0;i<n;++i){
			if(ans&(1<<i))printf("%d ",i+1);
		}
		printf("\n");
	}
	return	0;
}
