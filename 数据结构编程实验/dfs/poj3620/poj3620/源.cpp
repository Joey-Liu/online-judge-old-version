//dfs ˮ
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 100 + 20;
int map[maxn][maxn];		//1: It has water
bool visited[maxn][maxn];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };


int N, M, K;
int water_num = 0;

bool in_range(int row, int col)
{
	if (row < 0 || row >= N || col < 0 || col >= M)
		return false;
	return true;
}



void DFS(int row,int col)
{
	if (true == visited[row][col])
		return;

	visited[row][col] = true;
	water_num++;
	for (int i = 0; i < 4; i++)
	{
		int tr = row + dr[i];
		int	tc = col + dc[i];
		if (1 == map[tr][tc] && !visited[tr][tc])
			DFS(tr, tc);
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M >> K)
	{
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		int ans = 0;
		int row, col;

		for (int i = 0; i < K; i++)
		{
			cin >> row >> col;
			map[row][col] = 1;
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (1 == map[i][j] && false == visited[i][j])
				{
					water_num = 0;
					DFS(i, j);
					ans = max(ans, water_num);
				}
			}
		}//for int i
		cout << ans << endl;
	}//while
	return 0;
}