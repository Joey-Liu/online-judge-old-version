#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>

using namespace std;

const int maxn = (1e+5) + 20;
vector<int> a[maxn];
int ans[maxn];

int n, s;

void dfs(int x, int y)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		if (a[x][i] != y)
		{
			ans[a[x][i]] = x;
			dfs(a[x][i], x);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum, p,q;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 1; i <= n; i++)
			a[i].clear();
		memset(ans, 0, sizeof(ans));

		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d%d", &p, &q);
			a[p].push_back(q);
			a[q].push_back(p);
		}
		ans[s] = -1;

		dfs(s, 0);
		for (int i = 1; i < n; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}

	return 0;
}