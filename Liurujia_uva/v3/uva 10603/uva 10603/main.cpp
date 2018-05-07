#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
int cap[3], d;

struct Node
{
	int val[3];
	int dist;

	Node(int a = 0, int b = 0, int c = 0)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
	}
};

bool operator < (const Node& a, const Node& b)
{
	return a.dist > b.dist;
}

const int maxn = 200 + 10;
bool state[maxn][maxn];
int res[maxn];

void update_dist(const Node & node)
{
	for (int i = 0; i < 3; i++)
	{
		if (res[node.val[i]] < 0 || res[node.val[i]] > node.dist)
			res[node.val[i]] = node.dist;
	}
}


void work()
{
	memset(res, -1, sizeof(res));
	memset(state, false, sizeof(state));
	priority_queue<Node> que;

	Node start(0, 0, cap[2]);
	start.dist = 0;
	que.push(start);
	state[0][0] = true;

	while (!que.empty())
	{
		Node nt = que.top();
		que.pop();
		update_dist(nt);

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j || !nt.val[i] || nt.val[j] == cap[j])
					continue;
				int water_amount = min(cap[j], nt.val[i] + nt.val[j]) - nt.val[j];

				Node ssnt;
				memcpy(&ssnt, &nt, sizeof(Node));
				ssnt.val[i] -= water_amount;
				ssnt.val[j] += water_amount;
				ssnt.dist += water_amount;
				

				if (!state[ssnt.val[0]][ssnt.val[1]])
				{
					state[ssnt.val[0]][ssnt.val[1]] = true;
					que.push(ssnt);
				}
				else
					update_dist(ssnt);
			}//for int j
		}//for int i

	}//while que.empty()

	while (d >= 0)
	{
		if (res[d] >= 0)
		{
			printf("%d %d\n", res[d], d);
			return;
		}
		d--;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		for (int i = 0; i < 3; i++)
			scanf("%d", &cap[i]);
		scanf("%d", &d);
		work();
	}//while
	return 0;
}