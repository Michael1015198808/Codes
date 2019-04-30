#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,p,x,y,z;
   	int a[64];
    for (i=0;a[i-1]>-1;i++){
		scanf("%d",&a[i]);
	}
	i=i-1;
	char b[i][i];
	scanf("%d",&p);
	for(x=0;x<=i;x++){for(y=0;y<=i;y++){
	b[x][y]=0;
	}}
	
	while(p>0){
	scanf("%d %d",&x,&y);
	for (z=0;z<i;z++){
	if (a[z]==x){
	x=z;
	z=i;
	}
	}
	for (z=0;z<i;z++){
	if (a[z]==y){
	y=z;
	z=i;
	}
	}
	b[x][y]=1;
	p--;
	}
	

	
	for (p=0;p<i;p++){
	if (b[p][p]==0) p=i+1;
	}
	if (p==1) printf("reflexive\n");
    
p=1;
	for (x=0;x*p<i;x++){
		for (y=0;y*p<i;y++){
	if (b[x][y]-b[y][x]!=0) p=i+2;
    }}
	if (p==1) printf("symmetric\n");
	
	for (x=0,p=1;x*p<i;x++){for (y=0;y*p<i;y++){if (b[x][y]==1){
		for (z=0;z*p<1;z++){
			if (b[y][z]-b[x][z]==1)	p=i+2;
}}}}
    if (p==1) printf("transitive");
	return 0;
}
