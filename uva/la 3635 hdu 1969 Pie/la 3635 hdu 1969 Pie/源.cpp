#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int maxn = 10000 + 10;
const double pi = acos(-1);

int ra[maxn];
double square[maxn];
int n, f;

bool valid(double x)
{
	if (x <= 0.0)
		return false;
	int res = 0;
	for (int i = 0; i < n; i++)
		res = res + int(square[i] / x);

	if (res < f + 1)
		return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int casenum = 0;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d%d", &n, &f);
		double rp= 0.0, mid = 0.0, lp = 0.0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &ra[i]);
			square[i] = pi * ra[i] * ra[i];
			rp = max(rp, square[i]);
		}

		while (rp - lp > 1e-5)
		{
			mid = (rp + lp) / 2;
			if (valid(mid))
				lp = mid;
			else
				rp = mid;
		}
		printf("%.4f\n", lp);
	}
	return 0;
}