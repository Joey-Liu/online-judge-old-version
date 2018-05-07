#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory>
#include <algorithm>

using namespace std;

int N, ans_i, ans_j;

const int maxn = 1000 + 10;

int sec_code[maxn];
int break_code[maxn];

void work()
{
	ans_i = 0; ans_j = 0;
	for (int i = 0; i < N; i++)
	{
		if (sec_code[i] == break_code[i])
			ans_i++;
	}

	for (int k = 0; k <= 9; k++)
	{
		int c1 = 0, c2 = 0;
		for (int i = 0; i < N; i++)
		{
			if (k == sec_code[i])
				c1++;
			if (k == break_code[i])
				c2++;
		}
		ans_j += min(c1, c2);
	}//for int k
	ans_j -= ans_i;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int game_case = 1;
	while (true)
	{
		scanf("%d", &N);
		if (!N)
			break;
		for (int i = 0; i < N; i++)
			scanf("%d", &sec_code[i]);
		printf("Game %d:\n", game_case++);

		while (true)
		{
			for (int i = 0; i < N; i++)
				scanf("%d", &break_code[i]);
			if (!break_code[0])
				break;
			work();
			printf("    (%d,%d)\n", ans_i, ans_j);
		}
	}//while true
	return 0;
}