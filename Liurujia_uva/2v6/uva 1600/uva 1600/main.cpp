#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <queue>

using namespace std;

const int maxn = 20 + 5;
int M, N, K;

int board[maxn][maxn];
int dist[maxn][maxn][maxn];
bool visited[maxn][maxn][maxn];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Node
{
	int r, c, s;
	Node(int x = 0, int y = 0, int z = 0)
	{
		r = x;
		c = y;
		s = z;
	}
};

bool in_board(int r,int c)
{
	if (r < 0 || r >= M || c < 0 || c >= N)
		return false;
	return true;
}

void bfs()
{
	visited[0][0][0] = true;
	queue<Node> que;
	que.push(Node(0, 0, 0));
	while (!que.empty())
	{
		Node node = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = node.r + dr[i];
			int nc = node.c + dc[i];
			int s = 0;
			if (in_board(nr, nc))
			{
				if (board[nr][nc] == 1)
					s = node.s + 1;
				else
					s = 0;
				if (s > K || visited[nr][nc][s])
					continue;
				visited[nr][nc][s] = true;
				dist[nr][nc][s] = dist[node.r][node.c][node.s] + 1;
				que.push(Node(nr, nc, s));
			}
		}//for int i
	}//while
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &board[i][j]);

		bfs();
		if (!visited[M - 1][N - 1][0])
			cout << -1 << endl;
		else
			cout << dist[M - 1][N - 1][0] << endl;
	}//while
}