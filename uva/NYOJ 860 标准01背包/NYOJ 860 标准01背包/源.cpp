#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100 + 10;
const int INF = 1 << 30;

int wi[maxn], vi[maxn];
int w, n;
int dp[maxn * maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//不同于一般的01背包， 这里把价值固定来求相应的最小重量注意这类背包问题的初始条件
	while (cin >> n >> w)
	{
		int valMaxn = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> wi[i] >> vi[i];
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
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}