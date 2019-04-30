#include <stdio.h>
//#include <windows.h>

void culculate(int,int,double);

int n,r;
bool taken[20]={};
double p[20]={},pc[20]={},pb=0.0;
int main(){
	int i,j,k=1
		;
	while(scanf("%d%d",&n,&r)==2){
		if(!n){
			break;
		}
		for(i=0;i<n;++i){
			scanf("%lf",p+i);
			taken[i]=false;
		}
		culculate(0,r,1.0);
		for(i=0;i<n;++i){
			pb+=pc[i];
		}
		printf("Case %d:\n",k);
		++k;
		if(pb!=0.0){
			pb/=r;
			for(i=0;i<n;++i){
				printf("%.6lf\n",pc[i]/pb);
			}
		}else{
			for(i=0;i<n;++i){
				printf("%.6lf\n",0.0);
			}
		}
		for(i=0;i<n;++i){
			pc[i]=0;
		}
		pb=0.0;
	}
	return 0;
}
void culculate(int no,int totake,double now){
	int i,j,k;
	if(no+totake>n){
		return;
	}
//	printf("%d\t%d\t%lf\n",no,totake,now);
//	system("pause");
	if(totake==0&&no==n){
		for(i=0;i<n;++i){
			if(taken[i]){
				pc[i]+=now;
			}
		}
		return;
	}
	culculate(no+1,totake,now*(1-p[no]));
	if(totake>0){
		taken[no]=true;
		culculate(no+1,totake-1,now*p[no]);
		taken[no]=false;
	}
	return;
}

