#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 13;

int n, m;
bool ok = false;
bool map[maxn][maxn];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

void init()
{
	ok = false;
	memset(map, false, sizeof(map));
	char ch;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> ch;
			if ('S' == ch)
				map[i][j] = true;
		}
		getchar();
	}
}

bool judge()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == false)
				return false;
		}
	}
	return true;
}

bool in_range(int row, int col)
{
	if (row < 1 || row > n || col < 1 || col > m)
		return false;
	return true;
}

void DFS(int row,int col)
{
	if (judge())
	{
		ok = true;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int tr = row + dr[i];
		int tc = col + dc[i];
		if (in_range(tr, tc) && !map[tr][tc])
		{
			map[tr][tc] = true;
			DFS(tr, tc);
			if (!ok)
				map[tr][tc] = false;
			else
				return;
		}
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> m;
	while (n || m)
	{
		init();
		map[1][1] = true;
		DFS(1, 1);
		cout << (ok ? "YES" : "NO") << endl;
		cin >> n >> m;
	}
	return 0;
}