//思路：使用线段树时，对于有时不需要立即更新的 子区间，可以先将要更新的内容放在 结点的mark标记上，只要
//使用到这个 子区间的时候，再将子区间的sum值进行更新，这样就可以省去大量时间
//注意 结点的mark值不为零，说明该区间下的子区间sum值没有更新!
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
typedef __int64 LL;

const __int64 maxn = 100000 + 10;

struct node
{
	LL mark, sum;			//懒惰标记为mark ，当mark值为零时，说明改子区间的sum值已经更新过
}tree[maxn * 3];

__int64 A[maxn];			//存储输入序列
int n, m;				//数字个数n,询问数m


void build_tree(__int64 lp,__int64 rp,__int64 i)//构建以i为根，区间为[l,,,r]的线段树
{
	if (lp == rp)
	{
		tree[i].sum = A[lp];
		return;
	}

	__int64 mid = (lp + rp) / 2;
	build_tree(lp, mid, i * 2);
	build_tree(mid + 1, rp, i * 2 + 1);
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
}


void update(__int64 lp, __int64 rp, __int64 i)			//用标记法维护线段树，根i对应区间为[lp....rp],目的是更新[lp,rp]下子区间的 sum
{
	if (tree[i].mark == 0)			//如果树根i mark==0 说明该节点下子区间已经 更新过了
		return;

	//否则 要更新该区间下的左右子区间，之后将该节点的mark标记下传给左右子区间
	__int64 mid = (lp + rp) / 2;
	tree[i * 2].sum += tree[i].mark * (mid - lp + 1);
	tree[i * 2 + 1].sum += tree[i].mark * (rp - mid);

	tree[i * 2].mark += tree[i].mark;
	tree[i * 2 + 1].mark += tree[i].mark;
	tree[i].mark = 0;
}

LL query(__int64 tl, __int64 tr, __int64 lp, __int64 rp, __int64 i)			//计算线段树i 对应区间[lp,,rp] 内子区间[tl,tr]上的数字和
{
	if (tl > rp || tr < lp)				//区间[tl,tr]与[lp,rp]无交集
		return 0;
	if (tl <= lp && rp <= tr)			//区间[tl,tr]完全覆盖 [lp,rp]
		return tree[i].sum;

	update(lp, rp, i);				//更新下 区间[lp,rp]下 子区间的sum
	__int64 mid = (lp + rp) / 2;

	return query(tl, tr, lp, mid, i * 2) + query(tl, tr, mid + 1, rp, 2 * i + 1);
}

void add_value(__int64 tl, __int64 tr, __int64 lp, __int64 rp, __int64 i, __int64 val)		//线段树i[lp,rp] 中区间[tl,tr] 的每个数 + val 
{
	if (tl > rp || tr < lp)
		return;
	if (tl <= lp && rp <= tr) //若区间[tl,rp] 覆盖[lp,rp] 
	{
		tree[i].sum += val * (rp - lp + 1);
		tree[i].mark += val;
		return;
	}

	//否则，需要自底向上 对tree[i]进行更新
	update(lp, rp, i);
	__int64 mid = (lp + rp) / 2;
	add_value(tl, tr, lp, mid, i * 2, val);
	add_value(tl, tr, mid + 1, rp, i * 2 + 1, val);

	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}


void work()
{
	memset(tree,0, sizeof(tree));
	build_tree(1, n, 1);

	char ch;
	__int64 lp, rp, c;
	for (__int64 i = 0; i < m; i++)
	{
		getchar();
		scanf("%c", &ch);
		if ('Q' == ch)
		{
			scanf("%I64d %I64d", &lp, &rp);
			__int64 ans = query(lp, rp, 1, n, 1);
			//cout << ans << endl;
			printf("%I64d\n", ans);
		}
		else
		{
			//cin >> lp >> rp >> c;
			scanf("%I64d %I64d %I64d", &lp, &rp, &c);
			add_value(lp, rp, 1, n, 1, c);
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	//for (__int64 i = 1; i <= n; i++)
	//	cin >> A[i];
	for (__int64 i = 1; i <= n; i++)
		scanf("%I64d", &A[i]);
	//getchar();
	work();
	return 0;
}
