#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>

using namespace std;
int n, abcd, fghi;
int visited[10];

bool check()
{
	if (abcd >= 1e+5)
		return false;
	if (fghi < 1e+4)
		visited[0]++;
	if (abcd < 1e+4)
		visited[0]++;

	int ab = abcd, fg = fghi;
	while (ab > 0)
	{
		int te = ab % 10;
		visited[te]++;
		ab /= 10;
	}
	while (fg > 0)
	{
		int te = fg % 10;
		visited[te]++;
		fg /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i] != 1)
			return false;
	}
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	bool fir = true;
	while (cin >> n && n)
	{
		if (!fir)
			printf("\n");
		fir = false;

		bool flag = false;
		for (int i = 1234; i < 99999; i++)
		{
			memset(visited, 0, sizeof(visited));
			fghi = i;
			abcd = fghi * n;
			if (check())
			{
				printf("%05d / %05d = %d\n", abcd, fghi, n);
				flag = true;
			}
		}
		if (!flag)
			printf("There are no solutions for %d.\n", n);
	}//while
	return 0;
}