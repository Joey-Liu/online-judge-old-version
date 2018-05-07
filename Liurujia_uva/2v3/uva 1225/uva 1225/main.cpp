#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <ctype.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 10000 + 10;
int N;
int dig_cnt[maxn][10];

void init()
{
	memset(dig_cnt, 0, sizeof(dig_cnt));
	for (int i = 1; i < maxn; i++)
	{
		int tmp = i;
		while (tmp > 0)
		{
			dig_cnt[i][tmp % 10]++;
			tmp /= 10;
		}//while
		for (int j = 0; j < 10; j++)
			dig_cnt[i][j] += dig_cnt[i - 1][j];
	}
}

int main()
{
	init();
	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		scanf("%d", &N);
		printf("%d", dig_cnt[N][0]);
		for (int i = 1; i < 10; i++)
		{
			printf(" %d", dig_cnt[N][i]);
		}//for
		printf("\n");
	}//while

	return 0;
}