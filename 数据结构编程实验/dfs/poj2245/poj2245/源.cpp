#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>

using namespace std;
const int maxn = 15;
int size;
int casenum;
int set[maxn];//记录所选数字 base 1
int path[maxn];//记录序列 base 1
int vis[maxn];// also base 1

void init()
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= size; i++)
		scanf("%d", &set[i]);
}


void dfs(int cur, int now)//cur 处理目前序列中第几个数字，now目前数字位于set中第几个,从第几个开始取
{
	if (cur == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			printf("%d", path[i]);
			if (i != 6)
				printf(" ");
		}
		printf("\n");
		return;
	}

	//size - now + 1 表示可选的剩余数字 要多于 还需要填入的数字（6- cur + 1）
	for (int i = now; (i <= size) && (size - now + 1 >= 6 - cur + 1); i++)//i 为当前cur起始位置
	{
		if (!vis[i])
		{
			vis[i] = true;
			path[cur] = set[i];
			dfs(cur + 1, i + 1);
			vis[i] = false;//回溯一下
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	casenum = 1;
	while (EOF != scanf("%d", &size) && size != 0)
	{
		if (casenum != 1)
			printf("\n");

		for (int i = 1; i <= size; i++)
			scanf("%d", &set[i]);
		dfs(1, 1);
		casenum++;
	}
	return 0;
}