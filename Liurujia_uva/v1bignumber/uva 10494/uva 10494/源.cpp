#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 1000;
int a[maxn], b[maxn], res[maxn], temp[maxn], aflen, bslen, telen;
char s1[maxn], s2[maxn];
char ch;

void read()
{
	aflen = strlen(s1);
	bslen = strlen(s2);

	for (int i = 0; i < aflen; i++)
		a[i] = s1[aflen - 1 - i] - '0';
	for (int i = 0; i < bslen; i++)
		b[i] = s2[bslen - 1 - i] - '0';

}

bool lessThan(int f1[], int f2[], int len1, int len2)
{
	if (len1 < len2)
		return true;
	if (len1 > len2)
		return false;
	for (int i = len1 - 1; i >= 0; i--)
	{
		if (f1[i] != f2[i])
			return f1[i] < f2[i];
	}
	return false;
}

void multitem(int jk)
{
	memset(temp, 0, sizeof(temp));
	int pos, i;
	for (pos = jk, i = 0; i < bslen; i++)
	{
		temp[pos] = b[i];
		pos++;
	}
	telen = pos;
}

void subtract(int af[], int bs[], int aflen, int bslen)
{
	int i = 0;
	for (i = 0; i < bslen; i++)
	{
		af[i] -= bs[i];
		if (af[i] < 0)
		{
			af[i] += 10;
			af[i + 1]--;
		}
	}
	for (; i < aflen; i++)
	{
		if (af[i] < 0)
		{
			af[i] += 10;
			af[i + 1]--;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%s", s1))
	{
		while (scanf("%c", &ch) && ch == ' ')
			continue;
		scanf("%s", s2);
		memset(res, 0, sizeof(res));
		read();
		while (!lessThan(a, b, aflen, bslen))
		{
			int jk = aflen - bslen;
			multitem(jk);
			while (lessThan(a, temp, aflen, telen))
			{
				jk--;
				multitem(jk);
			}

			while (!lessThan(a, temp, aflen, telen))
			{
				subtract(a, temp, aflen, telen);
				res[jk]++;
				while (aflen > 0 && 0 == a[aflen - 1])
					aflen--;
			}
		}//while lessThan

		for (int index = 0; index < maxn - 1; index++)
		{
			if (res[index] >= 10)
			{
				res[index + 1]++;
				res[index] %= 10;
			}
		}

		if ('/' == ch)
		{
			int index;
			for (index = maxn - 1; index >= 0; index--)
			{
				if (res[index])
					break;
			}
			if (index < 0)
				index = 0;
			for (; index >= 0; index--)
				printf("%d", res[index]);
		}//
		else
		{
			if (aflen <= 0)
				aflen = 1;
			for (int i = aflen - 1; i >= 0; i--)
				printf("%d", a[i]);
		}
		printf("\n");
	}//while scanf
}