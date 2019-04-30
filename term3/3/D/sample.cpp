//0同类1鄙视2觉醒3佛系
#include <stdio.h>
#include <iostream>
#include <map>
#define initial rela[i].fa=i;\
rela[i].d=0;\
rela[i].pro=true;
using namespace std;
void solve(void);
int find(int);
void unite(int,int,int);
struct relation{
public:
	int fa;
	char d;
	bool pro;
};
relation rela[100000];
int main(){
	short t=0;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
void solve(void){
	map <string,int> list;
	int k=0,i=1,op=0,x=0,y=0;
	int cnt=0;
	string p,q;
	cin>>k;
	while(k--){
		cin>>op;
		if(op&2){
			cin>>p;
			if(list[p]==0){
							initial;
				list[p]=i++;
			}
			x=list[p];
			if(op&1){
//							cout<<"3\t"<<cnt<<endl;
				if(rela[x].pro==false){
					++cnt;
				}
			}else{
//							cout<<"2\t"<<cnt<<endl;
				if(rela[x].pro==true){
					++cnt;
				}else{
								initial;
					list[p]=i++;
				}
			}
		}else{
			cin>>p>>q;
			if(list[p]==0){
							initial;
				list[p]=i++;
			}
			x=list[p];
			if(list[q]==0){
							initial;
				list[q]=i++;
			}
			y=list[q];
			if(op&1){
//							cout<<"1\t"<<cnt<<endl;
				if(find(x)==find(y)){
					if((((rela[x].d-rela[y].d)%3)+3)%3!=1){
						++cnt;
					}
				}else{
					unite(x,y,1);
				}
			}else{
//							cout<<"0\t"<<cnt<<endl;
				if(find(x)==find(y)){
					if(rela[x].d!=rela[y].d){
						++cnt;
					}
				}else{
					unite(x,y,0);
				}
			}
		}
	}
	cout<<cnt<<endl;
//	cout<<"Name\tNo\tFa\td\tPro\n";
//	for(map<string,int>::iterator it=list.begin(); it!=list.end(); ++it){
//		cout<<it->first<<'\t'<<it->second<<'\t'<<rela[it->second].fa<<'\t'<<(int)rela[it->second].d<<'\t'<<rela[it->second].pro<<endl;
//	}
	return;
}
int find(int i){
	if(rela[i].fa==rela[rela[i].fa].fa){
		return rela[i].fa;
	}else{
		find(rela[i].fa);
		rela[i].d+=rela[rela[i].fa].d;
		rela[i].d%=3;
		return rela[i].fa=rela[rela[i].fa].fa;
	}
}
void unite(int x,int y,int delta){
	rela[x].pro=rela[y].pro=false;
	int i=find(x);
	rela[i].fa=find(y);
	rela[i].d=rela[y].d+delta-rela[x].d;
	rela[i].d%=3;
	if(rela[i].d<0)rela[i].d+=3;
}
