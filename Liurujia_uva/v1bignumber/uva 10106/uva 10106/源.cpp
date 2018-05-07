#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 700;
int a[maxn], b[maxn], res[maxn], aolen, btlen;
char temp[maxn];

void read(int num[])
{
	int len = strlen(temp);
	for (int i = 0; i < len; i++)
		num[i] = temp[len - 1 - i] - '0';
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (gets(temp))
	{
		aolen = strlen(temp);
		memset(a, 0, sizeof(a));
		read(a);

		gets(temp);
		btlen = strlen(temp);
		memset(b, 0, sizeof(b));
		read(b);

		memset(res, 0, sizeof(res));
		for (int i = 0; i < aolen; i++)
		{
			for (int j = 0; j < btlen; j++)
			{
				res[i + j] += a[i] * b[j];
				if (res[i + j] >= 10)
				{
					int c = res[i + j] / 10;
					res[i + j + 1] += c;
					res[i + j] %= 10;
				}
			}
		}

		int index;
		for (index = maxn - 1; index >= 0; index--)
		{
			if (res[index])
				break;
		}

		if (index < 0)
			index = 0;
		while (index >= 0)
		{
			printf("%d", res[index]);
			index--;
		}
		printf("\n");
	}//while

	return 0;
}