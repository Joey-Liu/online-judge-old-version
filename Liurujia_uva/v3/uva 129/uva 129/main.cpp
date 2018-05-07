#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 500 + 100;

int ans[maxn];
int N, L, cnt, flag = false;

bool has_repeat(int len, int layer)
{
	bool equal = true;
	for (int i = layer - 2 * len + 1; i <= layer - len; i++)
	{
		if (ans[i] != ans[i + len])
		{
			equal = false;
			break;
		}
	}
	return equal;
}

void dfs(int layer)
{
	if (cnt++ == N)
	{
		int ind = 0;
		for (int i = 0; i < layer; i++)
		{
			if (0 == i % 4 && i)
			{
				ind += 1;
				char c = ' ';
				if (ind == 16)
				{
					c = '\n';
					ind = 0;
				}
				printf("%c", c);
			}
			printf("%c", ans[i] + 'A');
		}
		printf("\n%d\n", layer);
		flag = true;
		return;
	}//if
	
	for (int i = 0; i < L; i++)
	{
		ans[layer] = i;
		bool repeat = false;
		for (int len = 1; len <= (layer + 1) / 2; len++)
		{
			repeat = has_repeat(len, layer);
			if (repeat)
				break;
		}

		if (!repeat)
			dfs(layer + 1);
		if (flag)
			return;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d%d", &N, &L);
	while (N || L)
	{
		flag = false;
		cnt = 0;
		dfs(0);
		scanf("%d%d", &N, &L);
	}
	return 0;
}