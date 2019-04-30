#include <stdio.h>
#define MOD 999997
struct node{
	node* next;
	int num,cnt;
};
long pow(int,int);
int k[6],p[6];
node *hash[MOD]={};
int main(){
	int n,m,mmm,i,x[4],num,l=0;
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
		mmm=temp%MOD;
		node *p=hash[mmm],*q=hash[mmm];
		if(hash[mmm]==NULL){
			hash[mmm]=new node;
			p=hash[mmm];
			p->cnt=1;
			p->num=temp;
			p->next=NULL;
		}else{
			while(p!=NULL){
				if(p->num==temp){
					++p->cnt;
					break;
				}
				q=p;
				p=p->next;
			}
			if(p==NULL){
				q->next=new node;
				p=q->next;
				p->cnt=1;
				p->num=temp;
				p->next=NULL;
			}
		}
		++l;
		++x[num];
		while(num<half&&x[num]>m){
			x[num]=1;
			++num;
			++x[num];
		}
	}while(num<half);
	x[0]=x[1]=x[2]=1;
	do{
//		printf("%d %d %d",x[0],x[1],x[2]);
		num=0;
		for(temp=0,i=half;i<n;++i){
			temp-=k[i]*pow(x[i-half],p[i]);
		}
		mmm=(MOD+(-temp)%MOD)%MOD;
//		printf("%d %d\n",temp,mmm);
		temp=-temp;
		node *p=hash[mmm];
		while(p!=NULL){
			if(p->num==temp){
				ans+=p->cnt;
			}
			p=p->next;
		}
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

