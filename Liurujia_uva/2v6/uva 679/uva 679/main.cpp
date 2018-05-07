#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;
const int maxn = (1 << 20) + 10;
bool node[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		int D, I;
		scanf("%d%d", &D, &I);

		memset(node, false, sizeof(node));
		int ind = 1;
		for (int i = 0; i < I; i++)
		{
			ind = 1;
			while (ind <= (1 << D) - 1)
			{
				node[ind] = !node[ind];
				if (node[ind])
					ind = (ind << 1);
				else
					ind = (ind << 1) + 1;
			}
		}
		printf("%d\n", (ind >> 1));
	}//while
	return 0;
}