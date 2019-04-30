#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
				int n,i,k,l;
				unsigned long long cost=0,j;
				scanf("%d",&n);
				priority_queue<long long, vector<long long>, greater<long long> > a;
				for(i=0;i<n;++i){
								cin>>j;
								a.push(j);
				}
				if(!(a.size()&1)){
								a.push(0);
				}
				while(a.size()>1){
												j=a.top();a.pop();
												j+=a.top();a.pop();
												j+=a.top();a.pop();
												cost+=j;
												a.push(j);
				}
				cout<<cost;
				return 0;
}
