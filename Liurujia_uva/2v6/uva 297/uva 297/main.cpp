#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>

using namespace std;
const int length = 32;

int graph[length][length];
char str[1024 * 2];
int cnt;

void work(int &st, int r, int c, int edge_len)
{
	char ch = str[st];
	st++;
	if ('p' == ch)
	{
		work(st, r, c + edge_len / 2, edge_len / 2);
		work(st, r, c, edge_len / 2);
		work(st, r + edge_len / 2, c, edge_len / 2);
		work(st, r + edge_len / 2, c + edge_len / 2, edge_len / 2);
	}
	else if ('f' == ch)
	{
		for (int i = r; i < r + edge_len; i++)
		{
			for (int j = c; j < c + edge_len; j++)
			{
				if (0 == graph[i][j])
				{
					graph[i][j] = 1;
					cnt++;
				}
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		cnt = 0;
		memset(graph, 0, sizeof(graph));
		for (int i = 0; i < 2; i++)
		{
			int st = 0;
			scanf("%s", str);
			work(st, 0, 0, 32);
		}
		printf("There are %d black pixels.\n", cnt);
	}//while kasenum--
	return 0;
}