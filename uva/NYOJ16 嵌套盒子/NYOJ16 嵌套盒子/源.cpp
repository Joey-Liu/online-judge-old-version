#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;
struct RECT
{
	double a, b;
};

const int maxn = 1000 + 10;
RECT rects[maxn];
int G[maxn][maxn];
int dpMat[maxn];
int rectNum;

void makeGraph()
{
	for (int i = 0; i < rectNum; i++)
	{
		for (int j = 0; j < rectNum; j++)
		{
			if ((rects[i].a < rects[j].a && rects[i].b < rects[j].b) ||
				(rects[i].b < rects[j].a && rects[i].a < rects[j].b))
			{
				G[i][j] = 1;
			}
		}
	}
}

int dp(int i)
{
	int & ans = dpMat[i];
	if (ans != -1)
		return ans;
	ans = 1;
	for (int j = 0; j < rectNum; j++)
	{
		if (G[i][j])
			ans = max(ans, dp(j) + 1);
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum, res = 0;
	cin >> casenum;
	while (casenum--)
	{
		cin >> rectNum;
		for (int i = 0; i < rectNum; i++)
			cin >> rects[i].a >> rects[i].b;
		memset(dpMat, -1, sizeof(dpMat));
		memset(G, 0, sizeof(G));
		makeGraph();
		res = 0;
		for (int i = 0; i < rectNum; i++)
		{
			res = max(dp(i), res);
		}
		cout << res << endl;
	}
}