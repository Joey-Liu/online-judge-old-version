#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <iomanip>

using namespace std;

const int maxn = 10000 + 100;
double dp[maxn];			//dp[i][j] 表示前i个学校 投了j美元 所得的最小失败率
							// dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - ci] * pi)

int N, M;
int cost[maxn];
double poss[maxn];

double min(double a, double b)
{
	if (a>b)
		return b;
	return a;

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//cin >> N >> M;
	while( ~scanf("%d%d", &N, &M), N + M)//输入的问题
	{
		for (int i = 0; i <= N; i++)
			dp[i] = 1.0;

		for (int i = 1; i <= M; i++)
		{
			cin >> cost[i] >> poss[i];
			poss[i] = 1 - poss[i];
		}

		/////////////////////////////////////////////////
		
		/////////////////////////////////////////////////
		for (int i = 1; i <= M; i++)
		{
			for (int j = N; j >= cost[i]; j--)
			{
				dp[j] = min(dp[j], dp[j - cost[i]] * poss[i]);
			}
		}

		double ans = 1 - dp[N];
		printf("%.1lf%%\n", ans * 100);
		//cin >> N >> M;
	}
	return 0;
}