#include<iostream>  
  
using namespace std;  
  
long long  cnt;  
  
void merge(int array[],int left,int mid,int right)  
{  
    int* temp=new int[right-left+1];  
    int i,j,p;  
    for(i=left,j=mid+1,p=0;i<=mid&&j<=right;p++)  
    {  
        if(array[i]<=array[j])temp[p]=array[i++];  
        else temp[p]=array[j++],cnt+=(mid-i+1);  
    }  
    while(i<=mid)temp[p++]=array[i++];  
    while(j<=right)temp[p++]=array[j++];  
    for(i=left,p=0;i<=right;i++)array[i]=temp[p++];  
    delete temp;  
}  
  
void mergesort(int array[],int left,int right)  
{  
    if(left==right)array[left]=array[right];  
    else  
    {  
        int mid=(left+right)/2;  
        mergesort(array,left,mid);  
        mergesort(array,mid+1,right);  
        merge(array,left,mid,right);  
    }  
}  
int main()  
{  
    int n,array[500005];  
    while(cin>>n,n)  
    {  
        cnt=0;  
        for(int i=0;i<n;i++)  
            cin>>array[i];  
        mergesort(array,0,n-1);  
            cout<<cnt<<endl;  
    }  
    return 0;  
}  
