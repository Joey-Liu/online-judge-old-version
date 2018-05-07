#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;
const int MAX = 0x3f3f3f3f;
const int maxn = 1000 + 10;

struct node					//将平台 均向右移 20000米
{
	int lp, rp, height;
}stage[maxn];

int stage_num;
int limit;				//最大下降高度
int dp[maxn][2];			//dp[i][j] 从第i块板子 向j方向走时的最短时间
int casenum;
int sx, sy;				//开始位置的坐标

int cmp(const void * a, const void * b)				//根据平台 高度排序
{
	node *_a = (node *)a;
	node *_b = (node *)b;

	return  -(_a->height) + (_b->height);
}



int work(int level,int y)				//计算 在第x块 平台上 向y方向走 可以调入地面的最短时间 y = 0 左方向
{
	if (-1 != dp[level][y])
		return dp[level][y];
	
	int cur_height = stage[level].height;
	int next_level, next_x;
	if (0 == y)
		next_x = stage[level].lp;
	else
		next_x = stage[level].rp;


	for (next_level = level + 1; next_level <= stage_num; next_level++)
	{
		if (stage[next_level].lp <= next_x && next_x <= stage[next_level].rp)
			break;
	}

	if (next_level > stage_num)			//直接落在地面上
	{
		if (stage[level].height > limit)
			return MAX;
		else
			return stage[level].height;
	}
	int airtime;			//降落时间
	airtime = stage[level].height - stage[next_level].height;
	if (airtime > limit)
		return MAX;

	int ltime = 0, rtime = 0;		//落在 next_level 块板子上向左或向右 走的时间
	ltime = airtime + next_x - stage[next_level].lp;
	rtime = airtime + stage[next_level].rp - next_x;

	ltime += work(next_level, 0);
	rtime += work(next_level, 1);
	dp[level][y] =  ltime < rtime ? ltime : rtime;
	return dp[level][y];
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;
	while (casenum--)
	{
		memset(stage, 0, sizeof(stage));
		memset(dp, -1, sizeof(dp));
		
		cin >> stage_num >> sx >> sy >> limit;
		for (int i = 1; i <= stage_num; i++)
		{
			cin >> stage[i].lp >> stage[i].rp >> stage[i].height;
		}
		stage[0].lp = sx;
		stage[0].rp = sx;
		stage[0].height = sy;

		qsort(stage, stage_num  +1, sizeof(node), cmp);
		cout << work(0, 1) << endl;
	}
	return 0;
}