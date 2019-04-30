#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int n;
long long h;
int a[20000],b[20000];

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
				int i,min,max,mid;
				priority_queue<int> choosen;
				scanf("%d",&n);
				cin>>h;
				for(i=0;i<n;++i){
								scanf("%d",a+i);
				}
				for(i=0;i<n;++i){
								scanf("%d",b+i);
				}
				for(i=0;i<n;++i){
								h+=a[i]-b[i];
								choosen.push(b[i]);
								while(h<=0&&choosen.size()>0){
												h+=choosen.top(),choosen.pop();
								}
								if(h<=0){
												printf("Bob will be unhappy!\n");
												return;
								}
				}
				cout<<choosen.size()<<' '<<h<<endl;
}
