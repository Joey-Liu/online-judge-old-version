#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 4;
int position[maxn];

void print()
{
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			char c = '@';
			if (position[i] == j)
				c = '*';
			printf("%c", c);
		}
		printf("\n");
	}
}

void dfs(int layer)
{
	if (layer == maxn)
	{
		print();
		printf("\n");
		return;
	}

	for (int i = 0; i < maxn; i++)
	{
		int pos = i;
		bool flag = true;
		for (int j = 0; j < layer; j++)
		{
			if (pos == position[j] || abs(layer - j) == abs(pos - position[j]))
				flag = false;
			if (!flag)
				break;
		}

		if (flag)
		{
			position[layer] = pos;
			dfs(layer + 1);
		}
	}
}

int main()
{
	dfs(0);
	system("pause");
}