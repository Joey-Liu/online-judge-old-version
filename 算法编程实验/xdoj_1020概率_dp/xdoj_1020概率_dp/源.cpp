#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 1000 + 5;
double dp[maxn][maxn];
double p[maxn];
int casenum, num, require;


void work()
{
	memset(dp, 0, sizeof(dp));
	dp[1][1] = p[1];
	dp[1][0] = 1 - p[1];

	for (int i = 2; i <= num; i++)
		dp[i][0] = dp[i - 1][0] * (1 - p[i]);

	for (int i = 2; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j < i)
				dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
			else
				dp[i][j] = dp[i - 1][j - 1] * p[i];
		}// for int j
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d%d", &num, &require);
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= num; i++)
			scanf("%lf", &p[i]);

		work();
		double ans = 0.0;
		for (int i = require; i <= num; i++)
			ans += dp[num][i];

		printf("%.4lf\n", ans);
	}

	return 0;
}