#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 50000 + 20;
const int NINF = -1 << 30;
int m, v;

int weight[maxn], value[maxn];
int dp[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d%d", &m, &v);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &weight[i], &value[i]);
	
		for (int i = 1; i <= v; i++)
			dp[i] = NINF;
		dp[0] = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = weight[i]; j <= v; j++)
			{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		if (dp[v] < 0)
			printf("NO\n");
		else
			printf("%d\n", dp[v]);
	}
	return 0;
}