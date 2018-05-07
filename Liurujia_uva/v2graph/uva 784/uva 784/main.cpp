#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;
const int maxn = 80 + 50;
char maze[maxn][maxn];
int kasenum, dire[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, {1, 0} };

void dfs(int r, int c)
{
	maze[r][c] = '#';
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dire[i][0];
		int nc = c + dire[i][1];
		if (' ' == maze[nr][nc])
		{
			dfs(nr, nc);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &kasenum);
	getchar();
	while (kasenum--)
	{
		memset(maze, 0, sizeof(maze));
		int index = 0;
		while (true)
		{
			gets(maze[index]);
			if ('_' == maze[index][0])
				break;
			index++;
		}
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < strlen(maze[i]); j++)
			{
				if ('*' == maze[i][j])
					dfs(i, j);
			}
		}
		for (int i = 0; i <= index; i++)
			printf("%s\n", maze[i]);
	}//while casenum
	return 0;
}