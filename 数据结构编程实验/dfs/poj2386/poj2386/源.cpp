#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

const int maxn = 100 + 20;
char map[maxn][maxn];
bool vis[maxn][maxn];

int N, M;
int ans = 0;

bool in_range(int row, int col)
{
	if (row < 1 || row > N || col < 1 || col > M)
		return false;
	return true;
}

int dr[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dc[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

void DFS(int row, int col)
{
	if (vis[row][col])
		return;

	vis[row][col] = true;
	for (int i = 0; i < 8; i++)
	{
		int tr = row + dr[i];
		int tc = col + dc[i];

		if (in_range(tr, tc) && 'W'==map[tr][tc] &&!vis[tr][tc])
			DFS(tr, tc);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M)
	{
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(vis, false, sizeof(vis));

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> map[i][j];
			}
		}


		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] == 'W' && !vis[i][j])
				{
					DFS(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;

	}//while
	return 0;
}