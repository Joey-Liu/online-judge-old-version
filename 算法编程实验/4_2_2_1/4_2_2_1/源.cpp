#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long int64;

int64 solution(int64 n, int64 k)
{
	if (k > n / 2)
		k = n - k;
	int64 a = 1, b = 1;
	for (int i = 1; i <= k; i++)
	{
		a *= (n + 1 - i);
		b *= i;
		if (0 == a % b)
		{
			a /= b;
			b = 1;
		}
	}

	return a / b;
}


int main()
{
	freopen("binomial.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	while (n || k)
	{
		cout << solution(n, k) << endl;
		cin >> n >> k;
	}
	return 0;
}