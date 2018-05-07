#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int maxn = 130;
const int msize = 40;

struct BIGNUM
{
	int s[maxn];
	int len;
}h[msize];

BIGNUM mutiply(BIGNUM a, int b)
{
	for (int i = 0; i < a.len; i++)
		a.s[i] *= b;

	for (int i = 0; i < a.len; i++)
	{
		if (a.s[i] >= 10)
		{
			a.s[i + 1] += a.s[i] / 10;
			a.s[i] %= 10;
		}
	}

	while (a.s[a.len] != 0)
	{
		a.s[a.len + 1] += a.s[a.len] / 10;
		a.s[a.len] %= 10;
		a.len++;
	}

	return a;
}

BIGNUM divide(BIGNUM a, int b)
{
	for (int i = a.len - 1; i > 0; i--)
	{
		a.s[i - 1] += a.s[i] % b * 10;
		a.s[i] /= b;
	}

	a.s[0] /= b;
	while (0 == a.s[a.len - 1])
		a.len--;

	return a;
}

void init()
{
	h[0].len = 1;
	h[0].s[0] = 1;

	for (int i = 1; i < msize; i++)
	{
		h[i] = mutiply(h[i - 1], 4 * i - 2);
		h[i] = divide(h[i], i + 1);
	}
}

void print(BIGNUM a)
{
	for (int i = a.len - 1; i >= 0; i--)
		printf("%d", a.s[i]);
}


int main()
{
	init();
	int num, casenum = 0;
	while (cin >> num && (num >= 0))
	{
		casenum++;
		printf("%d %d ", casenum, num);
		print(mutiply(h[num], 2));
		printf("\n");
	}
	return 0;
}