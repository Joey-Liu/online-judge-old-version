#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 10;
int ik, mo;				//input vars

struct matrix
{
	int a[maxn][maxn];
}origin, res;

matrix multiply(matrix x, matrix y)
{
	matrix temp;

	memset(temp.a, 0, sizeof(temp.a));
	
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			for (int k = 0; k < maxn; k++)
			{
				temp.a[i][j] += x.a[i][k] * y.a[k][j];
				temp.a[i][j] %= mo;
			}
		}
	}//for int i
	return temp;
}


void solve(int n)		//计算矩阵 n 次幂 res
{
	//res 初始化单位阵
	memset(res.a, 0, sizeof(res.a));
	for (int i = 0; i < maxn; i++)
		res.a[i][i] = 1;


	while (n)
	{
		if (n & 1)
			res = multiply(res, origin);
		n >>= 1;
		origin = multiply(origin, origin);
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int num[maxn];
	while (cin >> ik >> mo)
	{
		memset(origin.a, 0, sizeof(origin.a));
		for (int i = 0; i < maxn; i++)
			cin >> origin.a[0][i];

		for (int i = 1; i < maxn; i++)
			origin.a[i][i - 1] = 1;

		if (ik < 10)
		{
			cout << ik << endl;
			continue;
		}
		
		ik -= 9;
		solve(ik);
		
		int ans = 0;
		for (int i = 0; i < maxn; i++)
		{
			ans += res.a[0][i] * (9 - i);
			ans %= mo;
		}
		cout << ans << endl;
	}//while
	return 0;
}