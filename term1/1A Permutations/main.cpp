#include<iostream>
#include <stdio.h> 
using namespace std;

/*int power(int a,int x){
if (x>1){
   a=a*x*power(a,x-1);
   }
   return a;
}
substituted by loop*/
int main(){
	int n,m,a[10],time,x,pow,s;
	cin>>n>>m;
	for (int q = 0; q < m; q++){
	//Generate permutations m times
		for (int i = 1; i <= n; i++){
			a[i] = i;
		}
	//initialize array a
		cin>>time;
		time=time-1;
		for (int k=n-1; k>=1; k--){
			pow=1;
			for (int p=2;p<=k;p++){
				pow=pow*p;
			}
			x=time/pow;
			time=time-x*pow;
			//count what a[n-k] should be
			s=a[n-k+x];
			for(int j=n-k+x;j>n-k;j--){
				a[j]=a[j-1];
			}
			a[n-k]=s;
			// move a[n-k+x] to a[n-k], and move every element right
		}
		printf("{");
		for (int i=1;i<n;i++){
		printf("%d,",a[i]);}
		printf("%d}\n",a[n]);
		//output by format
	}
   return 0;
}
