#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 150;
const int msize = 105;
struct BIGNUM
{
	int s[maxn];
	int len;
};

BIGNUM h[msize];

BIGNUM multiply(BIGNUM a, int b)
{
	for (int i = a.len - 1; i >= 0; i--)
		a.s[i] = a.s[i] * b;

	for (int i = 0; i < a.len; i++)
	{
		if (a.s[i] >= 10)
		{
			a.s[i + 1] += a.s[i] / 10;
			a.s[i] = a.s[i] % 10;
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

	while (0==a.s[a.len - 1])
		a.len--;

	return a;
}

void print(BIGNUM a)
{
	for (int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.s[i]);
	}
}


void init()
{
	memset(h, 0, sizeof(0));
	h[0].len = 1;
	h[0].s[0] = 1;
	for (int i = 1; i < msize; i++)
	{
		h[i] = multiply(h[i - 1], 4 * i - 2);
		h[i] = divide(h[i], i + 1);
	}
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int num;
	cin >> num;
	while (num > 0)
	{
		print(h[num]);
		printf("\n");
		cin >> num;
	}
	return 0;
}