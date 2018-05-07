#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 100 + 20;
char area[maxn][maxn];
int visited[maxn][maxn];
int m, n, ans = 0;

bool check(int r, int c)
{
	if (r < 0 || r >= m || c < 0 || c >= n)
		return false;
	return true;
}

void dfs(int r, int c)
{
	if (check(r, c) && !visited[r][c] && area[r][c] == '@')
	{
		visited[r][c] = true;
		dfs(r - 1, c - 1); dfs(r - 1, c); dfs(r - 1, c + 1);
		dfs(r, c - 1); dfs(r, c + 1);
		dfs(r + 1, c - 1);
		dfs(r + 1, c); dfs(r + 1, c + 1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> m >> n)
	{
		if (m <= 0)
			break;
		memset(area, 0, sizeof(area));
		memset(visited, false, sizeof(visited));
		ans = 0;

		for (int i = 0; i < m; i++)
			cin >> area[i];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && area[i][j] == '@')
				{
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << endl;
	}//while
}