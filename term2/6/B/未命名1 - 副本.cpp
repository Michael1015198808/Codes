#include <stdio.h>
//#include <windows.h>
#define cor i*n+j
int find(int);

int father[2501]={},size[2501]={};
int main(){
	int m,n,i,j,k,l,temp,rooms=0,area=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			father[cor]=cor;
			size[cor]=1;
		}
	}
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			scanf("%d",&temp);
			if(!temp&8){
				father[cor]=find(cor+n);
				size[father[cor]]+=size[cor];
				size[cor]=0;
			}else if(!temp&4){
				father[cor]=find(cor+1);
				size[father[cor]]+=size[cor];
				size[cor]=0;
			}else if(!temp&2){
				father[cor]=find(cor-n);
				size[father[cor]]+=size[cor];
				size[cor]=0;
			}else if(!temp&1){
				father[cor]=find(cor-1);
				size[father[cor]]+=size[cor];
				size[cor]=0;
			}
		}
	}
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			if(father[cor]==cor){
				++rooms;
				if(size[cor]>area){
					area=size[cor];
				}
			}
		}
	}
	printf("%d\n%d",rooms,area);
	return 0;
}
int find(int i){
	if(father[i]==i){
		return i;
	}else{
		return father[i]=find(father[i]);
	}
}
