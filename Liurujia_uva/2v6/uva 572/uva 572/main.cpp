#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 100 + 5;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int M, N;
bool visited[maxn][maxn];
string oil_map[maxn];

bool in_map(int r, int c)
{
	if (r < 0 || r >= M || c < 0 || c >= N)
		return false;
	return true;
}

void dfs(int r, int c)
{
	visited[r][c] = true;
	int ro, co;
	for (int i = 0; i < 8; i++)
	{
		ro = r + dr[i];
		co = c + dc[i];
		if (in_map(ro, co) && '@' == oil_map[ro][co] && !visited[ro][co])
			dfs(ro, co);
	}
}

int main()
{
	while (cin >> M >> N && M && N)
	{
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < M; i++)
			cin >> oil_map[i];
		int res = 0;
		
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ('@' == oil_map[i][j] && !visited[i][j])
				{
					dfs(i, j);
					res++;
				}
			}//for int j
		}
		cout << res << endl;
	}//while
	return 0;
}