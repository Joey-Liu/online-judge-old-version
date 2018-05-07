#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;
queue<int> que;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	bool first = true;
	while (1 == scanf("%d", &n) && n)
	{
		if (!first)
			printf("\n");
		while (!que.empty())
			que.pop();
		for (int i = 1; i <= n; i++)
			que.push(i);
		printf("Discarded cards: ");
		while (que.size() > 1)
		{
			printf("%d", que.front());
			que.pop();
			if (que.size() > 1)
			{
				printf(", ");
				que.push(que.front());
				que.pop();
			}
		}
		printf("\nRemaining card: %d", que.front());
		first = false;
	}
	return 0;
}