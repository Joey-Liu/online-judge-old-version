#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
const int maxn = 1000000 + 10;
long long int f[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(f, 0, sizeof(f));
	for (long long i = 4; i < maxn; i++)
		f[i] = f[i - 1] + ((i - 2)*(i - 1) / 2 - (i - 1) / 2) / 2;

	int n;
	while (EOF != scanf("%d", &n))
	{
		if (n < 3)
			break;
		printf("%lld\n", f[n]);
	}
	return 0;
}