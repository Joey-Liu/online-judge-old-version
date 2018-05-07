#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int type_num;	//组件类型数量
map<string, int> id;
int ID(string s)
{
	if (!id.count(s))
		id[s] = type_num++;
	return id[s];
}

const int maxn = 1000 + 10;
struct Component
{
	int price;
	int quality;
	Component(int p, int q)
	{
		price = p;
		quality = q;
	}
};
int com_num, budget;
vector<Component> comp[maxn];

bool ok(int q)
{
	int sum = 0;
	for (int i = 0; i < type_num; i++)
	{
		int cheapest = budget + 1;
		int m = comp[i].size();
		for (int j = 0; j < m; j++)
		{
			//每次拿最便宜的零件
			if (comp[i][j].quality >= q)
				cheapest = min(cheapest, comp[i][j].price);
		}//for int j

		if (cheapest > budget)
			return false;
		sum += cheapest;
		if (sum > budget)
			return false;
	}//for int i

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d%d", &com_num, &budget);

		type_num = 0;
		for (int i = 0; i < com_num; i++)
			comp[i].clear();
		id.clear();

		int maxq = 0;
		for (int i = 0; i < com_num; i++)
		{
			char type[30], name[30];
			int p, q;
			scanf("%s%s%d%d", type, name, &p, &q);
			maxq = max(maxq, q);
			comp[ID(type)].push_back(Component(p, q));
		}

		int lp = 0, rp = maxq;
		while (lp < rp)
		{
			int middle = lp + (rp - lp + 1) / 2;
			if (ok(middle))
				lp = middle;
			else
				rp = middle - 1;
		}

		printf("%d\n", lp);
	}

	return 0;
}