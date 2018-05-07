//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>
//#include <algorithm>
//
//using namespace std;
//const int SPACE = 13000;
//const int KIND = 3450;
//
//int dp[KIND][SPACE];
//int w[KIND], d[KIND];
//int N, M;
//
//int work(int x, int y)		//前 x 件商品，空间为y
//{
//	if (-1 != dp[x][y])
//		return dp[x][y];
//
//	int ans = -1;
//	if (0 == x)				//边界
//	{
//		if (y >= w[x])
//			ans = d[x];
//		else
//			ans = 0;
//	}
//	else if (y < w[x])
//		ans = work(x - 1, y);
//	else
//		ans = max(work(x - 1, y), work(x - 1, y - w[x]) + d[x]);
//	
//	return dp[x][y] = ans;
//}
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	while (cin >> N >> M)
//	{
//		for (int i = 0; i < N; i++)
//			cin >> w[i] >> d[i];
//
//		memset(dp, -1, sizeof(dp));
//		cout << work(N - 1, M) << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 13000;
const int KIND = 3500;

int f[maxn];
int w[maxn], d[maxn];

int N, M;

void work()
{
	for (int i = 0; i < N; i++)
	{
		for (int v = M; v >= w[i]; v--)
		{
			f[v] = max(f[v], f[v - w[i]] + d[i]);
		}
	}// for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M)
	{
		for (int i = 0; i < N; i++)
			cin >> w[i] >> d[i];

		memset(f, 0, sizeof(f));
		work();
		cout << f[M] << endl;
	}
	return 0;
}