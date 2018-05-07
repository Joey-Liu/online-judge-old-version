#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
struct Node
{
	int x, y;
	Node(int m = -1, int n = -1)
	{
		x = m;
		y = n;
	}
};

vector<Node> a, b;
int N;

bool cmp(Node a, Node b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N)
	{
		a.clear();
		b.clear();
		for (int i = 0; i < N; i++)
		{
			int m, n;
			cin >> m >> n;
			a.push_back(Node(m, n));
		}

		for (int i = 0; i < N; i++)
		{
			int m, n;
			cin >> m >> n;
			b.push_back(Node(m, n));
		}
		sort(a.begin(), a.end(),cmp);
		sort(b.begin(), b.end(), cmp);

		int i = 0, j = 0, res = 0;
		while (i < a.size() && j < b.size())
		{
			if (a[i].x < b[j].x && a[i].y < b[j].y)
			{
				res++;
				j++;
				i++;
			}
			else
				i++;
		}
		cout << res << endl;
	}//while
	return 0;
}