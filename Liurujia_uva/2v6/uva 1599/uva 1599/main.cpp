#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

const int maxn = 2e+5 + 100;

struct Edge
{
	int a, b;
	int color;
	Edge(int x = 0, int y = 0, int z = 0)
	{
		a = x;
		b = y;
		color = z;
	}
};

bool visited[maxn];
Edge edges[maxn];
vector<int> graph[maxn];
int dist[maxn];
int N, M;

void init()
{
	memset(visited, false, sizeof(visited));
	memset(edges, 0, sizeof(edges));
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < N; i++)
		graph[i].clear();

	for (int i = 0; i < M; i++)
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].color;
		edges[i].a--; edges[i].b--;
		graph[edges[i].a].push_back(i);
		graph[edges[i].b].push_back(i);
	}
}

void rever_bfs()
{
	queue<int> que;
	dist[N - 1] = 0;
	visited[N - 1] = true;
	que.push(N - 1);
	while (!que.empty())
	{
		int node = que.front();
		que.pop();
		for (int i = 0; i < graph[node].size(); i++)
		{
			Edge edge = edges[graph[node][i]];
			int nxt = (edge.a == node ? edge.b : edge.a);
			if (!visited[nxt])
			{
				que.push(nxt);
				visited[nxt] = true;
				dist[nxt] = dist[node] + 1;
			}
		}//for int i
	}
}

void bfs()
{
	memset(visited, false, sizeof(visited));
	int cur_dist = dist[0];
	visited[0] = true;
	vector<int> cur, nxt, res;
	cur.push_back(0);
	

	for (int i = 0; i < dist[0]; i++)
	{
		int tmp_mini_color = INT_MAX;
		for (int j = 0; j < cur.size(); j++)
		{
			int node = cur[j];
			for (int k = 0; k < graph[node].size(); k++)
			{
				Edge edge = edges[graph[node][k]];
				int nxt_node = (edge.a == node ? edge.b : edge.a);
				if (!visited[nxt_node] && dist[nxt_node] == cur_dist - 1)
					tmp_mini_color = min(tmp_mini_color, edge.color);
			}//for int k
		}//for int j

		nxt.clear();

		for (int j = 0; j < cur.size(); j++)
		{
			int node = cur[j];
			for (int k = 0; k < graph[node].size(); k++)
			{
				Edge edge = edges[graph[node][k]];
				int nxt_node = (edge.a == node ? edge.b : edge.a);
				if (!visited[nxt_node] && dist[nxt_node] == cur_dist - 1 && edge.color == tmp_mini_color)
				{
					visited[nxt_node] = true;
					nxt.push_back(nxt_node);
				}
			}//for int k
		}//for int j
		cur_dist -= 1;
		res.push_back(tmp_mini_color);
		cur = nxt;
	}//for int i
	cout << dist[0] << endl;
	cout << res[0];
	for (int i = 1; i < res.size(); i++)
		cout << " " << res[i];
	cout << endl << endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M)
	{
		init();
		rever_bfs();
		bfs();
	}
	return 0;
}