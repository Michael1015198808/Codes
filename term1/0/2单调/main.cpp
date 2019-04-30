#include <iostream>
using namespace std;
int main(){
int m;
m=0;
char c;
int n[100];
int a[100];
int b[100];
printf("PLZ input the sequence of distinct integers\n");
for(int i=1;i<100;i++){
cin>>n[i];
char c = cin.get(); 
m=m+1;
a[i]=1;
b[i]=1;
if (c=='\n') break;
}
       for(int i=m-1;i>0;i--){
           for(int d=i+1;d<=m;d++){
           if (n[i]<=n[d]) {
               if (a[i]<=a[d]) a[i]=a[d]+1;}
           if (n[i]>=n[d]) {
               if (b[i]<=b[d]) b[i]=b[d]+1;}
       }
}
printf("the length of the longest monotone subsequence is ");
if (a[1]>b[1]) printf("%d",a[1]);
else printf("%d",b[1]);
}
