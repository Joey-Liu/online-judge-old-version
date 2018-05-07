#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1000 + 20;
int vis[maxn];
int dista[maxn][maxn];
vector<int> child[maxn];

int N, M, S, T;


void bfs(int num)
{
	queue<int> que;
	memset(vis, false, sizeof(vis));
	memset(dista[num], 0, sizeof(dista[num]));

	que.push(num);
	dista[num][num] = 0;
	vis[num] = true;

	while (!que.empty())
	{
		int t = que.front();
		que.pop();
		
		for (int i = 0; i < child[t].size(); i++)
		{
			int son = child[t][i];
			if (!vis[son])
			{
				vis[son] = true;
				dista[num][son] = dista[num][t] + 1;
				que.push(son);
			}
		}
	}
}

bool vecfind(const vector<int> & vi, int n)
{
	bool flag = false;
	for (int i = 0; i < vi.size(); i++)
	{
		if (vi[i] == n)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

int work()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (vecfind(child[i], j))
				continue;
			
			int ind = 0, dt = 0;
			if (dista[S][i] < dista[S][j])
			{
				dt = dista[S][i] + 1;
				ind = j;
			}
			else
			{
				dt = dista[S][j] + 1;
				ind = i;
			}
			if (dista[S][T] <= dt + dista[ind][T])
				cnt++;
		}//for int j
	}//for int i
	return cnt;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> S >> T;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		child[a].push_back(b);
		child[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		bfs(i);
	int res = work();
	cout << res << endl;
}