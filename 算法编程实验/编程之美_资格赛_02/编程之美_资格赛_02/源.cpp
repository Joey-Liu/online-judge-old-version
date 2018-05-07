#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 1050;
int dp[maxn][maxn];			//dp[i][j] 表示str[i..j]之间 回文子序列个数
char str[maxn];
int casenum, length;


void solve()
{
	for (int i = 0; i < length; i++)
		dp[i][i] = 1;


	for (int j = 0; j < length; j++)
	{
		for (int i = j - 1; i >= 0; i--)
		{
			if (str[j] == str[i])
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;		//加一是因为 回文子序列str[i,j]中间为空
			else
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(dp, 0, sizeof(dp));
	scanf("%d", &casenum);
	for (int cnt = 1; cnt <= casenum; cnt++)
	{
		scanf("%s", str);
		length = strlen(str);
		solve();
		printf("Case #%d: %d\n", cnt, dp[0][length - 1]);
	}
	return 0;
}