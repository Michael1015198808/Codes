#include<cstdio>
#include<cstring>
#define mod 1000000
int a[1010];
int dp[1010][100010];//��ǰi��������ȡ��j����������� 
int main()
{
	int t,n,s,b,i,j,x;
	while(scanf("%d%d%d%d",&t,&n,&s,&b)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;++i)
		{
			scanf("%d",&x);
			a[x-1]++;//�������㣬�����ϱ�Ŵ�0���� 
		}
		for(i=0;i<=t;++i)//һ������ȡ�ķ���ֻ��һ�� 
			dp[i][0]=1;
		for(i=1;i<=t;++i)
		{
			for(j=1;j<=b;++j)
			{
				if(j-1-a[i-1]>=0)//�����������г��ָ��� 
					dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1-a[i-1]]+mod)%mod;
				else
					dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
			}
		}
		int ans=0;
		for(i=s;i<=b;++i)
			ans=(ans+dp[t][i])%mod;
		printf("%d\n",ans);
	}
	return 0;
}

