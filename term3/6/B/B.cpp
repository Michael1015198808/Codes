#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#define squ(x) pow((x),2)
const double INF=1e5;
const double eps=1e-9;
using namespace std;
class edge{
public:
				double cost;
				int to;
};
bool operator<(edge a,edge b){
				return a.cost<b.cost;
}
class point{
public:
				double x,y;
				point(double a,double b){
								x=a,y=b;
				}
};
double a[22][4],x[22],dis[82];
bool judge(point p,point q){
				int i=0;
				while(x[i]<p.x+eps){++i;}
				while(x[i]<q.x-eps){
								double y=(p.y-q.y)*(x[i]-p.x)/(p.x-q.x)+p.y;
								if(
																((a[i][0]<y+eps)&&(y-eps<a[i][1]))||
																((a[i][2]<y+eps)&&(y-eps<a[i][3]))
								){
												++i;
												continue;
								}
								return false;
				}
				return true;
}

int main(){
				int n,i,j,k;
				scanf("%d",&n);
				vector <vector<edge> >path(4*n+2);
				for(i=0;i<n;++i){
								cin>>x[i]>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
								path[(i<<2)+1].push_back({
																a[i][1]-a[i][0],
																(i<<2)
																});
								path[(i<<2)].push_back({
																a[i][1]-a[i][0],
																(i<<2)+1
																});
								path[(i<<2)+3].push_back({
																a[i][3]-a[i][2],
																(i<<2)+2
																});
								path[(i<<2)+2].push_back({
																a[i][3]-a[i][2],
																(i<<2)+3
																});
				}
				for(i=0;i<4*n+2;++i){
						dis[i]=INF;
				}
						for(j=0;j<n;++j){
								for(k=0;k<4;++k){
									if(judge({0,5},{x[j],a[j][k]})){
										path[0].push_back({
														sqrt(
														squ(5-a[j][k])
														+
														squ(0-x[j])
														),
														(j<<2)+k+1
														});
									}
								}
						}
										if(judge({0,5},{10,5})){
													path[0].push_back({
																		10,
																		4*n+1,
														});
										}
				for(i=0;i<n;++i){
								for(j=i+1;j<n;++j){
												for(k=0;k<16;++k){
															if(judge({x[i],a[i][k>>2]},{x[j],a[j][k&3]})){
																		path[(i<<2)+(k>>2)+1].push_back({
																										sqrt(
																										squ(a[i][k>>2]-a[j][k&3])
																										+
																										squ(x[i]-x[j])
																										),
																										(j<<2)+(k&3)+1
																										});
																		path[(j<<2)+(k&3)+1].push_back({
																										sqrt(
																										squ(a[i][k>>2]-a[j][k&3])
																										+
																										squ(x[i]-x[j])
																										),
																										(i<<2)+(k>>2)+1
																										});
															}
												}
								}
												for(k=0;k<4;++k){
																if(judge({x[i],a[i][k]},{10,5})){
																			path[(i<<2)+k+1].push_back({
																										sqrt(
																										squ(a[i][k]-5)
																										+
																										squ(x[i]-10)
																										),
																										4*n+1
																										});
																}
												}
				}
				priority_queue<edge> q;
				q.push({0,0});
				while(!q.empty()){
								int a=q.top().to;
								double b=q.top().cost;
								q.pop();
								if(b-eps>dis[a]){
												continue;
								}
								dis[a]=b;
								for(i=0;i<path[a].size();++i){
												if(path[a][i].cost+b<dis[path[a][i].to]){
																q.push({
																								dis[path[a][i].to]=path[a][i].cost+b,
																								path[a][i].to});
												}
								}
				}
				printf("%.2lf\n",dis[(n<<2)+1]);
				return 0;
}
