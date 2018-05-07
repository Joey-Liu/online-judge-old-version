#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 1e5 + 20;
int N, M;
int lef[maxn], rig[maxn];

void link(int x, int y)
{
	rig[x] = y;
	lef[y] = x;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (2 == scanf("%d%d", &N, &M))
	{
		memset(lef, 0, sizeof(lef));
		memset(rig, 0, sizeof(rig));

		for (int i = 1; i <= N; i++)
		{
			lef[i] = i - 1;
			rig[i] = (i + 1) % (N + 1);
		}
		rig[0] = 1;
		lef[0] = N;
		
		bool inv = false;
		int op, x, y;

		for (int i = 0; i < M; i++)
		{
			scanf("%d", &op);
			if (4 == op)
				inv = !inv;
			else
			{
				if (inv && 3 != op)
					op = 3 - op;
				scanf("%d%d", &x, &y);
				if (3 == op && lef[y] == x)
					swap(x, y);

				int xl = lef[x], xr = rig[x];
				int yl = lef[y], yr = rig[y];
				if (1 == op && rig[x] == y)
					continue;
				if (2 == op && lef[x] == y)
					continue;

				if (1 == op)
				{
					link(xl, xr);
					link(yl, x);
					link(x, y);
				}
				else if (2 == op)
				{
					link(xl, xr);
					link(y, x);
					link(x, yr);
				}
				else
				{
					if (rig[y] == x)
					{
						link(yl, x);
						link(x, y);
						link(y, xr);
					}
					else
					{
						link(xl, y);
						link(y, xr);
						link(yl, x);
						link(x, yr);
					}
				}//else
			}//else

		}//for int i
		int cur = 0;
		long long int res = 0;
		bool flag = true;
		for (int i = 1; i <= N; i++)
		{
			if (!inv)
				cur = rig[cur];
			else
				cur = lef[cur];

			if (flag)
				res += cur;
			flag = !flag;
		}
		printf("Case %d: %lld\n", ++kasenum, res);
	}//while scanf()
	return 0;
}