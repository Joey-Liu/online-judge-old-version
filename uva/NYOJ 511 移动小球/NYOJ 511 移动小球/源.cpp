#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 10000 + 100;
int rig[maxn];
int lef[maxn];
int N, a, b;
char c;

void link(int x, int y)
{
	rig[x] = y;
	lef[y] = x;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum,ordernum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d %d", &N, &ordernum);
		for (int i = 1; i <= N; i++)
		{
			lef[i] = i - 1;
			rig[i] = i + 1;
		}
		rig[N] = 1;
		lef[1] = N;

		for (int i = 0; i < ordernum; i++)
		{
			getchar();
			scanf("%c %d %d", &c, &a, &b);
			//link(lef[a], rig[a]);
			rig[lef[a]] = rig[a];
			lef[rig[a]] = lef[a];
			if ('A' == c)
			{
				rig[a] = b;
				lef[a] = lef[b];
				lef[rig[a]] = a;
				rig[lef[a]] = a;
			}
			else if ('B' == c)
			{
				lef[a] = b;
				rig[a] = rig[b];
				lef[rig[a]] = a;
				rig[lef[a]] = a;
			}
			else
			{
				if (a == 1)
					printf("%d\n", rig[b]);
				else
					printf("%d\n", lef[b]);
			}
		}//for ordernum
	}//while casenum
	return 0;
}