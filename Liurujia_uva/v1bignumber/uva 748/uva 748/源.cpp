#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <string>

using namespace std;

const int maxn = 200;
int radio = 0, expon = 0, pos;
int num[maxn], res[maxn][maxn];
char temp[maxn];
char value[maxn], ans[maxn * 2];

void read()
{
	//输入的底数可能为整数
	for (pos = 0; pos < 6; pos++)
	{
		if (value[pos] == '.')
			break;
	}

	int rp;
	for (rp = 5; rp >= pos; rp--)
	{
		if (value[rp] == '0')
			value[rp] = '\0';
		else
			break;
	}
	
	memset(num, 0, sizeof(num));
	memset(res, 0, sizeof(res));
	int len = strlen(value);
	radio = (len - pos - 1) * expon;
	int j = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if ('.' == value[i])
			continue;
		num[j] = value[i] - '0';
		res[1][j] = num[j];
		j++;
	}
}

void work()
{
	for (int i = 2; i <= expon; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			for (int k = 0; k < maxn; k++)
			{
				res[i][j + k] += res[i - 1][j] * num[k];
				if (res[i][j + k] >= 10)
				{
					int c = res[i][j + k] / 10;
					res[i][j + k + 1] += c;
					res[i][j + k] %= 10;
				}
			}
		}
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (2 == scanf("%s %d", value, &expon))
	{
		read();
		work();

		int index;
		for (index = maxn - 1; index >= 0; index--)
		{
			if (res[expon][index])
				break;
		}
		memset(ans, 0, sizeof(ans));
		int i;
		for (i = 0; i < radio; i++)
		{
			ans[i] = res[expon][i] + '0';
		}
		int fraction = i;
		if (0 != radio)
			ans[i++] = '.';
		for (; fraction <= index; fraction++, i++)
			ans[i] = res[expon][fraction] + '0';
		i--;
		for (; i >= 0; i--)
			putchar(ans[i]);
		printf("\n");
	}//while
	return 0;
}