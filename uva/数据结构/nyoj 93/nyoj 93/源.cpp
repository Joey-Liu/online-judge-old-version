#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int N, p, q;
int a, b, tmp;
stack<int> hano[4];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &N);
	while (N--)
	{
		scanf("%d%d", &p, &q);
		for (int i = 1; i <= 3; i++)
		{
			while (!hano[i].empty())
				hano[i].pop();
		}
		for (int i = p; i >= 1; i--)
			hano[1].push(i);

		bool flag = true;
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &a, &b);
			if (!flag)
				continue;
			if (hano[a].empty())
			{
				flag = false;
				continue;
			}
			if (!hano[b].empty() && hano[a].top() >= hano[b].top())
			{
				flag = false;
				continue;
			}

			tmp = hano[a].top();
			hano[a].pop();
			hano[b].push(tmp);
		}
		printf("%s\n", flag ? "legal" : "illegal");
	}

	return 0;
}