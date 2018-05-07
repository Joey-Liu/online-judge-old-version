#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1000 + 10;
vector<int> gr[maxn], nodes[maxn];	//gr 表示结点， nodes[i] 表示深度为i的结点
int n, s, k, fa[maxn];			//fa[i] 结点i 的父节点
bool covered[maxn];		//结点i是否被覆盖


//深搜结点 u，父节点f 深度为d
void dfs(int u, int f, int d)
{
	fa[u] = f;
	int len = gr[u].size();
	if (len == 1 && d > k)			//结点u为叶节点 且深度大于k
		nodes[d].push_back(u);
	for (int i = 0; i < len; i++)
	{
		int v = gr[u][i];
		if (v != f)
			dfs(v, u, d + 1);
	}
}


void dfs2(int u,int f, int d)
{
	covered[u] = true;			//该节点被覆盖
	int len = gr[u].size();
	for (int i = 0; i < len; i++)
	{
		int v = gr[u][i];
		if (v != f && d < k)		//是否继续向下覆盖
			dfs2(v, u, d + 1);
	}
}

int work()
{
	int res = 0;
	memset(covered, false, sizeof(covered));
	for (int d = n - 1; d > k; d--) //深度小于等于k 的不用考虑
	{
		for (int i = 0; i < nodes[d].size(); i++)
		{
			int u = nodes[d][i];
			if (covered[u])		//如果已经被覆盖 不用考虑
				continue;

			int parent = u;
			for (int j = 0; j < k; j++)		//找到结点u的k级祖先
				parent = fa[parent];
			dfs2(parent, -1, 0);			//注意函数父节点的取值
			res++;
		}
	}

	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d%d%d", &n, &s, &k);
		for (int i = 0; i < n - 1; i++)
		{
			gr[i].clear();
			nodes[i].clear();
		}

		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}

		dfs(s, -1, 0);//转化为有根树
		printf("%d\n", work());
	}

	return 0;
}