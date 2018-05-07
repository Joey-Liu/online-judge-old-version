//1002
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 1000 * 100 + 100;

struct person
{
	LL iq;
	int cla;
};

person v[maxn];
bool vis[maxn];
int classnum;
int stunum; //×ÜÈËÊý
LL dudu;
int res = 0;
int mostsmart = -1;

void init()
{
	mostsmart = -1;
	res = 0;
	cin >> classnum >> dudu;

	int tmp;
	stunum = 0;
	for (int i = 1; i <= classnum; i++)
	{
		scanf("%d", &tmp);
		for (int j = 1; j <= tmp; j++)
		{
			scanf("%d", &v[stunum].iq);
			v[stunum].cla = i;
			/*
			if (mostsmart < v[stunum].iq)
				mostsmart = v[stunum].iq;
			*/
			stunum++;
		}
	}
	memset(vis, false, sizeof(vis));
}

void solve()
{
	for (int i = 0; i < stunum; i++)
	{
		for (int j = i + 1; j < stunum; j++)
		{
			if (v[i].cla != v[j].cla && v[i].iq + v[j].iq > dudu)
				res++;
		}//for j
	}//for i
	printf("%d\n", res);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		init();
		solve();
	}
	return 0;
}