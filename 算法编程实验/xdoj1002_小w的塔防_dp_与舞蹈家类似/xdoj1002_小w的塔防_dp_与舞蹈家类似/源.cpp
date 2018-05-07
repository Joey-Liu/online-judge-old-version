#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

using namespace std;
const int maxn = 100 + 5;
typedef long long LL;

LL f[maxn][maxn][maxn];	
LL n, x, y, z, t, tmp;

LL theMax(LL a, LL b, LL c)
{
	tmp = a > b ? a : b;
	return c > tmp ? c : tmp;
}

void work()
{
	for (int sum = 1; sum <= n; sum++)
	{
		for (int i = 0; i <= sum; i++)
		{
			for (int j = 0; i + j <= sum; j++)
			{
				int k = sum - i - j;
				if (k < 0)
					break;

				LL a, b, c;
				if (0 == i)
					a = 0;
				else
					a = f[i - 1][j][k] + (i - 1) * y * (t + z * j);

				if (0 == j)
					b = 0;
				else
					b = f[i][j - 1][k] + i * y * (t + z * (j - 1));

				if (0 == k)
					c = 0;
				else
					c = f[i][j][k - 1] + i * y * (t + z * j) + x * (t + z * j);

				f[i][j][k] = theMax(a, b, c);
			}//for int j
		}//for int i
	}// for sum
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int a[100];
	memset(a, -1, sizeof(a));
	int b[200];
	memset(b, 0x3f3f3f3f, sizeof(b));
	int c[100];
	memset(c, 100, sizeof(c));
	while (5 == scanf("%lld %lld %lld %lld %lld", &n, &x, &y, &z, &t))
	{
		memset(f, 0, sizeof(f));
		work();
		LL ans = -1;

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; i + j <= n; j++)
			{
				int k = n - i - j;
				if (ans < f[i][j][k])
					ans = f[i][j][k];
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}