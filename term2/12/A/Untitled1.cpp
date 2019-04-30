#include <stdio.h>
#define MOD 999997
struct node{
	node* next;
	int num,cnt;
};
long pow(int,int);
int k[6],p[6];
node* hash[MOD]={};
int main(){
	int n,m,i,x[4],num,l=0;
	long temp,ans=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%d%d",k+i,p+i);
	}
	x[0]=x[1]=x[2]=x[3]=1;
	num=0;
	int half=n>>1;
	do{
		num=0;
		for(temp=0,i=0;i<half;++i){
			temp+=k[i]*pow(x[i],p[i]);
		}
		m=temp%MOD;
		node* p;
		if(hash[m]==NULL){
			hash[m]=new node;
			hash[m]->num=temp;
			hash[m]->cnt=1;
			hash[m]->next=NULL;
		}
		++l;
		++x[num];
		while(num<half&&x[num]>m){
			x[num]=1;
			++num;
			++x[num];
		}
	}while(num<half);
	sort(test,test+(int)pow(m,half));
	x[0]=x[1]=x[2]=1;
	do{
		num=0;
		for(temp=0,i=half;i<n;++i){
			temp-=k[i]*pow(x[i-half],p[i]);
		}
		ans+=upper_bound(test,test+(int)pow(m,half),temp)-lower_bound(test,test+(int)pow(m,half),temp);
		++x[num];
		while(num+half<n&&x[num]>m){
			x[num]=1;
			++num;
			++x[num];
		}
	}while(num+half<n);
	printf("%d",ans);
	return 0;
}
long pow(int a,int b){
	int k=1;
	while(b--){
		k*=a;
	}
	return k;
}

