#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100000 + 20;

vector<int> children[maxn];
int N, depth[maxn], max_dep;


void dfs(int n, int dep)
{
	depth[dep]++;
	max_dep = max(max_dep, dep);
	for (int i = 0; i < children[n].size(); i++)
	{
		int t = children[n][i];
		dfs(t, dep + 1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N)
	{
		memset(depth, 0, sizeof(depth));
		for (int i = 0; i <= N; i++)
			children[i].clear();
		max_dep = 0;

		for (int i = 2; i <= N; i++)
		{
			int a;
			cin >> a;
			children[a].push_back(i);
		}
		
		dfs(1, 0);
		int res = 0;
		
		for (int i = 0; i <= max_dep; i++)
		{
			if (depth[i] % 2)
				res++;
		}
		cout << res << endl;
	}
	return 0;
}