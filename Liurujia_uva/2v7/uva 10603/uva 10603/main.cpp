#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 200 + 5;

struct Node
{
	int v[3], dist;
	bool operator < (const Node & n) const
	{
		return dist > n.dist;
	}
};

int visited[maxn][maxn], cap[3], ans[maxn], hasfound = false;

void update(const Node & node, int d)
{
	for (int i = 0; i < 3; i++)
	{
		int vo = node.v[i];
		if (ans[vo] < 0 || ans[vo] > node.dist)
			ans[vo] = node.dist;
		if (vo == d)
			hasfound = true;
	}
}

void work(int a, int b, int c, int d)
{
	memset(ans, -1, sizeof(ans));
	memset(visited, false, sizeof(visited));

	cap[0] = a; cap[1] = b; cap[2] = c;
	Node st;
	st.v[0] = 0; st.v[1] = 0; st.v[2] = c;
	st.dist = 0;
	
	ans[0] = 0;
	ans[c] = 0;
	visited[0][0] = true;
	hasfound = false;

	priority_queue<Node> pq;
	pq.push(st);

	while (!pq.empty())
	{
		Node node = pq.top();
		pq.pop();
		update(node, d);

		if (hasfound)
			break;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
					continue;
				if (!node.v[i] || node.v[j] == cap[j])
					continue;

				Node t = node;
				int wat = min(cap[j] - node.v[j], node.v[i]);
				t.v[i] -= wat;
				t.v[j] += wat;
				t.dist += wat;

				if (!visited[t.v[0]][t.v[1]])
				{
					visited[t.v[0]][t.v[1]] = true;
					pq.push(t);
				}
			}
		}
	}//while
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum, a, b, c, d;

	cin >> kasenum;
	while (kasenum--)
	{
		cin >> a >> b >> c >> d;
		work(a, b, c, d);
		
		int k = d;
		while (k >= 0)
		{
			if (ans[k] >= 0)
			{
				cout << ans[k] << " " << k << endl;
				break;
			}
			k--;
		}
	}
	return 0;
}