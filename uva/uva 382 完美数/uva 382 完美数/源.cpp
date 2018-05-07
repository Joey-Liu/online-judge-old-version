#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

const int maxn = 100 + 50;
int num[maxn];
char str[][maxn] = { "DEFICIENT", "PERFECT", "ABUNDANT" };

int solve(int n)
{
	if (1 == n)
		return 0;

	int res = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (0 == n % i)
		{
			res += i;
			if (i == n / i)
				continue;
			res += n / i;
		}
	}

	if (res < n)
		return 0;
	else if (res == n)
		return 1;
	else
		return 2;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cnt = 0, tmp = 0;
	cin >> tmp;

	while (tmp != 0)
	{
		num[cnt++] = tmp;
		cin >> tmp;
	}

	printf("PERFECTION OUTPUT\n");
	for (int i = 0; i < cnt; i++)
	{
		printf("%5d", num[i]);
		printf("  ");
		printf("%s\n", str[solve(num[i])]);
	}
	printf("END OF OUTPUT\n");
}