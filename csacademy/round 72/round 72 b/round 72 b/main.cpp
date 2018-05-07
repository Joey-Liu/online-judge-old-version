#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 5000 + 100;

int road[maxn];
int dist[maxn][maxn], num, dp[maxn], pd[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> road[i + 1];
		dist[i][(i + 1) % num] = road[i];
		dist[(i + 1) % num][i] = road[i];
	}

	for (int i = 1; i < num; i++)
		dp[i] = dp[i - 1] + road[i];

	for (int i = num - 1; i >= 0; i--)
		pd[i] = pd[i + 1] + road[i + 1];
	pd[0] = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			int shun = dp[j] - dp[i];
			if (shun < 0)
				shun = -shun;
			int nishi = dp[i] + pd[j];
			if (nishi < 0)
				nishi = -nishi;
			dist[i][j] = min(shun, nishi);
			dist[j][i] = dist[i][j];
		}
	}

	int dis = 0, res = 0;
	for (int j = 1; j < num; j++)
	{
		if (dist[0][j] > dis)
			dis = dist[0][j];
	}

	for (int i = 1; i < num; i++)
	{
		int tmp_max = -1;
		for (int j = 0; j < num; j++)
		{
			if (i == j)
				continue;
			if (tmp_max < dist[i][j])
				tmp_max = dist[i][j];
		}//for
		if (tmp_max < dis)
		{
			dis = tmp_max;
			res = i;
		}
	}
	cout << res + 1 << endl;
	return 0;
}