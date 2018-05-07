//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//const int maxn = 100 + 10;
//
//int num[maxn], dp[maxn][maxn];
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	int m, n;
//	while (cin >> m >> n)
//	{
//		memset(dp, 0, sizeof(dp));
//		for (int i = 1; i <= n; i++)
//			cin >> num[i];
//		
//		//初始化 dp边界 即最大子串的dp
//		for (int i = 1; i <= n; i++)
//			dp[1][i] = num[i];
//		for (int i = 2; i <= n; i++)
//			dp[1][i] = max(dp[1][i - 1] + num[i], num[i]);
//		
//		//dp方程 dp[i][j] = max(dp[i][j - 1] + num[j], dp[i - 1][t] + num[j]) i - 1 <= t <= j - 1
//		int tmax = -0x7fffffff;
//		for (int i = 2; i <= m; i++)		//从 2 段开始
//		{
//			for (int j = i; j <= n; j++)
//			{
//				for (int t = i - 1; t <= j - 1; t++)
//				{
//					if (tmax < dp[i - 1][t] + num[j])
//						tmax = dp[i - 1][t] + num[j];
//				}
//				if (j > i && tmax < dp[i][j - 1] + num[j])	//当 j-1 < i 时(第一轮循环 j = i)，不用再次判断,因为在上面循环中已经判断过了
//					tmax = dp[i][j - 1] + num[j];
//				dp[i][j] = tmax;
//				tmax = -0x7fffffff;
//			}// for int j
//		}// for int i
//		cout << dp[m][n] << endl;
//	}//while
//
//	return 0;
//}


//主要思想 dp[][] 数组 在题目要求下是 开不出来的，
// dp[i][j] = max(dp[i][ j - 1],dp[i - 1][t]) + num[j]  i - 1 <= t <= j - 1
//想法是 由于每次求dp[i][j] 时 我们可以得到dp[i][t] i<= t <= j的最大值(就是dp[i][j])
//而这个值 在下一轮计算 dp[i + 1][j + 1] 的时候会使用到
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100000 + 5;
int num[maxn], pre_max[maxn];

int dp(int n,int m)
{
	int tmp = 0;
	for (int i = 1; i <= m; i++)
	{
		int tmp = 0;
		for (int k = 1; k <= i; k++)
			tmp += num[k];
		pre_max[n] = tmp;

		for (int j = i + 1; j <= n; j++)
		{
			tmp = max(pre_max[j - 1], tmp) + num[j];
			pre_max[j - 1] = pre_max[n];
			pre_max[n] = max(pre_max[n], tmp);
		}
	}//for int i
	return pre_max[n];
}


int main()
{
	int n, m;
	while (cin >> m >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			pre_max[i] = 0;
		}
		cout << dp(n, m) << endl;
	}
	return 0;
}

