#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 20 * 20 + 150;
const int mod = 1000007;

int C[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for (int i = 0; i < maxn; i++)
	{
		C[i][0] = 1;
		C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;

	}

	int T, m, n ,k;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		scanf("%d%d%d", &m, &n, &k);
		int row = m, col = n, sum = 0, even = 0;//even 集合的个数
		for (int cnt = 0; cnt < 16; cnt++)
		{
			row = m; col = n; even = 0;
			if (cnt & 1)
			{
				even++;
				row--;
			}
			if (cnt & 2)
			{
				even++;
				row--;
			}
			if (cnt & 4)
			{
				even++;
				col--;
			}
			if (cnt & 8)
			{
				even++;
				col--;
			}

			if (even & 1)
				sum = (sum - C[row * col][k] + mod) % mod;
			else
				sum = (sum + C[row * col][k]) % mod;
		}
		printf("Case %d: %d\n", kase, sum);
	}//for int kase = 1

	return 0;
}