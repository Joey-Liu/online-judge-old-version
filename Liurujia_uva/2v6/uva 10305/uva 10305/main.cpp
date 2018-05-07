#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>

using namespace std;

const int maxn = 100 + 20;
int graph[maxn][maxn];
int state[maxn], N, M;
vector<int> ans;

bool DFS(int n)
{
	state[n] = -1;
	for (int i = 1; i <= N; i++)
	{
		if (graph[n][i])
		{
			if (-1 == state[i])
				return false;
			if (1 == state[i])
				continue;
			bool flag = DFS(i);
			if (!flag)
				return false;
		}
	}//for
	ans.push_back(n);
	state[n] = 1;
	return true;
}

int main()
{
	while (cin >> N >> M)
	{
		if (!N && !M)
			break;
		memset(state, 0, sizeof(state));
		memset(graph, 0, sizeof(graph));
		int a, b;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			graph[a][b] = 1;
		}

		bool flag;
		ans.clear();

		for (int i = 1; i <= N; i++)
		{
			if (!state[i])
			{
				flag = DFS(i);
			}
		}
		for (int i = ans.size() - 1; i >= 1; i--)
			cout << ans[i] << " ";
		cout << ans[0] << endl;
	}
	return 0;
}