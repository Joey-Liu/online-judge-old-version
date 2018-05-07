#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 200;
int bignum[maxn][maxn];
char temp[maxn];
int res[maxn];

int lengths[maxn] = { 0 };
int num = 0, resLength;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	memset(bignum, 0, sizeof(bignum));
	memset(res, 0, sizeof(res));

	while (gets(temp))
	{
		if (!strcmp(temp, "0"))
			break;

		lengths[num] = strlen(temp);
		for (int i = 0; i < lengths[num]; i++)
			bignum[num][i] = temp[lengths[num] - 1 - i] - '0';
		num++;
	}

	int c = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < maxn - 1; j++)
		{
			res[j] += bignum[i][j];
			if (res[j] >= 10)
			{
				c = res[j] / 10;
				res[j + 1] += c;
				res[j] %= 10;
			}
		}
	}

	int index;
	for (index = maxn - 1; index >= 0; index--)
	{
		if (res[index])
			break;
	}

	while (index >= 0)
	{
		printf("%d", res[index]);
		index--;
	}
	printf("\n");
	return 0;
}