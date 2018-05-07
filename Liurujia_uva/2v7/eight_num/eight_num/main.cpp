#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <set>

using namespace std;

set<int> vis;

typedef int State[9];
const int maxn = 1e+6;
State st[maxn], goal;
int dist[maxn];

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

bool in_map(int r, int c)
{
	if (r < 0 || r >= 3 || c < 0 || c >= 3)
		return false;
	return true;
}

bool insert_set(const State & s)
{
	int n = 0;
	for (int i = 0; i < 9; i++)
		n = n * 10 + s[i];
	if (!vis.count(n))
	{
		vis.insert(n);
		return true;
	}
	return false;

}

int bfs()
{
	vis.clear();
	int front = 1, rear = 2;
	while (front < rear)
	{
		State & s = st[front];
		if (!memcmp(s, goal, sizeof(goal)))
			return front;
		int ind = 0;
 		for (ind = 0; ind < 9; ind++)
			if (!s[ind])
				break;

		int r = ind / 3, c = ind % 3;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (in_map(nr, nc))
			{
				State & r = st[rear];
				memcpy(r, s, sizeof(s));
				int k = nr * 3 + nc;
				int t = r[k];
				r[k] = r[ind];
				r[ind] = t;
				bool flag = insert_set(r);
				if (flag)
				{
					dist[rear] = dist[front] + 1;
					rear++;
				}
			}
		}//for int i
		front++;
	}//while front
	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	for (int i = 0; i < 9; i++)
		scanf("%d", &st[1][i]);
	for (int i = 0; i < 9; i++)
		scanf("%d", &goal[i]);
	memset(dist, 0, sizeof(0));
	int ans = bfs();
	printf("%d\n", dist[ans]);
}