#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


using namespace std;

int cmp(const void *a, const void * b)
{
	int *x = (int *)a;
	int *y = (int *)b;

	return (*x - *y);
}
const int maxn = 1000 + 20;
int dp[maxn], price[maxn], n, m;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			cin >> price[i];
		qsort(price, n, sizeof(int), cmp);
		cin >> m;

		if (m < 5)
		{
			cout << m << endl;
			continue;
		}
		int maxi = price[n - 1];
		m -= 5;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = m; j >= price[i]; j--)
				dp[j] = max(dp[j], dp[j - price[i]] + price[i]);
		}
		cout << m + 5 - dp[m] - maxi << endl;
	}

	return 0;
}