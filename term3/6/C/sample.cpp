#include <bits/stdc++.h>
#define maxn 300005
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll Pow[65],d[maxn];
ll n,m;
struct edge{
				    ll to,next;
						    ll a,b;
}q[maxn];
ll head[maxn];
ll cnt;
void init(){
				    for(int i=0;i<65;i++){
										        if(i==0) Pow[i]=1;
														        else Pow[i]=Pow[i-1]<<1;
																		    }
						    memset(head,-1,sizeof(head));
								    cnt=0;
}
void add_edge(ll from,ll to,ll a,ll b){
				    q[cnt].to=to;
						    q[cnt].a=a;
								    q[cnt].b=b;
										    q[cnt].next=head[from];
												    head[from]=cnt++;
}
void dijk(ll x){
				    memset(d,INF,sizeof(d));
						    priority_queue<PLL,vector<PLL>,greater<PLL> >que;
								    d[x]=1;
										    que.push(PLL(1,x));
												    while(!que.empty()){
																		        PLL p=que.top();
																						        que.pop();
																										        if(d[p.second]<p.first) continue;
																														        ll xx=p.second;
																																		        for(int i=head[xx];i!=-1;i=q[i].next){
																																										            ll to=q[i].to;
																																																            ll aa=q[i].a;
																																																						            ll bb=q[i].b;
																																																												            if(aa/p.first>=bb-1&&p.first+aa<d[to]){
																																																																						                d[to]=p.first+aa;
																																																																														                que.push(PLL(d[to],to));
																																																																																						            }
																																																																		        }
																																						    }
														    if(d[n]==INF){
																				        puts("-1");
																								    }
																    else{
																						        printf("%lld\n",(ll)log2(d[n]));
																										    }
}
int main()
{
				    int t;
						    scanf("%d",&t);
								    while(t--){
														        scanf("%d%d",&n,&m);
																		        init();
																						        for(int i=0;i<m;i++){
																														            ll a,b,c,d;
																																				            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
																																										            add_edge(a,b,c,Pow[d]);
																																																        }
																										        dijk(1);
																														    }
										    return 0;
}
