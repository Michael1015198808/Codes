#include <stdio.h>
#include <algorithm>
using namespace std;
struct inversion{
	int a,b;
	bool operator<(const inversion another)const{
		return a<another.a;
	}
};
int main(){
	char a[100][51];
	inversion list[100];
	int i,j,k,temp,
		n,m;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;++i){
		getchar();
		for(j=0;j<m;++j){
			a[i][j]=getchar();
		}
		a[i][m]='\0';
	}
	for(i=0;i<n;++i){
		temp=0;
		for(j=0;j	<m;++j){
			for(k=j+1;k<m;++k){
				if(a[i][j]>a[i][k]){
					++temp;
				}
			}
		}
		list[i].a=temp;
		list[i].b=i;
	}
	sort(list,list+n);
	for(i=0;i<n;++i){
		printf(a[list[i].b]);
		putchar('\n');
	}
	return 0;
}
