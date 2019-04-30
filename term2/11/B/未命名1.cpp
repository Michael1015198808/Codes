#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <map>  
#include <queue>  
using namespace std;  
const int MAXN=2000+10;  
const int inf=0x3f3f3f;  
int a[MAXN],b[MAXN],c[MAXN];  
int n,m;  
void del()  
{  
    int i,j;  
    priority_queue<int>q;  
    for(i=0;i<n;++i)//先读入n个元素  
    {  
        q.push(a[i]+b[0]);  
    }  
    for(i=1;i<n;++i)//维护队列  
    {  
        for(j=0;j<n;++j)  
        {  
            int x=a[j]+b[i];  
            if(x<q.top())//如果比最大值还小，就进队，大的出队  
            {  
                q.pop();  
                q.push(x);  
            }  
            else break;//否则的话，后面一定都比x大的，所以直接break  
        }  
    }  
  
    for(i=0;i<n;++i)  
    {  
        a[n-1-i]=q.top();//更新a数组  
        q.pop();  
    }  
  
}  
int main()  
{  
    int t;  
    int i,j;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&m,&n);  
        for(j=0;j<n;++j)scanf("%d",&a[j]);  
        sort(a,a+n);  
        for(i=1;i<m;++i)  
        {  
            for(j=0;j<n;++j)scanf("%d",&b[j]);  
            sort(b,b+n);  
            del();  
        }  
        for(i=0;i<n-1;++i)printf("%d ",a[i]);  
        printf("%d\n",a[n-1]);  
    }  
    return 0;  
}  
