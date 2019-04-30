#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
#include<string>
#include<stdio.h>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;
int n, s, flag, live, a[100000];
int b[100001];
int fuck(int a[], int j, int leng)
{
	int i, k;
	if (leng == 0 || leng == 1)
		return 0;
	memset(b, 0, sizeof(b));
	for (i = j; i < j + leng; i++)
	{
		if (b[a[i]])
		{
			return 1;
		}
		b[a[i]]++;
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int m, i, j, k, sum;
	cin >> m;
	for (i = 0; i < m; i++)
	{
		sum = 0;
		memset(a, 0, sizeof(a));
		cin >> s >> n;
		for (j = 0; j < n; j++)
			scanf("%d", &a[j]);
		{
			for (j = 1; j <= s; j++)
			{
				if (fuck(a, 0, j) == 0)
				{
					live = 1;
					for (k = j; k + s <= n&&live; k += s)
					{
						if (fuck(a, k, s))
						{
							live = 0;
						}
					}
					if (fuck(a, k, n - k))
						live = 0;
					if (live)
						sum++;
				}
				else
					j = s;
			}
		}
		if (s>n)
		if (fuck(a, 0, n) == 0)
			sum = s;
		cout << sum << endl;
	}
}
