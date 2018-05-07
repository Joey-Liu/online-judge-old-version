#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 1000 + 50;

struct  Node
{
	double x, y;
}nodes_fi[maxn], nodes_se[maxn];

bool cmp_1(const Node n1, const Node n2)
{
	if (n1.x != n2.x)
		return n1.x < n2.x;
	return n1.y < n2.y;
}

bool cmp_2(const Node n1, const Node n2)
{
	if (n1.x != n2.x)
		return n1.x > n2.x;
	return n1.y < n2.y;
}

int N;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%lf%lf", &nodes_fi[i].x, &nodes_fi[i].y);
			nodes_se[i] = nodes_fi[i];
		}
		sort(nodes_fi, nodes_fi + N, cmp_1);
		sort(nodes_se, nodes_se + N, cmp_2);
		const double mx = nodes_fi[0].x + nodes_se[0].x;
		
		bool flag = true;
		for (int i = 0; i < N; i++)
		{
			double tm = nodes_fi[i].x + nodes_se[i].x;
			if (mx != tm || nodes_fi[i].y != nodes_se[i].y)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}//while
	return 0;
}
