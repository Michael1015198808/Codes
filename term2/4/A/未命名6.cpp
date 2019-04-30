#include <stdio.h>
#include <math.h>
#include <algorithm>


#define max(A,B) (A>B)?A:B
int main()  
{
  	const double eps=1e-9;  
	const double PI=acos(-1.0);  
	double h,l1,l2,r1,r2;  
	double v[205],g=9.8;  
    int i,num,n;
    while(scanf("%d",&n),n)  
    {  
        scanf("%lf%lf%lf%lf%lf",&h,&l1,&r1,&l2,&r2);  
        h*=19.6;
        for(i=0;i<n;i++)  
        {  
            scanf("%lf",&v[i]);  
        }  
        double a,add=PI/1000;  
        int ans=0;  
        for(a=-PI/2;a<=PI/2 ;a+=add){  
			num=0;
			double vx,vy1,vy2,t,x;  
    		for(i=0;i<n;i++){
				vx=v[i]*cos(a);
				vy1=v[i]*sin(a);
				vy2=sqrt(vy1*vy1+h);
				t=(vy1+vy2)/g;
				x=vx*t;
				if(x>=l2 &&x<=r2 ){
					num=0;
					break;
				}
				if(x>=l1 &&x<=r1 )
					num++;
			}
			if(num>ans){
				ans=num;
			}
        }
        printf("%d\n",ans);
    }
    return 0;  
}
