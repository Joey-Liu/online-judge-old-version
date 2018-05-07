#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int maxn = 20 + 20;

int numbers[maxn], leftp[maxn], rightp[maxn];
int N, k, m;

void link(int x, int y)
{
	rightp[x] = y;
	leftp[y] = x;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d%d%d", &N, &k, &m);
	while (N || k || m)
	{
		for (int i = 1; i <= N; i++)
		{
			numbers[i] = N - i + 1;
			leftp[i] = i - 1;
			rightp[i] = i + 1;
		}
		leftp[1] = N;
		rightp[N] = 1;

		int st = 1, ent = N, numCnt = N;
		while (numCnt > 0)
		{
			for (int i = 1; i < m; i++)
				st = rightp[st];
			for (int i = 1; i < k; i++)
				ent = leftp[ent];

			link(leftp[ent], rightp[ent]);
			numCnt--;

			printf("%3d", numbers[ent]);
			int temp = ent;
			ent = leftp[ent];

			if (st != temp)
			{
				link(leftp[st], rightp[st]);
				printf("%3d", numbers[st]);
				if (ent == st)
					ent = leftp[ent];
				st = rightp[st];
				numCnt--;
			}
			else
				st = rightp[st];
			
			if (numCnt)
				printf(",");
		}//while numCnt
		printf("\n");
		scanf("%d%d%d", &N, &k, &m);
	}//while

	return 0;
}