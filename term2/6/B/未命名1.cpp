#include <stdio.h>
//#include <windows.h>

int go(int,int);

bool way[50][50][4]={},test[50][50]={};
const char direc[4][2]={0,1,1,0,0,-1,-1,0};
int main(){
	int m,n,i,j,k,l,temp,rooms=0,area=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			scanf("%d",&temp);
			if(temp&8){
				way[i][j][1]=false;
			}else{
				way[i][j][1]=true;
			}
			if(temp&4){
				way[i][j][0]=false;
			}else{
				way[i][j][0]=true;
			}
			if(temp&2){
				way[i][j][3]=false;
			}else{
				way[i][j][3]=true;
			}
			if(temp&1){
				way[i][j][2]=false;
			}else{
				way[i][j][2]=true;
			}
//			printf("%d%d%d%d\n",way[i][j][0],way[i][j][1],way[i][j][2],way[i][j][3]);
		}
	}
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			if(!test[i][j]){
				test[i][j]=true;
				++rooms;
				temp=go(i,j);
				if(temp>area){
					area=temp;
				}
			}
		}
	}
	printf("%d\n%d",rooms,area);
	return 0;
}
int go(int x,int y){
//	printf("\npoint(%d,%d)\n",x,y);
//	system("pause");
	int sum=1,i,j,k;
	for(i=0;i<4;++i){
//		printf("%d%d%d\t",x,y,i);
		if(way[x][y][i]&&!test[x+direc[i][0]][y+direc[i][1]]){
			test[x+direc[i][0]][y+direc[i][1]]=true;
			sum+=go(x+direc[i][0],y+direc[i][1]);
		}
	}
	return sum;
}

