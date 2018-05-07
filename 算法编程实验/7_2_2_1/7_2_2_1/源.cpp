//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int > peo;
//
//int N,pos,val;
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	while (cin >> N)
//	{
//		peo.clear();
//		for (int i = 0; i < N; i++)
//		{
//			cin >> pos >> val;
//			peo.insert(peo.begin() + pos, val);
//		}
//		
//		for (int i = 0; i < peo.size() - 1; i++)
//			cout << peo[i] << " ";
//		cout << peo[peo.size() - 1] << endl;
//	}
//}

//方法: 从最后一个入队的人开始向前考虑，假设人pi，用线段树保存 队列中空格位置信息 
//从线段树中 以logn 时间复杂度 计算出pi应该 放入的空格，同时要更新线段树的信息，此时point[]
//数组就 返回空格在 线段树中的下标，从而进行线段树的更新
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 200000 + 20;

int pos[maxn];
int val[maxn];	//POS val 分别存储题目中要求的值
int trsize[maxn * 2];	//存储线段树数组 trsize[i] 表示相应区间下 空位置个数
int ans[maxn];	//最后输出 的序号 如ans[i] 表示队列中第i个人的序号
int peo_num;	//总人数
int point[maxn]; //point[t] 表示最后排列中 第t个位置在 trsize中的下标

void build_tree(int lp,int rp,int i)		//从结点i出发，构造区间[lp,rp]的区间树
{
	trsize[i] = rp - lp + 1;			//该区间下有多少个空格
	if (lp == rp)
	{
		point[lp] = i;					//记录空格在 线段树中的位置
		return;				
	}

	int mid = (lp + rp) / 2;
	build_tree(lp, mid, 2 * i);
	build_tree(mid + 1, rp, 2 * i + 1);
}


int require(int sum, int lp, int rp, int i)		//计算第sum个空格在线段树中的位置，即返回值为 （1--n）
{
	if (lp == rp)
		return lp;
	int mid = (lp + rp) / 2;

	if (trsize[2 * i] >= sum)			//如果左区间的空格数量足够，则空格应该在左区间
		return require(sum, lp, mid, i * 2);
	return require(sum - trsize[2 * i], mid + 1, rp, i * 2 + 1);
}

void keep(int i)			//维护线段树
{
	while (i > 0)
	{
		trsize[i]--;
		i /= 2;
	}
}

void init()
{
	for (int i = 1; i <= peo_num; i++)
		scanf("%d %d", &pos[i], &val[i]);
}

void solve()
{
	memset(trsize, 0, sizeof(trsize));
	memset(ans, 0, sizeof(ans));
	memset(point, 0, sizeof(point));

	build_tree(1, peo_num, 1);
	
	for (int i = peo_num; i >= 1; i--)
	{
		int t = require(pos[i] + 1, 1, peo_num, 1);
		ans[t] = i;	//第t个位置上 那个人的序号
		//维护线段树
		keep(point[t]);
	}

	for (int i = 1; i <= peo_num - 1; i++)
		printf("%d ", val[ans[i] ]);
	printf("%d\n", val[ans[peo_num]]);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &peo_num))
	{
		init();
		solve();
	}
	return 0;
}
