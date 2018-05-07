#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <set>

using namespace std;
typedef long long LL;

const int maxn = 100000 + 5;
vector<int> neighbor[maxn];
int N, a,b;
bool hasfound = false;
bool visited[maxn];
int parent[maxn];
int sstep = 0, cnt = 0;

void dfs(int node, int step)
{
	if (node == N)
	{
		hasfound = true;
		sstep = step;
	}
	if (hasfound)
		return;

	for (int i = 0; i < neighbor[node].size(); i++)
	{
		int nei = neighbor[node][i];
		if (!visited[nei])
		{
			parent[nei] = node;
			visited[nei] = true;
			dfs(nei, step + 1);
			if (hasfound)
				return;
			visited[nei] = false;
		}
	}
}

void dfsss(int node)
{
	for (int i = 0; i < neighbor[node].size(); i++)
	{
		int nei = neighbor[node][i];
		if (!visited[nei])
		{
			visited[nei] = true; cnt++;
			dfsss(nei);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	while (2 == scanf("%d%d", &a, &b))
	{
		neighbor[a].push_back(b);
		neighbor[b].push_back(a);
	}

	memset(visited, false, sizeof(visited));
	memset(parent, -1, sizeof(parent));
	hasfound = false;

	visited[1] = true;
	dfs(1, 1);
	sstep--;

	sstep = (sstep - 1) / 2;
	int pa = N;
	for (int i = 0; i < sstep; i++)
		pa = parent[pa];
	
	memset(visited, 0, sizeof(visited));
	visited[parent[pa]] = true;
	cnt = 0;
	dfsss(pa);
	int fen = N - cnt;
	if (fen > cnt && cnt != 0)
		cout << "Fennec\n";
	else
		cout << "Snuke\n";
	return 0;
}