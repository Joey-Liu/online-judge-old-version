#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <queue>

using namespace std;

const int maxs = 20;
const int maxn = 300;

int W, H, N, cnt, s[3], t[3];

string tab[maxs];
int x[maxn], y[maxn], id[maxs][maxs];
int graph[maxn][5], forkn[maxn], dist[maxn][maxn][maxn];
bool visited[maxn][maxn][maxn];

const int dr[] = { 0, -1, 0, 1, 0 };
const int dc[] = { 0, 0, 1, 0, -1 };

int ID(int a, int b, int c)
{
	return (a << 16 | b << 8 | c);
}

bool conflict(int a, int b, int a2, int b2)
{
	return a2 == b2 || (a2 == b && b2 == a);
}

bool hasfound(int a, int b, int c)
{
	return a == t[0] && b == t[1] && c == t[2];
}

void bfs()
{
	queue<int> que;
	int st = ID(s[0], s[1], s[2]);
	que.push(st);
	visited[s[0]][s[1]][s[2]] = true;
	bool flag = false;

	while (!que.empty())
	{
		int nu = que.front();
		que.pop();

		int a = (nu & 0xff0000) >> 16, b = (nu & 0xff00) >> 8, c = nu & 0xff;
		flag = hasfound(a, b, c);
		if (flag)
			break;

		for (int i = 0; i < forkn[a]; i++)
		{
			int a2 = graph[a][i];
			for (int j = 0; j < forkn[b]; j++)
			{
				int b2 = graph[b][j];
				if (conflict(a, b, a2, b2))
					continue;

				for (int k = 0; k < forkn[c]; k++)
				{
					int c2 = graph[c][k];
					if (conflict(a, c, a2, c2))
						continue;
					if (conflict(b, c, b2, c2))
						continue;
					if (!visited[a2][b2][c2])
					{
						visited[a2][b2][c2] = true;
						dist[a2][b2][c2] = dist[a][b][c] + 1;
						que.push(ID(a2, b2, c2));
					}

				}//for int k
			}//for int j
		}//for int i
	}//while

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	while (cin >> W >> H >> N && N)
	{
		char ch = cin.get();
		for (int i = 0; i < H; i++)
			getline(cin, tab[i]);
		
		cnt = 0;
		memset(id, -1, sizeof(id));
		memset(graph, -1, sizeof(graph));
		memset(forkn, 0, sizeof(forkn));
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if ('#' == tab[i][j])
					continue;
				x[cnt] = i;
				y[cnt] = j;
				id[i][j] = cnt;
				if (islower(tab[i][j]))
					s[tab[i][j] - 'a'] = cnt;
				if (isupper(tab[i][j]))
					t[tab[i][j] - 'A'] = cnt;
				cnt++;
			}
		}//for int i

		for (int i = 0; i < cnt; i++)
		{
			int r = x[i], c = y[i];
			forkn[i] = 0;
			for (int j = 0; j < 5; j++)
			{
				int nr = r + dr[j], nc = c + dc[j];
				if ('#' != tab[nr][nc])
					graph[i][forkn[i]++] = id[nr][nc];
			}//for int j
		}//for int i

		if (N <= 2)
		{
			s[2] = t[2] = cnt;
			forkn[cnt] = 1;
			graph[cnt][0] = cnt;
			cnt++;
		}
		if (N <= 1)
		{
			s[1] = t[1] = cnt;
			forkn[cnt] = 1;
			graph[cnt][0] = cnt;
			cnt++;
		}

		bfs();
		cout << dist[t[0]][t[1]][t[2]]<<endl;
	}//while
	return 0;
}