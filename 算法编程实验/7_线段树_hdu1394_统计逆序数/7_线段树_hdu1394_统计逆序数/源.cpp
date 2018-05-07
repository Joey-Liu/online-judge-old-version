//http://www.cnblogs.com/ziyi--caolu/archive/2013/01/15/2860768.html
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 5000 + 10;
int a[maxn];
int tree[maxn];			//tree[node] lp,rp表示 区间[lp,rp]之间数的个数
int length;

//感觉好像没有建树的必要 直接memset
void build_tree(int node, int lp, int rp)
{
	if (lp == rp)
		tree[node] = 0;
	else
	{
		int mid = (lp + rp) / 2;
		build_tree(node * 2, lp, mid);
		build_tree(node * 2 + 1, mid + 1, rp);
	}
}

int query(int node, int tl, int tr, int lp, int rp)			//在区间 lp -- rp 中查找 tl---tr 元素个数
{
	if (tl > rp || tr < lp)
		return 0;
	if (tl <= lp && rp <= tr)
		return tree[node];

	int mid = (lp + rp) / 2;
	int p1 = query(node * 2, tl, tr, lp, mid);
	int p2 = query(node * 2 + 1, tl, tr, mid + 1, rp);
	tree[node] = p1 + p2;
	return tree[node];
}

void update(int node,int lp, int rp, int val)//从node [lp,rp]开始更新值val，tree[node]表示 区间lp,rp之间有多少个数
{
	if (lp == rp && lp == val)
	{
		tree[node] = 1;						//这个地方刚开始弄错了，应该是tree[node] = 1 代表存在这个数
		return;
	}
	else if (val < lp || val > rp)
		return;

	int mid = (lp + rp) / 2;
	update(node * 2, lp, mid, val);
	update(node * 2 + 1, mid + 1, rp, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &length))
	{
		memset(tree, 0, sizeof(tree));
		build_tree(1, 1, length);
		int ans = 0;

		for (int i = 1; i <= length; i++)
		{
			scanf("%d", &a[i]);
			ans += query(1, a[i] + 1, length, 1, length);
			update(1, 1, length, a[i]);
		}

		int minu = ans;
		for (int i = 1; i <= length; i++)
		{
			ans = ans + length - 1 - a[i] - a[i];  //移动初始位置后，  产生新的a[i]逆序 
													//n - 1 - a[i],减去原a[i]个逆序
			if (ans < minu)
				minu = ans;
		}

		printf("%d\n", minu);
	}
}