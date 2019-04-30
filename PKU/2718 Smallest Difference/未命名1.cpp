#include <stdio.h>

int search(int);

int a,b,ans;
bool d[10];
int main(){
	int n,i,j,k,cnt;
	char temp;
	scanf("%d",&n);
	getchar();
	while(n--){
		cnt=0;
		for(i=0;i<10;++i){
			d[i]=false;
		}
		while((temp=getchar())!='\n'){
			if(temp>='0'&&temp<='9'){
				d[temp-'0']=true;
				++cnt;
			}
		}
		ans=100000;
		a=b=0;
		if(cnt&1){
			for(i=0;i<10;++i){
				if(d[i]==true){
					d[i]=false;
					a[0]=2;
					a[1]=i;
					search(cnt/2);
					d[i]=true;
				}
			}
		}else{
			search(cnt/2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
int search(int to){
	int i,j,k;
	if(to==0){
		if((a[0]>2&&a[1]==0)||(b[0]>2&&b[1]==0)){
			return 0;
		}
		for(i=1,j=0;i<a[0];++i){
			j*=10;
			j+=a[i];
		}
		for(i=1,k=0;i<b[0];++i){
			k*=10;
			k+=b[i];
		}
		if(j-k>0){
			if(j-k<ans){
				ans=j-k;
			}
		}else{
			if(k-j<ans){
				ans=k-j;
			}
		}
	}else{
		for(i=0;i<10;++i){
			if(d[i]){
				d[i]=false;
				a[a[0]]=i;
				++a[0];
				for(j=0;j<10;++j){
					if(d[j]){
						d[j]=false;
						b[b[0]]=j;
						++b[0];
						search(to-1);
						d[j]=true;
						--b[0];
					}
				}
				d[i]=true;
				--a[0];
			}
		}
	}
	return 0;
}

