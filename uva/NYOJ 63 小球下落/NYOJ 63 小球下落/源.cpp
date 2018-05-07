#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 1 << 21;
bool node[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int dep, num;
	while (scanf("%d%d", &dep, &num))
	{
		if (!dep && !num)
			break;
		memset(node, false, sizeof(node));
		int cur = 1, level = 1;
		for (int i = 0; i < num; i++)
		{
			cur = 1; level = 1;
			while (level < dep)
			{
				node[cur] = !node[cur];
				if (node[cur])
					cur *= 2;
				else
					cur = 2 * cur + 1;
				level++;
			}//while
		}//for num
		printf("%d\n", cur);
	}//scanf
	return 0;
}