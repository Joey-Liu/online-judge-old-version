#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long LL;
const int maxn = 101;
LL c[maxn][maxn];

void init()
{
	for (int i = 0; i < maxn; i++)
		c[i][0] = 1;

	for (int i = 1; i < maxn; i++)
	{
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int n, m;
	while ((EOF != scanf("%d%d", &n, &m)) && (n || m))
	{
		printf("%d things taken %d at a time is %d exactly.\n", n, m, c[n][m]);
	}
	return 0;
}