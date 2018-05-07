
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
const int dim = 3;
const int mode = 1000007;
struct matrix
{
	long long mat[dim][dim];
};

matrix tmp, origin, res;
long long a, b, c, n, first, second;
matrix mul(matrix x, matrix y)
{
	memset(tmp.mat, 0, sizeof(tmp.mat));
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int k = 0; k < dim; k++)
			{
				tmp.mat[i][j] += x.mat[i][k] * y.mat[k][j];
				tmp.mat[i][j] = (tmp.mat[i][j] + mode) % mode;
			}
		}
	}

	return tmp;
}

void init()
{
	origin.mat[0][0] = b; origin.mat[0][1] = a; origin.mat[0][2] = 1;
	origin.mat[1][0] = 1; origin.mat[1][1] = 0; origin.mat[1][2] = 0;
	origin.mat[2][0] = 0; origin.mat[2][1] = 0; origin.mat[2][2] = 1;

	memset(res.mat, 0, sizeof(res.mat));
	for (int i = 0; i < dim; i++)
		res.mat[i][i] = 1;

}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%lld%lld", &first, &second);
		scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
		if (n == 0)
		{
			printf("%lld\n", (second - first*b - c + mode) % mode);
			continue;
		}
		else if (n == 1)
		{
			printf("%lld\n", (first + mode) % mode);
			continue;
		}
		else if (n == 2)
		{
			printf("%lld\n", (second + mode) % mode);
			continue;
		}

		init();
		n -= 2;
		while (n)
		{
			if (n & 1)
				res = mul(res, origin);
			n = n >> 1;
			origin = mul(origin, origin);
		}

		long long ans = 0;
		ans = (first * res.mat[0][0] + mode) % mode;
		ans = (ans + second * res.mat[0][1] + mode) % mode;
		ans = (ans + c * res.mat[0][2] + mode) % mode;
		ans = (ans + mode) % mode;
		printf("%lld\n", ans);
	}//while

	return 0;
}