#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 5;
int stu[maxn];
int tree[maxn << 2];	

int N, M;

void build_tree(int node, int lp, int rp)
{
	if (lp == rp)
		tree[node] = stu[lp];
	else
	{
		int mid = (lp + rp) / 2;
		build_tree(node << 1, lp, mid);
		build_tree((node << 1) + 1, mid + 1, rp);
		tree[node] = max(tree[node << 1], tree[(node << 1) + 1]);
	}
}

int query(int node, int tl,int tr,int lp, int rp)
{
	if (tr < lp || tl > rp)
		return -1;
	if (tl <= lp && rp <= tr)
		return tree[node];
	
	int mid = (lp + rp) >> 1;
	int p1 = query(node << 1, tl, tr, lp, mid);
	int p2 = query((node << 1) + 1, tl, tr, mid + 1, rp);

	if (-1 == p1)
		return p2;
	else if (-1 == p2)
		return p1;
	else
		return max(p1, p2);
}

void update(int node, int lp, int rp, int id, int grade)
{
	if (id < lp || id > rp)
		return;
	if (lp == rp && id == lp)
		tree[node] = grade;
	else
	{
		if (grade > tree[node])
			tree[node] = grade;
		
		int mid = (lp + rp) >> 1;
		update(node << 1, lp, mid, id, grade);
		update((node << 1) + 1, mid + 1, rp, id, grade);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char ch;
	int a, b;
	while (2==scanf("%d%d",&N,&M))
	{
		for (int i = 1; i <= N; i++)
			scanf("%d", &stu[i]);
		build_tree(1, 1, N);
		for (int i = 0; i < M; i++)
		{
			getchar();
			scanf("%c %d %d", &ch,&a,&b);
			if ('Q' == ch)
				printf("%d\n", query(1, a, b, 1, N));
			else
				update(1, 1, N, a, b);
		}
	}//while scanf
	return 0;
}