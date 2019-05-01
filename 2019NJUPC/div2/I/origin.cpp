//I. Welcome Party
#include <map>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define update(A,B) A=min(A,B)
#define INF (2000000000000000000)
using namespace std;
struct Student{
public:
    int64_t a,b;
    bool operator<(const Student &s)const{
        return b==s.b?a>s.a:b<s.b;
    }
}stu[300005];
map<int64_t,int>stat;
int main(){
    int64_t n,i,j,a=-INF,b,ans=INF;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>stu[i].a>>stu[i].b;
        ++stat[stu[i].a];
    }
    sort(stu,stu+n);
    i=n;
    while(i-->0){//Beautiful grammar
        //a:= max(stu[i+1,...,n-1].a)
        b=stu[i].b;
        --stat[stu[i].a];
        if(a>b)break;
        auto iter=stat.upper_bound(b);
        auto upper=iter,lower=iter;
        while(upper->second==0&&upper!=stat.end())++upper;
        if(upper!=stat.end()){
            ans=min(ans,abs(upper->first-b));
        }
        do{--lower;}while(lower!=stat.begin()&&lower->second==0);
        if(lower->second!=0){
            ans=min(ans,abs(lower->first-b));
        }
        a=max(a,stu[i].a);
        ++stat[stu[i].a];
    }
    cout<<min(ans,abs(b-a))<<endl;
    return 0;
}
