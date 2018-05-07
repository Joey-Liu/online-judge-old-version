#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

struct Node
{
	int w1, w2;
};

bool cmp(Node a, Node b)
{
	if(a.w1 != b.w1)
		return a.w1 < b.w1;
	return a.w2 < b.w2;
}

Node nodes[6];

bool work()
{
	bool flag = true;
	for (int i = 0; i < 6; i += 2)
	{
		if (nodes[i].w1 != nodes[i + 1].w1
			|| nodes[i].w2 != nodes[i + 1].w2)
			flag = false;
	}
	if (!flag)
		return flag;

	int a[2] = { 0 };

	if (nodes[2].w1 == nodes[0].w1)
	{
		a[0] = nodes[0].w2;
		a[1] = nodes[2].w2;
	}
	else if (nodes[2].w2 == nodes[0].w1)
	{
		a[0] = nodes[0].w2;
		a[1] = nodes[2].w1;
	}
	else if (nodes[2].w1 == nodes[0].w2)
	{
		a[0] = nodes[0].w1;
		a[1] = nodes[2].w2;
	}
	else if (nodes[2].w2 == nodes[0].w2)
	{
		a[0] = nodes[0].w1;
		a[1] = nodes[2].w1;
	}
	else
		return false;

	if (a[0] > a[1])
		swap(a[0], a[1]);
	if (a[0] == nodes[4].w1 && a[1] == nodes[4].w2)
		return true;
	else
		return false;
	
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> nodes[0].w1 >> nodes[0].w2)
	{
		for (int i = 1; i < 6; i++)
			cin >> nodes[i].w1 >> nodes[i].w2;
		for (int i = 0; i < 6; i++)
		{
			if (nodes[i].w1 > nodes[i].w2)
				swap(nodes[i].w1, nodes[i].w2);
		}
		sort(nodes, nodes + 6, cmp);
		string res = (work() ? "POSSIBLE" : "IMPOSSIBLE");
		cout << res << endl;
	}//while
	return 0;
}