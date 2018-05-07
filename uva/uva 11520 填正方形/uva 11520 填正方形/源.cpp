#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int maxn = 10 + 5;
char grid[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum = 0;
	scanf("%d", &casenum);
	for (int kase = 1; kase <= casenum;kase++)
	{
		int length = 0;
		scanf("%d", &length);
		for (int i = 0; i < length; i++)
			scanf("%s", grid[i]);

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if ('.' == grid[i][j])
				{
					for (char c = 'A'; c <= 'Z'; c++)
					{
						if (i - 1 >= 0 && grid[i - 1][j] == c)
							continue;
						if (i + 1 < length && grid[i + 1][j] == c)
							continue;
						if (j - 1 >= 0 && grid[i][j - 1] == c)
							continue;
						if (j + 1 < length && grid[i][j + 1] == c)
							continue;
						grid[i][j] = c;
						break;
					}
				}
			}//for int j
		}//for int i

		printf("Case %d:\n", kase);
		for (int i = 0; i < length; i++)
			printf("%s\n", grid[i]);

	}//for kase
	return 0;
}