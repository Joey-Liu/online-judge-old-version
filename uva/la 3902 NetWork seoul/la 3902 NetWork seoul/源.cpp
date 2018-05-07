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
vector<int> gr[maxn], nodes[maxn];	//gr ��ʾ��㣬 nodes[i] ��ʾ���Ϊi�Ľ��
int n, s, k, fa[maxn];			//fa[i] ���i �ĸ��ڵ�
bool covered[maxn];		//���i�Ƿ񱻸���


//���ѽ�� u�����ڵ�f ���Ϊd
void dfs(int u, int f, int d)
{
	fa[u] = f;
	int len = gr[u].size();
	if (len == 1 && d > k)			//���uΪҶ�ڵ� ����ȴ���k
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
	covered[u] = true;			//�ýڵ㱻����
	int len = gr[u].size();
	for (int i = 0; i < len; i++)
	{
		int v = gr[u][i];
		if (v != f && d < k)		//�Ƿ�������¸���
			dfs2(v, u, d + 1);
	}
}

int work()
{
	int res = 0;
	memset(covered, false, sizeof(covered));
	for (int d = n - 1; d > k; d--) //���С�ڵ���k �Ĳ��ÿ���
	{
		for (int i = 0; i < nodes[d].size(); i++)
		{
			int u = nodes[d][i];
			if (covered[u])		//����Ѿ������� ���ÿ���
				continue;

			int parent = u;
			for (int j = 0; j < k; j++)		//�ҵ����u��k������
				parent = fa[parent];
			dfs2(parent, -1, 0);			//ע�⺯�����ڵ��ȡֵ
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

		dfs(s, -1, 0);//ת��Ϊ�и���
		printf("%d\n", work());
	}

	return 0;
}