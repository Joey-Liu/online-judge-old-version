#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <functional>

using namespace std;
const int maxn = 1000000 + 1000;

long long A[maxn], C[maxn], total, M;
int n;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (EOF != scanf("%d", &n))
	{
		total = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &A[i]);
			total += A[i];
		}

		M = total / n;
		C[0] = 0;
		for (int i = 1; i < n; i++)
			C[i] = C[i - 1] + A[i] - M;
		sort(C, C + n);

		long long x1 = C[n / 2], ans = 0;
		for (int i = 0; i < n; i++)
			ans += abs(x1 - C[i]);
		printf("%lld\n", ans);
	}
	return 0;
}