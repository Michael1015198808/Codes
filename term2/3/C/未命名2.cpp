#include <stdio.h>
//#include <windows.h>
#include <stdlib.h>
bool a[1500][1500];

int main(){
	int n,i,j,k,l,temp,max,maxid,ans;
	int b[1500];
	while(scanf("%d",&n)==1){
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				a[i][j]=0;
			}
		}
		for(l=0;l<n;++l){
			scanf("%d:(%d)",&i,&k);
			for(j=0;j<k;++j){
				scanf("%d",&temp);
				a[i][temp]=true;
				a[temp][i]=true;				
			}
		}
		ans=0;
		for(i=0;i<n;++i){
			b[i]=0;
			for(j=0;j<n;++j){
				if(a[i][j]){
					b[i]++;
				}
			}
		}
		while(1){
			maxid=-1;
			max=0;
			for(i=0;i<n;++i){
				if(b[i]==1){
					for(j=0;j<n;++j){
						if(a[i][j]){
							goto tag;
						}
					}
				}
			}
			break;
			tag:;
//			printf("%d\t",j);
			for(i=0;i<n;++i){
				if(a[i][j]){
					--b[i];
					--b[j];
					a[i][j]=0;
					a[j][i]=0;
				}
			}
			for(i=0;i<n;++i){
//				printf("%d\t",b[i]);
			}
//			printf("\n");
//			system("pause");
			++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
