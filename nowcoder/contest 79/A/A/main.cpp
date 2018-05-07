#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <memory>
#include <memory.h>

const int maxn = 25;
using namespace std;
int N;
double li[4], res;
double dp[maxn];

const int year[4] = { 1, 2, 3, 5 };

void work()
{
	dp[0] = 1.0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int t = i - year[j];
			if (t < 0)
				continue;
			double r = dp[i - year[j]] * pow((1 + li[j]), year[j]);
			dp[i] = max(dp[i], r);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (1 == scanf("%d", &N))
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 0;i < 4;i++)
			scanf("%lf", &li[i]);
		work();
		printf("%.5f\n", dp[N]);
	}
}