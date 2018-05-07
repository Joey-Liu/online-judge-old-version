#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 10 + 10;

double r;
int  s, weight[maxn], node_num;
double lw[maxn], rw[maxn];
bool visited[maxn];
double ans = 0.0;

void dfs(int layer, double t_ans)
{
	if (layer == s - 1)
	{
		ans = max(t_ans, ans);
		return;
	}

	for (int i = 0; i < node_num; i++)
	{
		if (visited[i])
			continue;

		for (int j = 0; j < node_num; j++)
		{
			if (i == j || visited[j])
				continue;

			double left = max(lw[i], lw[j] - 1);
			double right = max(rw[i] - 1, rw[j]);
			if (left + right + 1 < r)
			{
				visited[i] = true;
				visited[j] = true;
				weight[node_num] = weight[i] + weight[j];
				lw[node_num] = 1.0 * weight[j] / (weight[i] + weight[j]) + left;
				rw[node_num] = 1.0 * weight[i] / (weight[i] + weight[j]) + right;

				node_num++;
				t_ans = left + right + 1;
				dfs(layer + 1, t_ans);

				visited[i] = false;
				visited[j] = false;
				node_num--;
			}

		}//for int j
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		scanf("%lf%d", &r, &s);
		for (int i = 0; i < s; i++)
			scanf("%d", &weight[i]);

		node_num = s;
		memset(lw, 0, sizeof(lw));
		memset(rw, 0, sizeof(rw));
		memset(visited, false, sizeof(visited));
		ans = -1;
		dfs(0, 0);

		if (ans < 0)
			printf("-1\n");
		else
			printf("%.10f\n", ans);
	}
	return 0;
}