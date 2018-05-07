#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
unsigned long long n, m, res;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (EOF != scanf("%lld%lld", &n, &m))
	{
		if (m == 0 && 0 == n)
			break;
		if (n > m)
		{
			res = n;
			n = m;
			m = res;
		}

		res = (2 * n * (n - 1) * (n - 2) / 3 + n*(n - 1)*(m - n + 1)) << 1;
		res += (m*(m - 1)*n + n*(n - 1)*m);
		printf("%lld\n", res);
	}//while

	return 0;
}