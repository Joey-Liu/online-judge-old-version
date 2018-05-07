#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 10;

struct node
{
	int left;
	int right;
	int id;
};
node cities[maxn];

int casenum;
int interval_num;
int query_num;

int cmp(const void * a,const void * b)
{
	node * na = (node *)a;
	node * nb = (node *)b;

	return ((na->left) - (nb->left));
}

int work(int goal)
{
	int lp = 0, rp = interval_num - 1;
	int mid = (lp + rp) / 2;
	bool hasFind = false;
	int ans = -1;

	while (lp + 1 < rp)
	{
		if (cities[mid].left > goal)
			rp = mid;
		else if (cities[mid].right < goal)
			lp = mid;
		else
		{
			hasFind = true;
			ans = cities[mid].id;
			break;
		}

		mid = (lp + rp) / 2;
	}

	if (!hasFind)
	{
		if (cities[lp].left <= goal && goal <= cities[lp].right)
			ans = cities[lp].id;
		else if (cities[rp].left <= goal && goal <= cities[rp].right)
			ans = cities[rp].id;
		else
			ans = -1;
	}

	return ans;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d", &interval_num);
		for (int i = 0; i < interval_num; i++)
			scanf("%d %d %d", &cities[i].left, &cities[i].right, &cities[i].id);

		qsort(cities, interval_num, sizeof(node), cmp);
		
		scanf("%d", &query_num);
		int city;
		for (int i = 0; i < query_num; i++)
		{
			scanf("%d", &city);
			printf("%d\n", work(city));
		}
	}//while

	return 0;
}