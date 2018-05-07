#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;
const int maxn = 1000 + 10;
int f[maxn][maxn];
int m, n;

void work()
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i < maxn; i++)
		f[1][i] = i;

	for (int i = 1; i < maxn; i++)
	{
		f[i][1] = 1;
		f[i][0] = 0;
	}

	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			f[i][j] = 0x3f3f3f;
			for (int w = 1; w <= j; w++)
			{
				int tmp = max(f[i - 1][w - 1], f[i][j - w]) + 1;
				if (tmp < f[i][j])
					f[i][j] = tmp;
			}
		}
	}
}

int main()
{
	while (cin >> m >> n)
	{
		if (m > n)
			m = n;
		if (m >= ceil(log2(n + 1)))
		{
			cout << ceil(log2(n + 1)) << endl;
			continue;
		}
		work();
		cout << f[m][n] << endl;
	}
	return 0;
}