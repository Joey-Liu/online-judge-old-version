#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;
const int maxn = 20 + 5;
char map[maxn][maxn];
bool vis[maxn][maxn];

int res = 1;
int row, col;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool in_range(int r, int c)
{
	if (r < 1 || r > row || c < 1 || c > col)
		return false;
	return true;
}

void trans(char ch,int mode)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (ch == map[i][j] && 1 == mode)
				vis[i][j] = true;
			else if (map[i][j] == ch && 0 == mode)
				vis[i][j] = false;
		}
	}
}


void dfs(int r,int c,int step)
{
	if (step > res)
		res = step;
	for (int i = 0; i < 4; i++)
	{
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (in_range(tr, tc) && !vis[tr][tc])
		{
			vis[tr][tc] = true;
			trans(map[tr][tc], 1);

			dfs(tr,tc,step + 1);

			vis[tr][tc] = false;
			trans(map[tr][tc], 0);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (EOF != scanf("%d%d",&row,&col))
	{
		for (int i = 1; i <= row; i++)
			scanf("%s", map[i] + 1);
		memset(vis, false, sizeof(vis));
		res = 1;

		vis[1][1] = true;
		trans(map[1][1], 1);
		dfs(1, 1, 1);
		printf("%d\n", res);
	}
	return 0;
}