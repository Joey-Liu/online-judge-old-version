#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

const int maxn = 10 + 5;
char map[maxn][maxn];
char tou[maxn][maxn];
char ans[maxn][maxn];

int size = 0;
char mark = '.';

bool touchMine()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ('*' == map[i][j] && 'x' == tou[i][j])
				return true;
		}
	}

	return false;
}

bool isLegal(int r, int c)
{
	if (r < 0 || c < 0 || r >= size || c >= size)
		return false;
	return true;
}

int getNum(int r, int c)
{
	int res = 0;
	int row = r - 1;
	int col = c - 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (isLegal(row + i, col + j) && map[row + i][col + j] == '*')
			{
				res++;
			}
		}
	}//for int i

	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int flag = false;
	while (EOF != scanf("%d", &size))
	{
		if (flag)
			printf("\n\n");
		memset(ans, sizeof(ans), 0);
		getchar();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				scanf("%c", &map[i][j]);
			}
			getchar();
		}//for int i

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				scanf("%c", &tou[i][j]);
			}
			getchar();
		}//for int i


		if (touchMine())
		{
			mark = '*';
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (map[i][j] == '*')
						ans[i][j] = '*';
				}
			}
		}
		else
			mark = '.';

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (tou[i][j] == 'x' && map[i][j] == '.')
					ans[i][j] = getNum(i, j) + '0';
				if (tou[i][j] == 'x' && map[i][j] == '*')
					continue;
				if (tou[i][j] == '.' && map[i][j] == '*')
					ans[i][j] = mark;
				if (tou[i][j] == '.' && map[i][j] == '.')
					ans[i][j] = '.';
			}
		}//for int i

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				printf("%c", ans[i][j]);
			if (i != size - 1)
				printf("\n");
		}
		flag = true;
	}//while

	return 0;
}