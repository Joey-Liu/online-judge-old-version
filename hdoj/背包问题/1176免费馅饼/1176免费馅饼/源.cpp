#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 10;
const int limit = 12;
int dp[maxn][15];				//dp[i][j]表示 从i，j开始到达底部 馅饼最多的数量
int pz[maxn][15];				//位置 i，j的馅饼数量

int n;
int x, y;
int mx;						//记录有馅饼 的最高层数
int tmp;

int max(int a, int b, int c)
{
	tmp = max(a, b);
	return max(tmp, c);
}

void work()
{
	for (int i = mx - 1; i >= 1; i--)
	{
		for (int j = 0; j < limit; j++)
		{
			if (j == 0)
			{
				dp[i][j] = pz[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
			}
			else if (j == 11)
			{
				dp[i][j] = pz[i][j] + max(dp[i + 1][j], dp[i + 1][j - 1]);
			}
			else
				dp[i][j] = pz[i][j] + max(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]);
		}//for intj
	}//for int i
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &n) && n > 0)
	{
		memset(dp, 0, sizeof(dp));
		memset(pz, 0, sizeof(pz));
		mx = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &y, &x);
			pz[x][y]++;
			if (mx < x)
				mx = x;
		}

		for (int i = 0; i < limit; i++)
			dp[mx][i] = pz[mx][i];
		work();
		int ans = max(dp[1][4], dp[1][5], dp[1][6]);
		printf("%d\n", ans);
	}//while
	return 0;
}