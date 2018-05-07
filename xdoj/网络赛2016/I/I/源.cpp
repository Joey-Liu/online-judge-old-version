#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
const int maxn = 1000 + 10;
const int INF = 1 << 30;

int wi[maxn], vi[maxn];
int w, n;
int dp[maxn * maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (2 == scanf("%d%d", &n, &w))
	{
		int valMaxn = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &wi[i], &vi[i]);
			valMaxn += vi[i];
		}

		for (int i = valMaxn; i > 0; i--)
			dp[i] = INF;
		dp[0] = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = valMaxn; j >= vi[i]; j--)
			{
				dp[j] = min(dp[j], dp[j - vi[i]] + wi[i]);
			}
		}

		for (int i = valMaxn; i >= 0; i--)
		{
			if (dp[i] <= w)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}