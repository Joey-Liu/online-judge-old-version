#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
const int maxn = 20 + 5;

double dp[maxn][maxn];
double poss[maxn];
int casenum, sum, require;

void work()
{
	memset(dp, 0, sizeof(dp));
	dp[1][1] = poss[1];
	dp[1][0] = 1 - poss[1];

	for (int i = 2; i <= sum; i++)
		dp[i][0] = dp[i - 1][0] * (1 - poss[i]);

	for (int i = 2; i <= sum; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j < i)
				dp[i][j] = dp[i - 1][j - 1] * poss[i] + dp[i - 1][j] * (1 - poss[i]);
			else
				dp[i][j] = dp[i - 1][j - 1] * poss[i];
		}
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d %d", &sum, &require);
		memset(poss, 0, sizeof(poss));
		for (int i = 1; i <= sum; i++)
			scanf("%lf", &poss[i]);

		work();
		double ans = 0.0;
		for (int k = require; k <= sum; k++)
			ans += dp[sum][k];

		printf("%.1lf\n", ans);

		int a = (int)(4.5);
		int b = (int)(-4.3);
		cout << a << "  " << b << endl;
	}

	return 0;
}