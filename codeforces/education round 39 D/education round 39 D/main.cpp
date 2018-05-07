#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 500 + 10;

int dp[maxn][maxn];
int prefix[maxn];
char school[maxn][maxn];
int n, m, k;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> n >> m >> k)
	{
		memset(dp, -1, sizeof(dp));
		memset(dp[0], 0, sizeof(dp[0]));
		memset(school, 0, sizeof(school));
		for (int i = 1; i <= n; i++)
			cin >> school[i] + 1;


		for (int i = 1; i <= n; i++)
		{
			int mn[maxn];
			memset(mn, -1, sizeof(mn));
			memset(prefix, 0, sizeof(prefix));
			for (int j = 1; j <= m; j++)
			{
				prefix[j] = school[i][j] - '0';
				prefix[j] += prefix[j - 1];
			}

			if (prefix[m] <= k)
				mn[prefix[m]] = 0;
			for (int j = 1; j <= m; j++)
			{
				if ('0' == school[i][j])
					continue;
				for (int h = j; h <= m; h++)
				{
					if ('0' == school[i][h])
						continue;
					int interval = prefix[h] - prefix[j] + 1;
					int left_lesson = prefix[m] - interval;
					if (left_lesson > k)
						continue;
					if (-1 == mn[left_lesson] || mn[left_lesson] > h - j + 1)
						mn[left_lesson] = h - j + 1;
				}//for int h
			}//for int j
			

			for (int j = 0; j <= k; j++)
			{
				if (-1 == dp[i - 1][j])
					continue;
				for (int h = 0; j + h <= k; h++)
				{
					if (-1 == mn[h])
						continue;
					if (-1 == dp[i][j + h] || dp[i][j + h] > dp[i - 1][j] + mn[h])
						dp[i][j + h] = dp[i - 1][j] + mn[h];
				}
			}

		}//for int i
		int res = maxn * maxn;
		for (int i = 0; i <= k; i++)
		{
			if (-1 == dp[n][i])
				continue;
			res = min(res, dp[n][i]);
		}
		cout << res << endl;
	}//while
	return 0;
}