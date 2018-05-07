#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int maxn = 2;

struct node
{
	int mat[maxn][maxn];
};

node tmp, origan, res;
int n;

node multiply(node a, node b)
{
	memset(tmp.mat, 0, sizeof(tmp.mat));
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			for (int k = 0; k < maxn; k++)
			{
				tmp.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				tmp.mat[i][j] %= 10000;
			}
		}
	}

	return tmp;
}

void work(int num)		//¼ÆËã origan µÄnum ´ÎÃÝ
{
	memset(res.mat, 0, sizeof(res.mat));
	for (int i = 0; i < maxn; i++)
		res.mat[i][i] = 1;

	while (num > 0)
	{
		if (num & 1)
			res = multiply(res, origan);
		num >>= 1;
		origan = multiply(origan, origan);
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	
	while (1== scanf("%d", &n) && n >= 0)
	{
		if (0 == n || 1 == n)
		{
			printf("%d\n", n);
			continue;
		}
		origan.mat[0][0] = origan.mat[0][1] = origan.mat[1][0] = 1;
		origan.mat[1][1] = 0;

		work(n - 1);
		res.mat[0][0] %= 10000;
		printf("%d\n", res.mat[0][0]);
	}//while

	return 0;
}