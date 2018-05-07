#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;

const int maxn = 52;
int graph[maxn][maxn];
char str[maxn];
int state[maxn];

int ID(char c1, char c2)
{
	return (c1 - 'A') * 2 + ('+' == c2 ? 1 : 0);
}

void connect(char c1, char c2, char c3, char c4)
{
	if (c1 == '0' || c3 == '0')
		return;
	int a = ID(c1, c2);
	a = a ^ 1;
	int b = ID(c3, c4);
	graph[a][b] = 1;
}

bool dfs(int n)
{
	state[n] = -1;
	for (int i = 0; i < maxn; i++)
	{
		if (graph[n][i] && -1 == state[i]) // has a ring
			return true;
		if (graph[n][i] && 0 == state[i])
		{
			bool flag = dfs(i);
			if (flag)
				return true;
		}
	}
	state[n] = 1;
	return false;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N;
	while (1 == scanf("%d", &N))
	{
		memset(graph, 0, sizeof(graph));
		memset(state, 0, sizeof(state));
		for (int i = 0; i < N; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (j == k)
						continue;
					connect(str[j * 2], str[j * 2 + 1], str[k * 2], str[k * 2 + 1]);
				}
			}//for int j
		}//for int i

		bool flag = false;
		for (int i = 0; i < 52; i++)
		{
			if (0 == state[i])
				flag = dfs(i);
			if (flag)
				break;
		}
		if (flag)
			printf("unbounded\n");
		else
			printf("bounded\n");
	}//while
	return 0;
}